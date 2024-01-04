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

#include "../includes/push_swap_bonus.h"

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
	char	**temp;

	i = 1;
	j = -1;
	while (i < argc)
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
		i++;
	}
	return (true);
}

void read_stdout(t_elem	**sa)
{

}

int	main(int argc, char **argv)
{
	t_elem	*sa;

	sa = NULL;
	if (argc < 2 || !parsing(argc, argv, &sa))
		return (0);
	read_stdout(&sa);
}
