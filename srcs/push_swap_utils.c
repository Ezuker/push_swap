/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:02:32 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:07:03 by bcarolle         ###   ########.fr       */
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

t_elem	*ft_lastelem(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
