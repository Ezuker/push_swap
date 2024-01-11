/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:02:24 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 15:03:43 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	check_action(t_action *action, t_elem **sa, t_elem **sb)
{
	if (!ft_strcmp((action)->name, "sa\n"))
		do_sa(sa);
	if (!ft_strcmp((action)->name, "sb\n"))
		do_sb(sb);
	if (!ft_strcmp((action)->name, "ss\n"))
		do_ss(sa, sb);
	if (!ft_strcmp((action)->name, "pa\n"))
		do_pa(sa, sb);
	if (!ft_strcmp((action)->name, "pb\n"))
		do_pb(sa, sb);
	if (!ft_strcmp((action)->name, "ra\n"))
		do_ra(sa);
	if (!ft_strcmp((action)->name, "rb\n"))
		do_rb(sb);
	if (!ft_strcmp((action)->name, "rr\n"))
		do_rr(sa, sb);
	if (!ft_strcmp((action)->name, "rra\n"))
		do_rra(sa);
	if (!ft_strcmp((action)->name, "rrb\n"))
		do_rrb(sb);
	if (!ft_strcmp((action)->name, "rrr\n"))
		do_rrr(sa, sb);
}

void	do_action(t_action *action, t_elem **sa, t_elem **sb)
{
	while (action)
	{
		check_action(action, sa, sb);
		(action) = (action)->next;
	}
}
