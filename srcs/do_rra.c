/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:13:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:57:43 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rra(t_elem **stack_a, t_bool print)
{
	t_elem	*last;
	t_elem	*tmp;

	last = ft_lastelem(*stack_a);
	if (stack_length(*stack_a) == 1)
		return (true);
	if (last->prev)
		last->prev->next = NULL;
	tmp = (*stack_a);
	(*stack_a)->prev = last;
	(*stack_a) = (*stack_a)->prev;
	last->next = tmp;
	last->prev = NULL;
	if (print)
		ft_printf("rra\n");
	return (true);
}
