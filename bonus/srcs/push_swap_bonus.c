/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:16:56 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:16:56 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

void	ft_elem_clear(t_elem **sa)
{
	t_elem	*tmp;

	while (*sa)
	{
		tmp = *sa;
		(*sa) = (*sa)->next;
		free(tmp);
	}
}

t_bool	is_sorted(t_elem *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_action_clear(t_action **action)
{
	t_action	*tmp;

	while (*action)
	{
		tmp = *action;
		if ((*action)->name)
			free((*action)->name);
		(*action) = (*action)->next;
		free(tmp);
	}
}

void	do_action(t_action *action, t_elem **sa, t_elem **sb)
{
	while (action)
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
		(action) = (action)->next;
	}
}

void	checking(t_elem **sa, t_elem **sb)
{
	t_action	*action;
	
	action = NULL;
	if (!get_next_line(&action))
	{
		write(2,"Error\n", 6);
		ft_action_clear(&action);
		return ;
	}
	do_action(action, sa, sb);
	if (is_sorted(*sa))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_action_clear(&action);
}

int	main(int argc, char **argv)
{
	t_elem	*sa;
	t_elem	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
	{
		ft_elem_clear(&sa);
		write(2, "Error\n", 6);
		return (0);
	}
	add_index(sa);
	if (repeated_number(sa))
	{
		ft_elem_clear(&sa);
		write(2, "Error\n", 6);
		return (0);
	}
	checking(&sa, &sb);
	ft_elem_clear(&sa);
	return (0);
}
