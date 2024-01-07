/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:32 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/06 15:29:53 by bcarolle         ###   ########.fr       */
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
		{
			one_num = true;
			i++;
		}
		else if (str[i] == 32)
			i++;
		else if (!((str[i] == 45 || str[i] == 43)
				&& (ft_isdigit(str[i + 1]))))
			return (false);
		else
			i++;
	}
	if (one_num)
		return (true);
	return (false);
}

t_bool	repeated_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	argv++;
	while (i < argc - 1)
	{
		while (j < argc - 1)
		{
			if (i != j && !ft_strcmp(argv[i], argv[j]))
			{
				ft_printf("Error\n");
				return (true);
			}
			j++;
		}
		j = 0;
		i++;
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
	int		j;
	char	**temp;

	i = 0;
	j = -1;
	if (repeated_number(argc, argv))
		return (false);
	while (++i < argc)
	{
		if (!only_nb(argv[i]))
		{
			ft_printf("Error\n");
			return (false);
		}
		if (ft_strlen(argv[i]) <= 2)
			ft_addback(sa, ft_str_to_elem(argv[i]));
		else
		{
			temp = ft_split(argv[i], ' ');
			while (temp[++j] != NULL)
				ft_addback(sa, ft_str_to_elem(temp[j]));
			j = -1;
		}
	}
	add_index(*sa);
	return (true);
}
