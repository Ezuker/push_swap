/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:16:08 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:10:41 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rb(t_elem **sb)
{
	t_elem	*temp;
	t_elem	*last;

	temp = *sb;
	last = ft_lastelem(*sb);
	*sb = (*sb)->next;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	return (true);
}
