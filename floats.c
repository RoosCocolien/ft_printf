/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   floats.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 14:52:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/23 15:34:35 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		float_check_neg_zero(long double i)
{
	t_float	float_nb;
	int		neg;

	neg = 0;
	float_nb = (t_float)i;
	neg = float_nb.float_short[4] >> 15 & 1;
	return (neg);
}
