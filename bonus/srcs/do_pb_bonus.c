/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:44:40 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:44:21 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_bool	do_pb(t_elem **sa, t_elem **sb)
{
	t_elem	*head;

	head = *sb;
	*sb = *sa;
	*sa = (*sa)->next;
	(*sb)->next = head;
	(*sb)->prev = NULL;
	(*sa)->prev = NULL;
	ft_printf("pb\n");
	return (true);
}
