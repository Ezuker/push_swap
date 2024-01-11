/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ss_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:49 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:49 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_ss(t_elem **stack_a, t_elem **stack_b)
{
	if (!stack_a || !*stack_a)
		return (false);
	if (!stack_b || !*stack_b)
		return (false);
	do_sa(stack_a);
	do_sb(stack_b);
	return (true);
}
