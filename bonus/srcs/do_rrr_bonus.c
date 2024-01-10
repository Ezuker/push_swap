/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:36 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:36 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

t_bool	do_rrr(t_elem **stack_a, t_elem **stack_b)
{
	do_rra(stack_a, 0);
	do_rrb(stack_b, 0);
	ft_printf("rrr\n");
	return (true);
}
