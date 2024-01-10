/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:45 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:45 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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
