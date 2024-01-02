/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:45:58 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:45:08 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rr(t_elem **stack_a, t_elem **stack_b)
{
	do_ra(stack_a, 0);
	do_rb(stack_b, 0);
	ft_printf("rr\n");
	return (true);
}
