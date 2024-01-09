/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:51:11 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/09 00:51:11 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_sort(t_elem	**sa)
{
	t_elem	*min;
	int		cost;
	int		i;

	i = -1;
	min = get_min_stack(*sa);
	cost = 0;
	if (min->index > stack_length(*sa) / 2)
	{
		cost = stack_length(*sa) - min->index;
		while (++i < cost)
			do_rra(sa, 1);
	}
	else
	{
		cost = min->index;
		while (++i < cost)
			do_ra(sa, 1);
	}
}

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