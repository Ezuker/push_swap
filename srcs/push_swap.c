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

void	mechanical_turk(t_elem	**stack)
{

}

int	main(int argc, char **argv)
{
	t_elem	*sa;

	sa = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
		return (0);
	if (stack_length(sa) == 3)
		sort_three(&sa);
}

