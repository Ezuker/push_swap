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

static float	get_bigger_delta(int sa_number, int sb_number)
{
	float	delta;

	if (sa_number > sb_number)
	{
		delta = sb_number - sa_number;
		delta = ft_abs(delta);
		return (delta);
	}
	else
		return (2147483648.0);
}

static float	get_lower_delta(int sa_number, int sb_number)
{
	float	delta;

	if (sa_number > sb_number)
	{
		delta = sa_number - sb_number;
		delta = ft_abs(delta);
		return (delta);
	}
	else
		return (2147483648.0);
}

void	set_target_a(t_elem *sa, t_elem *sb)
{
	float	new_delta;
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
			new_delta = get_lower_delta(sa->number, sb->number);
			if (sa->number > sb->number && delta > new_delta)
			{
				save = sb;
				delta = new_delta;
			}
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
	float	new_delta;
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
			new_delta = get_bigger_delta(sa->number, sb->number);
			if (sb->number < sa->number && delta > new_delta)
			{
				save = sa;
				delta = new_delta;
			}
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