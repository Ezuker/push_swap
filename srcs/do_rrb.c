/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:50:23 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:58:53 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rrb(t_elem **stack_b, t_bool print)
{
	t_elem	*last;
	t_elem	*temp;

	temp = *stack_b;
	last = ft_lastelem(*stack_b);
	last->next = temp;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack_b = last;
	last->next->prev = last;
	last = ft_lastelem(*stack_b);
	last->next = NULL;
	if (print)
		ft_printf("rrb\n");
	return (true);
}
