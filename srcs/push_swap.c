/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:56:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:12:29 by bcarolle         ###   ########.fr       */
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

t_bool	parsing(int argc, char **argv, t_elem **sa)
{
	int		i;
	int		j;
	t_elem	*node;
	char	**temp;

	i = 1;
	j = 0;
	while (i < argc)
	{
		if (!only_nb(argv[i]))
		{
			ft_printf("Error\n");
			return (false);
		}
		if (ft_strlen(argv[i]) <= 2)
		{
			node = ft_str_to_elem(argv[i]);
			ft_addback(sa, node);
		}
		else
		{
			temp = ft_split(argv[i], ' ');
			while (temp[j] != NULL)
			{
				node = ft_str_to_elem(temp[j]);
				ft_addback(sa, node);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_elem	*sa;
	t_elem	*sb;

	sa = NULL;
	sb = NULL;
	if (!parsing(argc, argv, &sa))
		return (0);
	// sb = NULL;
	// sa = malloc(sizeof(t_elem));
	// sa->number = 10;
	// sa->next = malloc(sizeof(t_elem));
	// sa->next->prev = sa;
	// sa->next->number = 45;
	// sa->next->next = malloc(sizeof(t_elem));
	// sa->next->next->number = 12;
	// sa->next->next->prev = sa->next;
	// sa->next->next->next = malloc(sizeof(t_elem));
	// sa->next->next->next->number = 32;
	// sa->next->next->next->prev = sa->next->next;
	// sa->next->next->next->next = NULL;

	print_stack(sa, sb);
	do_rra(&sa);
	print_stack(sa, sb);
}
