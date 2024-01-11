/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:00:29 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/11 17:09:31 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	add_elem(t_elem **sa, int index, char **argv)
{
	char	**temp;
	int		j;
	t_elem	*node;

	j = -1;
	temp = ft_split(argv[index], ' ');
	while (temp[++j] != NULL)
	{
		node = ft_str_to_elem(temp[j]);
		if (!node)
			return (false);
		ft_addback(sa, node);
		free(temp[j]);
	}
	free(temp);
	return (true);
}

t_elem	*ft_str_to_elem(char *str)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	if (!node)
		return (NULL);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (NULL);
	node->number = ft_atoi(str);
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	node->target = NULL;
	return (node);
}
