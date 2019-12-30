/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 15:32:58 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		put_0x_spec_f(int count, char spec, int fd)
{
	if (spec >= 65 && spec <= 90)
		ft_putstr_fd("0X", fd);
	else
		ft_putstr_fd("0x", fd);
	return (count += 2);
}

int		change_fill_float(t_info *flag, int fill, int length)
{
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	if ((*flag).neg == 1 /* && (*flag).prec_value == 0*/)
	{
		fill--;
	}
	if ((*flag).plus == 1)
	{
		fill = check_flag_plus_float(flag, fill, (*flag).minus);
	}
	if ((*flag).space == 1)
		fill = check_flag_space_float(flag, fill);
	return (fill);
}

int		calc_extra_padding(t_info *flag)
{
	int extra_padding;

	extra_padding = 0;
	if ((*flag).neg != 0)
	{
		extra_padding++;
	}
	else
	{
		if ((*flag).plus == 1)
			extra_padding++;
	}
	return (extra_padding);
}

void	put_space_plus_e(t_info *flag, t_padding *padding)
{
	if ((*flag).zero == 1 && (*flag).neg != 1)
	{
		if ((*flag).space == 1 && (*flag).plus == 0 && (*flag).neg == 0)
		{
			ft_putchar_fd(' ', (*flag).fd);
			(*padding).fill_w--;
			(*flag).count++;
		}
		if ((*flag).plus == 1 && (*flag).neg == 0)
		{
			ft_putchar_fd('+', (*flag).fd);
			(*flag).plus = -1;
			(*flag).count++;
		}
	}
	if ((*flag).zero == 1 && (*flag).neg == 1)
	{
		ft_putchar_fd('-', (*flag).fd);
		(*flag).plus = -1;
		(*flag).count++;
	}
}

void	put_padding(t_info *flag, int fill)
{
	char	char_fill;

	if ((*flag).zero == 1 && (*flag).prec_no_val == 0)
	{
		char_fill = '0';
		if ((*flag).neg == 1 && (*flag).f_nan == 0)
		{
			ft_putchar_fd('-', (*flag).fd);
			(*flag).neg = 1;
			(*flag).count++;
		}
		else if ((*flag).plus == 1 && (*flag).f_nan == 0 && (*flag).neg == 0)
		{
			put_plus_change_count(flag);
		}
	}
	else
		char_fill = ' ';
	while (fill > 0)
	{
		ft_putchar_fd(char_fill, (*flag).fd);
		(*flag).count++;
		fill--;
	}
}
