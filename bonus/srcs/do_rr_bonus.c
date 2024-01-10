/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:23 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:23 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_rr(t_elem **stack_a, t_elem **stack_b)
{
	do_ra(stack_a, 0);
	do_rb(stack_b, 0);
	ft_printf("rr\n");
	return (true);
}
