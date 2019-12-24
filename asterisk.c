/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asterisk.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 19:50:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/24 11:13:44 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		check_asterisk(t_info *flag, char spec)
{
	if ((*flag).precision != -1)
	{
		if (((*flag).width == -1 && (*flag).asterisk == 1) ||\
		((*flag).width == 0 && (*flag).prec_value != 0 &&\
		(spec == 'd' || spec == 'i' || spec == 'u')))
		{
			(*flag).width = (*flag).prec_value;
		}
	}
	if ((*flag).precision == -1)
	{
		(*flag).precision = 0;
		(*flag).prec_value = 0;
	}
}
