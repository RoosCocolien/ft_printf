/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/11 19:37:41 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	prec_and_zero_check(va_list args, t_info *flag, char spec)
{
	if ((*flag).precision == 2)
	{
		if (spec == 'p' || spec == 'x')
			(*flag).width = va_arg(args, int);
		else
			(*flag).prec_value = va_arg(args, int);
	}
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);
	if ((*flag).prec_value == 0 && spec != 'p')
	{
		if ((*flag).precision != 0)
			(*flag).no_decimals = 1;
		else
			(*flag).prec_value = 6;
	}
	if ((*flag).minus == 1)
		(*flag).zero = 0;
	if ((*flag).precision != 0 && /*spec == 'p' && */(*flag).minus != 1)
		(*flag).zero = 1;
}
