/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:57:41 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:25:34 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

t_bool	do_sa(t_elem **stack);
t_bool	do_sb(t_elem **stack);
t_bool	do_ss(t_elem **stack_a, t_elem **stack_b);
t_bool	do_pb(t_elem **sa, t_elem **sb);
t_bool	do_pa(t_elem **sa, t_elem **sb);
t_bool	do_ra(t_elem **sa);
t_bool	do_rb(t_elem **sb);
t_bool	do_rr(t_elem **sa, t_elem **sb);
t_bool	do_rra(t_elem **stack_a);
t_elem	*ft_lastelem(t_elem *lst);
void	print_stack(t_elem	*stack_a, t_elem *stack_b);
#endif
