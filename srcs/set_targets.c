/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:49:32 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/09 00:49:32 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target_a(t_elem *sa, t_elem *sb)
{
	float	delta;
	t_elem	*save;
	t_elem	*save_b;

	delta = 2147483648.0;
	save_b = sb;
	while (sa)
	{
		save = NULL;
		while (sb)
		{
			save = get_save_a(&delta, sa, sb, save);
			sb = sb->next;
		}
		sb = save_b;
		if (delta == 2147483648.0)
			sa->target = get_max_stack(sb);
		else
			sa->target = save;
		delta = 2147483648.0;
		sa = sa->next;
	}
}

void	set_target_b(t_elem *sa, t_elem *sb)
{
	float	delta;
	t_elem	*save;
	t_elem	*save_a;

	delta = 2147483648.0;
	save_a = sa;
	while (sb)
	{
		save = NULL;
		while (sa)
		{
			save = get_save_b(&delta, sa, sb, save);
			sa = sa->next;
		}
		sa = save_a;
		if (!save)
			sb->target = get_min_stack(sa);
		else
			sb->target = save;
		delta = 2147483648.0;
		sb = sb->next;
	}
}
