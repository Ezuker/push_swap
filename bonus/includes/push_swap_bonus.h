/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:57:41 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/27 15:55:55 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_elem
{
	struct s_elem	*prev;
	struct s_elem	*next;
	int				number;
}				t_elem;

t_bool	do_sa(t_elem **stack, t_bool print);
t_bool	do_sb(t_elem **stack, t_bool print);
t_bool	do_ss(t_elem **stack_a, t_elem **stack_b);
t_bool	do_pb(t_elem **sa, t_elem **sb);
t_bool	do_pa(t_elem **sa, t_elem **sb);
t_bool	do_ra(t_elem **sa, t_bool print);
t_bool	do_rb(t_elem **sb, t_bool print);
t_bool	do_rr(t_elem **sa, t_elem **sb);
t_bool	do_rra(t_elem **stack_a, t_bool print);
t_bool	do_rrb(t_elem **stack_b, t_bool print);
t_bool	do_rrr(t_elem **sa, t_elem **sb);
t_elem	*ft_lastelem(t_elem *lst);
void	print_stack(t_elem	*stack_a, t_elem *stack_b);
t_bool	ft_addback(t_elem **lst, t_elem *node);
t_elem	*ft_str_to_elem(char *str);
void	print_data(t_elem *stack_a);

#endif
