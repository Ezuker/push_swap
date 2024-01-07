/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:56:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 16:22:53 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	sort_three(t_elem	**stack)
{
	while (!is_sorted(*stack))
	{
		if (ft_lastelem(*stack)->number == get_max_stack(*stack)->number)
			do_sa(stack, 1);
		else if ((*stack)->number == get_max_stack(*stack)->number
			&& ft_lastelem(*stack)->number == get_min_stack(*stack)->number)
		{
			do_sa(stack, 1);
			do_rra(stack, 1);
		}
		else if ((*stack)->number == get_max_stack(*stack)->number
			&& ft_lastelem(*stack)->number != get_min_stack(*stack)->number)
			do_ra(stack, 1);
		else if ((*stack)->number == get_min_stack(*stack)->number)
		{
			do_rra(stack, 1);
			do_sa(stack, 1);
		}
		else
			do_rra(stack, 1);
	}
}

void	push_two(t_elem	**sa, t_elem	**sb)
{
	if (stack_length(*sa) == 4)
		do_pb(sa, sb);
	else
	{
		do_pb(sa, sb);
		do_pb(sa, sb);
	}
}

void	set_target_a(t_elem *sa, t_elem *sb)
{
	int		delta;
	t_elem	*save;
	t_elem	*save_b;

	delta = 2147483647;
	save_b = sb;
	while (sa)
	{
		while (sb)
		{
			if (sa->number > sb->number && delta > sa->number - sb->number)
			{
				delta = sa->number - sb->number;
				save = sb;
			}
			sb = sb->next;
		}
		sb = save_b;
		if (delta == 2147483647)
			sa->target = get_max_stack(sb);
		else
			sa->target = save;
		delta = 2147483647;
		save = NULL;
		sa = sa->next;
	}
}

void	cost_analysis(t_elem *sa, t_elem *sb, t_cost *cost)
{
	float	median_a;
	float	median_b;
	int		save;
	int		actu;

	save = 0;
	median_a = stack_length(sa) / 2;
	median_b = stack_length(sb) / 2;
	while (sa)
	{
		if (sa->index > median_a)
			cost->ra += stack_length(sa) - sa->index;
		else
			actu += sa->index;
		if (sa->target->index > median_b)
			actu += stack_length(sb) - sb->index;
		else
			actu += sb->index;
		if (save < actu)
			save = actu;
		actu = 0;
		sa = sa->next;
	}
}

void	mechanical_turk(t_elem	**sa, t_elem	**sb)
{
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	push_two(sa, sb);
	set_target_a(*sa, *sb);
	add_index(*sa);
	add_index(*sb);
	cost_analysis(*sa, *sb, cost);
	print_data(*sa);
	print_data(*sb);
}

int	main(int argc, char **argv)
{
	t_elem	*sa;
	t_elem	*sb;

	sa = NULL;
	sb = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
		return (0);
	if (stack_length(sa) == 2 && !is_sorted(sa))
	{
		do_sa(&sa, 1);
		return (0);
	}
	else if (stack_length(sa) == 3)
	{
		sort_three(&sa);
		return (0);
	}
	else
		mechanical_turk(&sa, &sb);
	return (0);
}

