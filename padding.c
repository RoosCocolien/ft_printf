/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 23:07:24 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		put_0x_spec_f(int count, char spec, int fd)
{
	if (spec >= 65 && spec <= 90)
		ft_putstr_fd("0X", fd);
	else
		ft_putstr_fd("0x", fd);
	return (count += 2);
}

int		change_fill(t_info *flag, int fill, int length)
{
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	if ((*flag).neg == 1 && (*flag).precision == 0)
		fill--;
	if ((*flag).plus == 1)
		fill = check_flag_plus(flag, fill, (*flag).minus);
	if ((*flag).space == 1)
		fill = check_flag_space(flag, fill, (*flag).minus);
	return (fill);
}

void	put_padding_w(t_info *flag, int fill_w)
{
	while (fill_w > 0)
	{
		ft_putchar_fd(' ', (*flag).fd);
		(*flag).count++;
		fill_w--;
	}
}

void	put_padding(t_info *flag, int fill)
{
	char	char_fill;

	if ((*flag).zero == 1 && (*flag).prec_no_val == 0)
	{
		char_fill = '0';
		if ((*flag).neg == 1)
		{
			ft_putchar_fd('-', (*flag).fd);
			(*flag).count++;
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
