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

void	a_to_action()
{
	
}

void	read_stdin(t_action **action)
{

}

void	checking(t_elem **sa, t_elem **sb)
{
	t_action	*action;
	
	action = NULL;
	read_stdin(&action);

	//Appliquer les actions

	//verif si c'est sort
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
