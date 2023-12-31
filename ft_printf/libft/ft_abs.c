/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarolle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:01:47 by bcarolle          #+#    #+#             */
/*   Updated: 2024/01/08 17:01:47 by bcarolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	math_round(float nb)
{
	nb += 0.5;
	return ((int)(nb));
}
