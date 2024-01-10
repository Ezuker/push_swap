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

typedef struct s_cost
{
	float	ra;
	float	rb;
	float	rra;
	float	rrb;
}				t_cost;

typedef struct s_elem
{
	struct s_elem	*prev;
	struct s_elem	*next;
	struct s_elem	*target;
	int				number;
	int				index;
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
t_bool	only_nb(char *str);
t_bool	parsing(int argc, char **argv, t_elem **sa);
int		stack_length(t_elem	*stack);
t_elem	*get_max_stack(t_elem *stack);
t_elem	*get_min_stack(t_elem *stack);
void	add_index(t_elem	*sa);
void	set_target_b(t_elem *sa, t_elem *sb);
void	set_target_a(t_elem *sa, t_elem *sb);
void	push_two(t_elem	**sa, t_elem	**sb);
void	sort_three(t_elem	**stack);
t_bool	is_sorted(t_elem *stack);
void	final_sort(t_elem	**sa);
void	do_action_b(t_elem *id, t_elem **sb, t_elem **sa);
void	do_action_a(t_elem *id, t_elem **sa, t_elem **sb);
float	get_bigger_delta(int sa_number, int sb_number);
float	get_lower_delta(int sa_number, int sb_number);
t_elem	*get_save_a(float *delta, t_elem *sa, t_elem *sb, t_elem *save);
t_elem	*get_save_b(float *delta, t_elem *sa, t_elem *sb, t_elem *save);
int		get_total_above_median(int length_a, t_elem *sa, t_elem *sb);
int		get_total_below_median(t_elem *sa);
int		get_total_other(int length_a, t_elem *sa, t_elem *sb);
t_elem	*cost_analysis(t_elem *sa, t_elem *sb);
void	sort_four(t_elem **sa, t_elem **sb);
t_bool	repeated_number(t_elem	*sa);

#endif
