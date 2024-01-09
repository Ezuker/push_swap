/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:56:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 16:22:53 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		math_round(float nb)
{
	nb += 0.5;
	return ((int)(nb));
}

t_elem	*cost_analysis(t_elem *sa, t_elem *sb)
{
	int		total;
	int		save;
	t_elem	*save_id;
	int		length;

	save = 2147483647;
	length = (stack_length(sa));
	while (sa)
	{
		if (sa->index >= math_round(length / 2.0) && sa->target->index >= math_round(stack_length(sb) / 2.0))
		{
			if (length - sa->index > stack_length(sb) - sa->target->index)
				total = length - sa->index;
			else
				total = stack_length(sb) - sa->target->index;
		}
		else if (sa->index < math_round(length / 2.0) && sa->target->index < math_round(stack_length(sb) / 2.0))
		{
			if (sa->index > sa->target->index)
				total = sa->index;
			else
				total = sa->target->index;
		}
		else
		{
			if (sa->index >= math_round(length / 2.0))
				total = length - sa->index;
			else
				total = sa->index;
			if (sa->target->index >= math_round(stack_length(sb) / 2.0))
				total += stack_length(sb) - sa->target->index;
			else
				total += sa->target->index;
		}
		if (save > total)
		{
			save = total;
			save_id = sa;
		}
		sa = sa->next;
	}
	return (save_id);
}

void	do_action_a(t_elem *id, t_elem **sa, t_elem **sb)
{
	int	i;
	int	j;
	int	it;

	it = -1;
	if (id->index >= math_round(stack_length(*sa) / 2.0) && id->target->index >= math_round(stack_length(*sb) / 2.0))
	{
		i = stack_length(*sa) - id->index;
		j = stack_length(*sb) - id->target->index;
		while (i > 0 && j > 0)
		{
			do_rrr(sb, sa);
			i--;
			j--;
		}
		while (i-- > 0)
			do_rra(sa, 1);
		while (j-- > 0)
			do_rrb(sb, 1);
	}
	else if (id->index < math_round(stack_length(*sa) / 2.0) && id->target->index < math_round(stack_length(*sb) / 2.0))
	{
		i = id->index;
		j = id->target->index;
		while (i > 0 && j > 0)
		{
			do_rr(sb, sa);
			i--;
			j--;
		}
		while (i-- > 0)
			do_ra(sa, 1);
		while (j-- > 0)
			do_rb(sb, 1);
	}
	else
	{
		if (id->index >= math_round(stack_length(*sa) / 2.0))
		{
			i = stack_length(*sa) - id->index;
			while (++it < i)
				do_rra(sa, 1);
		}
		else
			while (++it < id->index)
				do_ra(sa, 1);
		it = -1;
		if (id->target->index >= math_round(stack_length(*sb) / 2.0))
		{
			i = stack_length(*sb) - id->target->index;
			while (++it < i)
				do_rrb(sb, 1);
		}
		else
			while (++it < id->target->index)
				do_rb(sb, 1);
	}
}

void	do_action_b(t_elem *id, t_elem **sb, t_elem **sa)
{
	int	i;
	int	j;
	int	it;

	it = -1;
	if (id->index >= math_round(stack_length(*sb) / 2.0) && id->target->index >= math_round(stack_length(*sa) / 2.0))
	{
		i = stack_length(*sb) - id->index;
		j = stack_length(*sa) - id->target->index;
		while (i > 0 && j > 0)
		{
			do_rrr(sa, sb);
			i--;
			j--;
		}
		while (i-- > 0)
			do_rrb(sb, 1);
		while (j-- > 0)
			do_rra(sa, 1);
	}
	else if (id->index < math_round(stack_length(*sb) / 2.0) && id->target->index < math_round(stack_length(*sa) / 2.0))
	{
		i = id->index;
		j = id->target->index;
		while (i > 0 && j > 0)
		{
			do_rr(sa, sb);
			i--;
			j--;
		}
		while (i-- > 0)
			do_rb(sb, 1);
		while (j-- > 0)
			do_ra(sa, 1);
	}
	else
	{
		if (id->index >= math_round(stack_length(*sb) / 2.0))
		{
			i = stack_length(*sb) - id->index;
			while (++it < i)
				do_rrb(sb, 1);
		}
		else
			while (++it < id->index)
				do_rb(sb, 1);
		it = -1;
		if (id->target->index >= math_round(stack_length(*sa) / 2.0))
		{
			i = stack_length(*sa) - id->target->index;
			while (++it < i)
				do_rra(sa, 1);
		}
		else
			while (++it < id->target->index)
				do_ra(sa, 1);
	}
}

void	mechanical_turk(t_elem	**sa, t_elem	**sb)
{
	t_elem	*save_id;

	push_two(sa, sb);
	while (stack_length(*sa) > 3)
	{
		add_index(*sa);
		add_index(*sb);
		set_target_a(*sa, *sb);
		save_id = cost_analysis(*sa, *sb);
		do_action_a(save_id, sa, sb);
		do_pb(sa, sb);
	}
	sort_three(sa);
	while (stack_length(*sb) != 0)
	{
		add_index(*sa);
		add_index(*sb);
		set_target_b(*sa, *sb);
		save_id = cost_analysis(*sb, *sa);
		do_action_b(save_id, sb, sa);
		do_pa(sa, sb);
	}
	add_index(*sa);
	final_sort(sa);
}

int	main(int argc, char **argv)
{
	t_elem	*sa;
	t_elem	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
		return (0);
	if (stack_length(sa) == 2 && !is_sorted(sa))
	{
		do_sa(&sa, 1);
		return (0);
	}
	else if (stack_length(sa) == 3)
	{
		sort_three(&sa);
		return (0);
	}
	else
		mechanical_turk(&sa, &sb);
	return (0);
}

