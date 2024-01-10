/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:31:53 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:26:31 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
		ft_printf("next = %p\n", stack_a->next);
		ft_printf("index = %d\n", stack_a->index);
		ft_printf("target b = %p ", stack_a->target);
		if (stack_a->target)
			ft_printf("%d", stack_a->target->number);
		ft_printf("\n\n");
		stack_a = stack_a->next;
	}
}
