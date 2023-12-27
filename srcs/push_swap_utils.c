/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:02:32 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 16:21:56 by bcarolle         ###   ########.fr       */
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

t_elem	*ft_lastelem(t_elem *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_bool	ft_addback(t_elem **lst, t_elem *node)
{
	t_elem	*last;

	if (!lst || !(*lst))
	{
		(*lst) = node;
		return (true);
	}
	last = ft_lastelem(*lst);
	last->next = node;
	last->next->next = NULL;
	last->next->prev = last;
	return (true);
}

t_elem	*ft_str_to_elem(char *str)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	node->number = ft_atoi(str);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
