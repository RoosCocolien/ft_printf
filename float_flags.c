/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_flags.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 19:28:03 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			check_flag_space_float(t_info *flag, int fill)
{
	if ((*flag).neg == 0 && (*flag).f_nan == 0 && (*flag).space == 1)
	{
		ft_putchar_fd(' ', (*flag).fd);
		fill--;
		(*flag).count++;
	}
	return (fill);
}

int			check_flag_plus_float(t_info *flag, int fill, int left_align)
{
	if ((*flag).neg == 0)
	{
		fill--;
	}
	if ((*flag).neg == 0 && (*flag).f_nan == 0 && (*flag).plus == 1)
	{
		if ((*flag).zero == 1 && (*flag).minus == 1 && (((*flag).precision != 0\
		|| left_align == 1) || (*flag).zero == 1))
		{
			put_plus_change_count(flag);
		}
		if ((*flag).minus == 1 && (*flag).plus == 1)
		{
			put_plus_change_count(flag);
		}
		if ((*flag).plus == 1 && (*flag).zero == 1 && (*flag).precision == 0)
		{
			put_plus_change_count(flag);
		}
	}
	return (fill);
}
