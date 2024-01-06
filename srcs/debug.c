/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:31:53 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/06 15:32:09 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_elem	*stack_a, t_elem *stack_b)
{
	ft_printf("A  B\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			ft_printf("%d  ", stack_a->number);
			stack_a = stack_a->next;
		}
		else
			ft_printf("    ");
		if (stack_b)
		{
			ft_printf("%d", stack_b->number);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

void	print_data(t_elem *stack_a)
{
	while (stack_a != NULL)
	{
		ft_printf("content = %d\n", stack_a->number);
		ft_printf("actual = %p\n", stack_a);
		ft_printf("prev = %p\n", stack_a->prev);
		ft_printf("next = %p\n\n", stack_a->next);
		stack_a = stack_a->next;
	}
}
