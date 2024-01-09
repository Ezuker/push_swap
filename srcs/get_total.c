/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_total.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:02:58 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/09 18:03:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_total_above_median(int length_a, t_elem *sa, t_elem *sb)
{
	int	total;

	if (length_a - sa->index > stack_length(sb) - sa->target->index)
		total = length_a - sa->index;
	else
		total = stack_length(sb) - sa->target->index;
	return (total);
}

int	get_total_below_median(t_elem *sa)
{
	int	total;

	if (sa->index > sa->target->index)
		total = sa->index;
	else
		total = sa->target->index;
	return (total);
}

int	get_total_other(int length_a, t_elem *sa, t_elem *sb)
{
	int	total;

	if (sa->index >= math_round(length_a / 2.0))
		total = length_a - sa->index;
	else
		total = sa->index;
	if (sa->target->index >= math_round(stack_length(sb) / 2.0))
		total += stack_length(sb) - sa->target->index;
	else
		total += sa->target->index;
	return (total);
}
