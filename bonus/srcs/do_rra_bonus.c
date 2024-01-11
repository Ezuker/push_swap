/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:27 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:27 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_rra(t_elem **stack_a)
{
	t_elem	*last;
	t_elem	*tmp;

	if (!stack_a || !*stack_a || stack_length(*stack_a) < 2)
		return (false);
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
	return (true);
}
