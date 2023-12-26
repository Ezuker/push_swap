/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:56:50 by bcarolle          #+#    #+#             */
/*   Updated: 2023/12/24 20:25:14 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	t_elem	*sa;
	t_elem	*sb;

	sb = NULL;
	sa = malloc(sizeof(t_elem));
	sa->number = 10;
	sa->next = malloc(sizeof(t_elem));
	sa->next->prev = sa;
	sa->next->number = 45;
	sa->next->next = malloc(sizeof(t_elem));
	sa->next->next->number = 12;
	sa->next->next->prev = sa->next;
	sa->next->next->next = malloc(sizeof(t_elem));
	sa->next->next->next->number = 32;
	sa->next->next->next->prev = sa->next->next;
	sa->next->next->next->next = NULL;

	print_stack(sa, sb);
	do_rra(&sa);
	print_stack(sa, sb);
}
