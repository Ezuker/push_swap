/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:32 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 17:38:18 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	only_nb(char *str)
{
	int		i;
	t_bool	one_num;

	i = 0;
	one_num = false;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			one_num = true;
		else if (str[i] != 45 && str[i] != 32 && str[i] != 43)
			return (false);
		else if ((str[i] == 45 || str[i] == 43)
			&& ((!ft_isdigit(str[i + 1]))
				|| (i > 0 && str[i - 1] != 32)))
			return (false);
		i++;
	}
	if (one_num)
		return (true);
	return (false);
}

t_bool	repeated_number(t_elem	*sa)
{
	t_elem	*cpy;
	t_elem	*head_cpy;

	cpy = sa;
	head_cpy = cpy;
	while (sa)
	{
		while (cpy)
		{
			if (cpy->index != sa->index && cpy->number == sa->number)
				return (true);
			cpy = cpy->next;
		}
		cpy = head_cpy;
		sa = sa->next;
	}
	return (false);
}

void	add_index(t_elem	*sa)
{
	int	i;

	i = 0;
	while (sa)
	{
		sa->index = i;
		sa = sa->next;
		i++;
	}
}

t_bool	parsing(int argc, char **argv, t_elem **sa)
{
	int		i;
	t_elem	*node;

	i = 0;
	while (++i < argc)
	{
		if (!only_nb(argv[i]))
			return (false);
		if (ft_strlen(argv[i]) <= 2)
		{
			node = ft_str_to_elem(argv[i]);
			if (!node)
				return (false);
			ft_addback(sa, node);
		}
		else
			if (!add_elem(sa, i, argv))
				return (false);
	}
	return (true);
}
