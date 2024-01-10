/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:06 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:06 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	create_stack(t_elem **sa, t_elem **sb)
{
	*sb = *sa;
	*sa = (*sa)->next;
	(*sb)->next = NULL;
	(*sb)->prev = NULL;
	(*sa)->prev = NULL;
}

t_bool	do_pb(t_elem **sa, t_elem **sb)
{
	t_elem	*former_head;
	t_elem	*last;

	if (!sb || !*sb)
		create_stack(sa, sb);
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
