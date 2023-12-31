/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:52:09 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:45:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_rrr(t_elem **stack_a, t_elem **stack_b)
{
	do_rra(stack_a, 0);
	do_rrb(stack_b, 0);
	ft_printf("rrr\n");
	return (true);
}
