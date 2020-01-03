/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flag_plus_space.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 16:32:43 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		put_plus_change_count(t_info *flag)
{
	ft_putchar_fd('+', (*flag).fd);
	(*flag).count++;
	(*flag).plus = -1;
}

void		check_flag_plus(t_info *flag, t_padding *padding, int left_align)
{
	if ((*flag).neg == 0)
		(*padding).fill_w--;
	if ((*flag).neg == 0 && (*flag).f_nan == 0 && (*flag).plus == 1)
	{
		if ((*flag).zero == 1 && (*flag).minus == 1 && (((*flag).precision != 0\
		|| left_align == 1) || (*flag).zero == 1))
		{
			put_plus_change_count(flag);
		}
		if ((*flag).plus == 1 && (*padding).fill_p > 0 && (*padding).fill_w > 0\
		&& (*flag).zero == 1)
		{
			put_plus_change_count(flag);
		}
	}
}

void		put_neg_or_plus(t_info *flag)
{
	if ((*flag).neg == 1)
		put_neg(flag);
	if ((*flag).plus == 1 && (*flag).neg == 0)
		put_plus_change_count(flag);
}

void		check_flag_space(t_info *flag, t_padding *padding)
{
	if ((*flag).neg == 0 && (*flag).f_nan == 0)
	{
		ft_putchar_fd(' ', (*flag).fd);
		(*padding).fill_w--;
		(*flag).count++;
	}
}

void		check_flag_plus_space(t_info *flag, t_padding *padding,\
			int left_align)
{
	if ((*flag).plus == 1)
		check_flag_plus(flag, padding, left_align);
	if ((*flag).space == 1 && (*flag).plus == 0)
		check_flag_space(flag, padding);
}
