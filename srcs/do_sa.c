/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:40:45 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:47:21 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_sa(t_elem **stack, t_bool print)
{
	t_elem	*temp;

	temp = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	temp->prev = (*stack);
	if (print)
		ft_printf("sa\n");
	return (true);
}
