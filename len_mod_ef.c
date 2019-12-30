/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_ef.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 15:41:51 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:01:45 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

long double		len_mod_check_efg(va_list args, t_info *flag)
{
	long double		i;

	if ((*flag).l_cap == 1)
	{
		i = (long double)va_arg(args, long double);
	}
	else
	{
		i = (long double)va_arg(args, double);
	}
	if (i < 0)
	{
		(*flag).neg = 1;
		(*flag).space = 0;
		(*flag).plus = 0;
		i = -i;
	}
	if (i == 0.0)
		(*flag).neg = float_check_neg_zero(i);
	return (i);
}
