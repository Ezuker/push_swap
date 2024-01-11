/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:15:43 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/10 20:15:43 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../../ft_printf/ft_printf.h"

# define BUFFER_SIZE 1

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_elem
{
	struct s_elem	*prev;
	struct s_elem	*next;
	struct s_elem	*target;
	int				number;
	int				index;
}				t_elem;

typedef struct s_action
{
	char			*name;
	struct s_action	*next;
}				t_action;

t_bool	do_sa(t_elem **stack);
t_bool	do_sb(t_elem **stack);
t_bool	do_ss(t_elem **stack_a, t_elem **stack_b);
t_bool	do_pb(t_elem **sa, t_elem **sb);
t_bool	do_pa(t_elem **sa, t_elem **sb);
t_bool	do_ra(t_elem **sa);
t_bool	do_rb(t_elem **sb);
t_bool	do_rr(t_elem **sa, t_elem **sb);
t_bool	do_rra(t_elem **stack_a);
t_bool	do_rrb(t_elem **stack_b);
t_bool	do_rrr(t_elem **sa, t_elem **sb);
t_elem	*ft_lastelem(t_elem *lst);
void	print_stack(t_elem	*stack_a, t_elem *stack_b);
t_bool	ft_addback(t_elem **lst, t_elem *node);
t_elem	*ft_str_to_elem(char *str);
void	print_data(t_elem *stack_a);
t_bool	only_nb(char *str);
t_bool	parsing(int argc, char **argv, t_elem **sa);
int		stack_length(t_elem	*stack);
t_elem	*get_max_stack(t_elem *stack);
t_elem	*get_min_stack(t_elem *stack);
void	add_index(t_elem	*sa);
t_bool	is_sorted(t_elem *stack);
t_bool	repeated_number(t_elem	*sa);
t_bool	get_next_line(t_action **action);
t_bool	add_action(char *name, t_action **action);
void	do_action(t_action *action, t_elem **sa, t_elem **sb);
t_bool	add_elem(t_elem **sa, int index, char **argv);
t_elem	*ft_str_to_elem(char *str);

#endif
