/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 10:41:22 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:44:11 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_pa(t_elem **sa, t_elem **sb)
{
	t_elem	*head;

	head = *sa;
	*sa = *sb;
	*sb = (*sb)->next;
	(*sa)->next = head;
	(*sa)->prev = NULL;
	(*sb)->prev = NULL;
	ft_printf("pa\n");
	return (true);
}
