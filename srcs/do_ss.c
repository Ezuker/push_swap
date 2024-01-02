/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 23:45:58 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:47:06 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	do_ss(t_elem **stack_a, t_elem **stack_b)
{
	do_sa(stack_a, 0);
	do_sb(stack_b, 0);
	return (true);
}
