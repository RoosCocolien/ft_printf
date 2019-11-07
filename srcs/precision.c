/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 13:49:14 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	I use this function for spec e, spec f and spec x.
*/

int		fill_width_prec(t_info *flag, int length)
{
	int		fill;

	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	fill = (*flag).width - length;
	return (fill);
}

void	prec_and_zero_check(va_list args, t_info *flag, char spec)
{
	(*flag).dot = 1;
	if ((*flag).precision == 2)
	{
		if (spec == 'p' || spec == 'x' || spec == 'd' || spec == 'i')
			(*flag).width = va_arg(args, int);
		else
			(*flag).prec_value = va_arg(args, int);
	}
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);
	if ((*flag).prec_value == 0 && spec != 'p' && spec != 'd' && spec != 'i')
	{
		if ((*flag).precision != 0)
		{
			(*flag).no_decimals = 1;
			if ((*flag).hash != 1)
				(*flag).dot = 0;
		}
		else
			(*flag).prec_value = 6;
	}
	if ((*flag).minus == 1 && spec != 'd' && spec != 'i')
		(*flag).zero = 0;
	if (spec == 'x' || spec == 'X')
		(*flag).plus = 0;
}
