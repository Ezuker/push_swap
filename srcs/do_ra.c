/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:06:58 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_ra(t_elem **sa)
{
	t_elem	*temp;
	t_elem	*last;

	temp = *sa;
	last = ft_lastelem(*sa);
	*sa = (*sa)->next;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	return (true);
}
