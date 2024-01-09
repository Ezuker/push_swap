/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:40:45 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:47:01 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_sb(t_elem **stack, t_bool print)
{
	t_elem	*temp;

	temp = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->next = temp;
	if (print)
		ft_printf("sb\n");
	return (true);
}
