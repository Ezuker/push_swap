/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:29:32 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 03:19:16 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker_bonus.h"

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

t_elem	*ft_str_to_elem(char *str)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	if (!node)
		return (NULL);
	node->number = ft_atoi(str);
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	node->target = NULL;
	return (node);
}

t_bool	parsing(int argc, char **argv, t_elem **sa)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = -1;
	while (++i < argc)
	{
		if (!only_nb(argv[i]))
			return (false);
		if (ft_strlen(argv[i]) <= 2)
			ft_addback(sa, ft_str_to_elem(argv[i]));
		else
		{
			temp = ft_split(argv[i], ' ');
			while (temp[++j] != NULL)
			{
				ft_addback(sa, ft_str_to_elem(temp[j]));
				free(temp[j]);
			}
			free(temp);
			j = -1;
		}
	}
	return (true);
}
