/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:41 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:41 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_sa(t_elem **stack)
{
	t_elem	*first;
	t_elem	*second;
	t_elem	*third;

	if (!stack || !*stack || stack_length(*stack) < 2)
		return (false);
	first = *stack;
	second = (*stack)->next;
	third = NULL;
	if ((*stack)->next->next)
		third = (*stack)->next->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (third)
		third->prev = first;
	*stack = second;
	return (true);
}
