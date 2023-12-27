/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 16:21:19 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_ra(t_elem **sa, t_bool print)
{
	t_elem	*temp;
	t_elem	*last;

	temp = *sa;
	last = ft_lastelem(*sa);
	*sa = (*sa)->next;
	(*sa)->prev = NULL;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	if (print == true)
		ft_printf("ra\n");
	return (true);
}
