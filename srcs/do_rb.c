/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 16:22:09 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rb(t_elem **sb, t_bool print)
{
	t_elem	*temp;
	t_elem	*last;

	temp = *sb;
	last = ft_lastelem(*sb);
	*sb = (*sb)->next;
	(*sb)->prev = NULL;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	if (print == true)
		ft_printf("rb\n");
	return (true);
}
