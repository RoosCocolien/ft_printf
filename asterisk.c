/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asterisk.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 19:50:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 18:27:06 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static void	reset_prec_zero(t_info *flag, char spec)
{
	if (spec == 'd' || spec == 'i' || spec == 'u' || spec == 'o')
	{
		if ((*flag).width > 0 && (*flag).precision != 0\
		&& (*flag).prec_value == 0 && (*flag).asterisk == 1)
		{
			(*flag).precision = 0;
			(*flag).prec_value = 0;
			(*flag).zero = 0;
		}
	}
}

static void	reset_width_and_prec_value(t_info *flag, char spec)
{
	if (((*flag).width == -1 && (*flag).asterisk == 1) ||\
	((*flag).width == 0 && (*flag).prec_value != 0 &&\
	(spec == 'd' || spec == 'i' || spec == 'u' || spec == 'o')))
	{
		(*flag).width = (*flag).prec_value;
		if (spec == 'f')
			(*flag).prec_value = 6;
	}
}

void		check_asterisk(t_info *flag, char spec)
{
	reset_prec_zero(flag, spec);
	if ((*flag).precision != -1)
	{
		reset_width_and_prec_value(flag, spec);
	}
	if ((*flag).precision == -1)
	{
		(*flag).precision = 0;
		(*flag).prec_value = 0;
	}
}
