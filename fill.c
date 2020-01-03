/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 16:52:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			change_fill_0x(intmax_t i, t_info *flag, char spec, int fill)
{
	if ((i != 0 && (*flag).hash == 1) || spec == 'p')
	{
		if (i == 0 && (*flag).prec_value == 0 && spec != 'p')
			return (fill);
		else
			fill += 2;
	}
	if (fill < 2 && (spec == 'p' || (*flag).hash == 1))
		fill = 2;
	return (fill);
}

int			fill_width_prec(t_info *flag, int length)
{
	int		fill;

	fill = 0;
	if ((*flag).width > 0 && (*flag).precision == 1 && (*flag).prec_value == 0)
	{
		(*flag).precision = 0;
		(*flag).prec_value = 0;
		(*flag).zero = 0;
	}
	if ((*flag).precision != 0 && ((*flag).prec_value != 0\
	|| (*flag).width != 0))
	{
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).prec_value - length;
	return (fill);
}

int			fill_precision(t_info *flag, int length)
{
	int fill;

	fill = 0;
	if ((*flag).precision != 0)
		fill = (*flag).prec_value - length;
	if (fill < 0)
		fill = 0;
	return (fill);
}

int			fill_width(t_info *flag, char spec, int length)
{
	int fill;

	fill = 0;
	if (spec == 'p' && length == 0 && (*flag).prec_value == 0)
		length = 2;
	if ((*flag).width != 0)
		fill = (*flag).width - length;
	if (fill < 0)
		fill = 0;
	return (fill);
}
