/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:18 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:18 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_rb(t_elem **sb)
{
	t_elem	*temp;
	t_elem	*last;

	if (!sb || !*sb || stack_length(*sb) < 2)
		return (false);
	temp = *sb;
	last = ft_lastelem(*sb);
	*sb = (*sb)->next;
	(*sb)->prev = NULL;
	last->next = temp;
	last->next->next = NULL;
	last->next->prev = last;
	return (true);
}
