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
	do_sa(stack_a, 0);
	do_sb(stack_b, 0);
	return (true);
}
