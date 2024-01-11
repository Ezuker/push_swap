/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:13 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:13 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_ra(t_elem **sa)
{
	t_elem	*temp;
	t_elem	*last;

	if (!sa || !*sa || stack_length(*sa) < 2)
		return (false);
	temp = *sa;
	last = ft_lastelem(*sa);
	*sa = (*sa)->next;
	(*sa)->prev = NULL;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	return (true);
}
