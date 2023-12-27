/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:50:23 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 11:50:59 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rrb(t_elem **stack_b)
{
	t_elem	*last;
	t_elem	*temp;

	temp = *stack_b;
	last = ft_lastelem(*stack_b);
	last->next = temp;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack_b = last;
	(*stack_b)->prev = NULL;
	last = ft_lastelem(*stack_b);
	last->next = NULL;
	return (true);
}
