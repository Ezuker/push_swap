/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:13:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:29:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rra(t_elem **stack_a)
{
	t_elem	*last;
	t_elem	*temp;

	temp = *stack_a;
	last = ft_lastelem(*stack_a);
	last->next = temp;
	*stack_a = last;
	(*stack_a)->prev = NULL;
	last = ft_lastelem(*stack_a);
	last->next = NULL;
	return (true);
}
