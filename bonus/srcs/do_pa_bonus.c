/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:15:57 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:15:57 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

static void	create_stack(t_elem **sa, t_elem **sb)
{
	*sa = *sb;
	*sb = (*sb)->next;
	(*sa)->next = NULL;
	(*sa)->prev = NULL;
	(*sb)->prev = NULL;
}

t_bool	do_pa(t_elem **sa, t_elem **sb)
{
	t_elem	*former_head;
	t_elem	*last;

	if (!sb || !*sb)
		return (false);
	if (!sa || !*sa)
		create_stack(sa, sb);
	else
	{
		last = ft_lastelem(*sa);
		former_head = *sa;
		*sa = *sb;
		*sb = (*sb)->next;
		(*sa)->next = former_head;
		(*sa)->next->prev = (*sa);
		(*sa)->prev = NULL;
		if (*sb)
			(*sb)->prev = NULL;
		last->next = NULL;
	}
	return (true);
}
