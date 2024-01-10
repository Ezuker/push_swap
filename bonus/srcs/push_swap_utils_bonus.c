/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:17:01 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:17:01 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

int	stack_length(t_elem	*stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_elem	*get_min_stack(t_elem *stack)
{
	int		save;
	t_elem	*addr;

	save = 2147483647;
	while (stack)
	{
		if (save > stack->number)
		{
			save = stack->number;
			addr = stack;
		}
		stack = stack->next;
	}
	return (addr);
}

t_elem	*get_max_stack(t_elem *stack)
{
	int		save;
	t_elem	*addr;

	save = -2147483648;
	while (stack)
	{
		if (save < stack->number)
		{
			save = stack->number;
			addr = stack;
		}
		stack = stack->next;
	}
	return (addr);
}
