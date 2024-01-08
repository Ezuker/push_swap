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

t_bool	is_sorted(t_elem *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	sort_three(t_elem	**stack)
{
	while (!is_sorted(*stack))
	{
		if (ft_lastelem(*stack)->number == get_max_stack(*stack)->number)
			do_sa(stack, 1);
		else if ((*stack)->number == get_max_stack(*stack)->number
			&& ft_lastelem(*stack)->number == get_min_stack(*stack)->number)
		{
			do_sa(stack, 1);
			do_rra(stack, 1);
		}
		else if ((*stack)->number == get_max_stack(*stack)->number
			&& ft_lastelem(*stack)->number != get_min_stack(*stack)->number)
			do_ra(stack, 1);
		else if ((*stack)->number == get_min_stack(*stack)->number)
		{
			do_rra(stack, 1);
			do_sa(stack, 1);
		}
		else
			do_rra(stack, 1);
	}
}

void	push_two(t_elem	**sa, t_elem	**sb)
{
	if (stack_length(*sa) == 4)
		do_pb(sa, sb);
	else
	{
		do_pb(sa, sb);
		do_pb(sa, sb);
	}
}

void	set_target_a(t_elem *sa, t_elem *sb)
{
	float	delta;
	t_elem	*save;
	t_elem	*save_b;

	delta = 2147483648.0;
	save_b = sb;
	while (sa)
	{
		while (sb)
		{
			if (sa->number > sb->number && delta > sa->number - sb->number)
			{
				delta = sa->number - sb->number;
				save = sb;
			}
			sb = sb->next;
		}
		sb = save_b;
		if (delta == 2147483648.0)
			sa->target = get_max_stack(sb);
		else
			sa->target = save;
		delta = 2147483648.0;
		save = NULL;
		sa = sa->next;
	}
}

void	set_target_b(t_elem *sa, t_elem *sb)
{
	float	delta;
	t_elem	*save;
	t_elem	*save_a;

	delta = 2147483648.0;
	save_a = sa;
	while (sb)
	{
		while (sa)
		{
			if (sb->number < sa->number && delta > sb->number - sa->number)
			{
				delta = sb->number - sa->number;
				save = sa;
			}
			sa = sa->next;
		}
		sa = save_a;
		if (delta == 2147483648.0)
			sb->target = get_min_stack(sa);
		else
			sb->target = save;
		delta = 2147483648.0;
		save = NULL;
		sb = sb->next;
	}
}

t_elem	*cost_analysis(t_elem *sa, t_elem *sb)
{
	int		total;
	int		save;
	t_elem	*save_id;
	int		length;

	save = 2147483647;
	length = stack_length(sa);
	while (sa)
	{
		if (sa->index > length / 2)
			total = length - sa->index;
		else
			total = sa->index;
		if (sa->target->index > stack_length(sb) / 2)
			total += stack_length(sb) - sa->target->index;
		else
			total += sa->target->index;
		if (save > total)
		{
			save = total;
			save_id = sa;
		}
		sa = sa->next;
	}
	return (save_id);
}

void	do_action(t_elem *id, t_elem **sa, t_elem **sb)
{
	int	i;
	int	it;

	it = -1;
	if (id->index > stack_length(*sa) / 2)
	{
		i = stack_length(*sa) - id->index;
		while (++it < i)
			do_rra(sa, 1);
	}
	else
		while (++it < id->index)
			do_ra(sa, 1);
	it = -1;
	if (id->target->index > stack_length(*sb) / 2)
	{
		i = stack_length(*sb) - id->target->index;
		while (++it < i)
			do_rrb(sb, 1);
	}
	else
		while (++it < id->target->index)
			do_rb(sb, 1);
}

void	mechanical_turk(t_elem	**sa, t_elem	**sb)
{
	t_elem	*save_id;

	push_two(sa, sb);
	while (stack_length(*sa) > 3)
	{
		set_target_a(*sa, *sb);
		add_index(*sa);
		add_index(*sb);
		save_id = cost_analysis(*sa, *sb);
		do_action(save_id, sa, sb);
		do_pb(sa, sb);
	}
	sort_three(sa);
	while (stack_length(*sb) != 0)
	{
		set_target_b(*sa, *sb);
		add_index(*sa);
		add_index(*sb);
		save_id = cost_analysis(*sb, *sa);
		do_action(save_id, sa, sb);
		do_pa(sa, sb);
		print_stack(*sa, *sb);
	}
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

