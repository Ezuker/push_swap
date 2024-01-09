/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:43:28 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/09 19:27:43 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	action_above_median(t_elem *id, t_elem **sa, t_elem **sb)
{
	int	i;
	int	j;

	i = stack_length(*sb) - id->index;
	j = stack_length(*sa) - id->target->index;
	while (i > 0 && j > 0)
	{
		do_rrr(sa, sb);
		i--;
		j--;
	}
	while (i-- > 0)
		do_rrb(sb, 1);
	while (j-- > 0)
		do_rra(sa, 1);
}

static void	action_below_median(t_elem *id, t_elem **sa, t_elem **sb)
{
	int	i;
	int	j;

	i = id->index;
	j = id->target->index;
	while (i > 0 && j > 0)
	{
		do_rr(sa, sb);
		i--;
		j--;
	}
	while (i-- > 0)
		do_rb(sb, 1);
	while (j-- > 0)
		do_ra(sa, 1);
}

static void	action_other(t_elem *id, t_elem **sa, t_elem **sb)
{
	int	i;
	int	it;

	it = -1;
	if (id->index >= math_round(stack_length(*sb) / 2.0))
	{
		i = stack_length(*sb) - id->index;
		while (++it < i)
			do_rrb(sb, 1);
	}
	else
		while (++it < id->index)
			do_rb(sb, 1);
	it = -1;
	if (id->target->index >= math_round(stack_length(*sa) / 2.0))
	{
		i = stack_length(*sa) - id->target->index;
		while (++it < i)
			do_rra(sa, 1);
	}
	else
		while (++it < id->target->index)
			do_ra(sa, 1);
}

void	do_action_b(t_elem *id, t_elem **sb, t_elem **sa)
{
	if (id->index >= math_round(stack_length(*sb) / 2.0)
		&& id->target->index >= math_round(stack_length(*sa) / 2.0))
		action_above_median(id, sa, sb);
	else if (id->index < math_round(stack_length(*sb) / 2.0)
		&& id->target->index < math_round(stack_length(*sa) / 2.0))
		action_below_median(id, sa, sb);
	else
		action_other(id, sa, sb);
}
