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
		if (sa->index >= math_round(length / 2.0)
			&& sa->target->index >= math_round(stack_length(sb) / 2.0))
			total = get_total_above_median(length, sa, sb);
		else if (sa->index < math_round(length / 2.0)
			&& sa->target->index < math_round(stack_length(sb) / 2.0))
			total = get_total_below_median(sa);
		else
			total = get_total_other(length, sa, sb);
		if (save > total)
		{
			save = total;
			save_id = sa;
		}
		sa = sa->next;
	}
	return (save_id);
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

void	ft_elem_clear(t_elem **sa)
{
	t_elem	*tmp;

	while (*sa)
	{
		tmp = *sa;
		(*sa) = (*sa)->next;
		free(tmp);
	}
}

void	sorting(t_elem **sa, t_elem **sb)
{
	if (stack_length(*sa) == 2 && !is_sorted(*sa))
		do_sa(sa, 1);
	else if (stack_length(*sa) == 3)
		sort_three(sa);
	else if (stack_length(*sa) == 4)
		sort_four(sa, sb);
	else
		mechanical_turk(sa, sb);
}

int	main(int argc, char **argv)
{
	t_elem	*sa;
	t_elem	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
	{
		ft_elem_clear(&sa);
		write(2, "Error\n", 6);
		return (0);
	}
	add_index(sa);
	if (repeated_number(sa))
	{
		ft_elem_clear(&sa);
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(sa))
	{
		ft_elem_clear(&sa);
		return (0);
	}
	sorting(&sa, &sb);
	ft_elem_clear(&sa);
	return (0);
}
