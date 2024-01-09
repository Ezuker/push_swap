/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:37:18 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/09 17:37:48 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

float	get_bigger_delta(int sa_number, int sb_number)
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

float	get_lower_delta(int sa_number, int sb_number)
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

t_elem	*get_save_a(float *delta, t_elem *sa, t_elem *sb, t_elem *save)
{
	float	new_delta;

	if (!sa || !sb)
		return (NULL);
	new_delta = get_lower_delta(sa->number, sb->number);
	if (sa->number > sb->number && *delta > new_delta)
	{
		save = sb;
		*delta = new_delta;
	}
	return (save);
}

t_elem	*get_save_b(float *delta, t_elem *sa, t_elem *sb, t_elem *save)
{
	float	new_delta;

	if (!sa || !sb)
		return (NULL);
	new_delta = get_bigger_delta(sa->number, sb->number);
	if (sb->number < sa->number && *delta > new_delta)
	{
		save = sa;
		*delta = new_delta;
	}
	return (save);
}
