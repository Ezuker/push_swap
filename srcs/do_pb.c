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

#include "../includes/push_swap.h"

t_bool	do_pb(t_elem **sa, t_elem **sb)
{
	t_elem	*former_head;
	t_elem	*last;

	if (!sb || !*sb)
	{
		*sb = *sa;
		*sa = (*sa)->next;
		(*sb)->next = NULL;
		(*sb)->prev = NULL;
		(*sa)->prev = NULL;
	}
	else
	{
		last = ft_lastelem(*sb);
		former_head = *sb;
		*sb = *sa;
		*sa = (*sa)->next;
		(*sb)->next = former_head;
		(*sb)->next->prev = (*sb);
		(*sb)->prev = NULL;
		if (*sa)
			(*sa)->prev = NULL;
		last->next = NULL;
	}
	ft_printf("pb\n");
	return (true);
}
