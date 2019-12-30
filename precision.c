/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:18:59 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static void	get_prec_value_if_asterisk(va_list args, t_info *flag)
{
	(*flag).prec_value = va_arg(args, int);
	(*flag).zero = 0;
	if ((*flag).prec_value < 0)
	{
		(*flag).minus = 1;
		(*flag).prec_value = -(*flag).prec_value;
	}
	if ((*flag).width == -1)
	{
		(*flag).width = (*flag).prec_value;
		(*flag).prec_value = 0;
	}
}

void		pres_width_s(va_list args, t_info *flag)
{
	if ((*flag).precision == -1)
	{
		(*flag).prec_value = va_arg(args, int);
		(*flag).zero = 0;
		if ((*flag).prec_value < 0)
			(*flag).minus = 1;
		(*flag).prec_value = 0;
	}
	else if ((*flag).asterisk == 1 && (*flag).precision != 2)
		get_prec_value_if_asterisk(args, flag);
	if ((*flag).precision == 2)
	{
		(*flag).prec_value = va_arg(args, int);
		(*flag).zero = 0;
		if ((*flag).prec_value < 0)
		{
			(*flag).precision = 0;
			(*flag).prec_value = 0;
		}
	}
	if ((*flag).prec_no_val == 1)
	{
		(*flag).precision = 1;
		(*flag).prec_value = 0;
	}
}

void		change_prec_value_if_neg(t_info *flag, char spec)
{
	if (spec == 'f' && (*flag).asterisk == 0)
		(*flag).prec_value = 6;
	else if ((*flag).asterisk == 0)
	{
		(*flag).prec_value = 0;
		(*flag).precision = 0;
	}
	else
	{
		(*flag).prec_value = -(*flag).prec_value;
		(*flag).minus = 1;
	}
}

void		get_prec_width(va_list args, t_info *flag, char spec)
{
	if (((*flag).precision == 2 || (*flag).asterisk == 1)\
	&& (*flag).prec_value == 0)
	{
		if (spec == 'p' || spec == 'x' || spec == 'd' || spec == 'i'\
		|| spec == 'u' || spec == 'o' || spec == 'X')
		{
			(*flag).prec_value = va_arg(args, int);
		}
		else
		{
			if ((spec == 'e' || spec == 'E') && (*flag).width == -1)
				(*flag).width = va_arg(args, int);
			else
				(*flag).prec_value = va_arg(args, int);
		}
	}
	if ((*flag).prec_value < 0)
	{
		change_prec_value_if_neg(flag, spec);
	}
}

void		get_sequence_prec_width(va_list args, t_info *flag)
{
	if ((*flag).sequence < 0)
	{
		(*flag).width = va_arg(args, int);
		(*flag).prec_value = va_arg(args, int);
	}
	if ((*flag).sequence > 0)
	{
		(*flag).prec_value = va_arg(args, int);
		(*flag).width = va_arg(args, int);
	}
	if ((*flag).width < 0)
	{
		(*flag).width = -(*flag).width;
		(*flag).minus = 1;
	}
	if ((*flag).prec_value < 0)
	{
		(*flag).prec_value = 6;
	}
}
