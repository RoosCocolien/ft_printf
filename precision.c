/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/14 20:41:27 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			fill_width_prec(t_info *flag, int length)
{
	int		fill;

	fill = 0;
	//toegevoegd voor x en p
	if ((*flag).width > 0 && (*flag).precision == 1 && (*flag).prec_value == 0)
	{
		(*flag).precision = 0;
		(*flag).prec_value = 0;
		(*flag).zero = 0;
	}
	// printf("prec value: %d\n", (*flag).prec_value);
	if ((*flag).precision != 0 && ((*flag).prec_value != 0\
	|| (*flag).width != 0))
	{
		//%%#09.0X
		// printf("fill_width_prec test\n");
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	return (fill);
}

void		pres_width_s(va_list args, t_info *flag)
{
	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 2)
		{
			(*flag).prec_value = va_arg(args, int);
			if ((*flag).prec_value < 0)
			{
				(*flag).minus = 1;
				(*flag).prec_value = -(*flag).prec_value;
			}
		}
		(*flag).zero = 0;
		(*flag).minus = 0;
	}
	if ((*flag).prec_no_val == 1)
	{
		(*flag).precision = 1;
		(*flag).prec_value = 0;
	}
}

void		get_prec_width(va_list args, t_info *flag, char spec)
{
	if ((*flag).precision == 2)
	{
		if (spec == 'p' || spec == 'x' || spec == 'd' || spec == 'i'\
		|| spec == 'u' || spec == 'o' || spec == 'X')
		{
			(*flag).width = va_arg(args, int);
			if ((*flag).width < 0)
				(*flag).width = 0;
		}
		else
		{
			(*flag).prec_value = va_arg(args, int);
			if ((*flag).prec_value < 0)
			{
				(*flag).prec_value = 6;
				printf("get_prec_width\tchange prec value to 6\n");
			}
		}
	}
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);
	if ((*flag).width < 0)
	{
		(*flag).width = -(*flag).width;
		(*flag).minus = 1;
	}
}

void		prec_and_zero_check(va_list args, t_info *flag, char spec)
{
	(*flag).dot = 1;
	get_prec_width(args, flag, spec);
	if ((*flag).prec_value == 0 && spec != 'p' && spec != 'd' && spec != 'i'\
	&& spec != 'u' && spec != 'x' && spec != 'X')
	{
		if ((*flag).precision != 0)
		{
			(*flag).no_decimals = 1;
			if ((*flag).hash != 1)
				(*flag).dot = 0;
		}
		else
		{
			(*flag).prec_value = 6;
		}
	}
	if ((*flag).minus == 1 && spec != 'd' && spec != 'i')
		(*flag).zero = 0;
	if (spec == 'x' || spec == 'X')
		(*flag).plus = 0;
}