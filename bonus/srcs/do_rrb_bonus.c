/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:32 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:32 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_rrb(t_elem **stack_b)
{
	t_elem	*last;
	t_elem	*temp;

	if (!stack_b || !*stack_b)
		return (false);
	temp = *stack_b;
	last = ft_lastelem(*stack_b);
	last->next = temp;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack_b = last;
	last->next->prev = last;
	last = ft_lastelem(*stack_b);
	last->next = NULL;
	return (true);
}
