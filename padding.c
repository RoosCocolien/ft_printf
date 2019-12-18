/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/02 16:40:53 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		put_0x_spec_f(int count, char spec)
{
	if (spec >= 65 && spec <= 90)
		ft_putstr("0X");
	else
		ft_putstr("0x");
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
		ft_putchar(' ');
		(*flag).count++;
		fill_w--;
	}
}

void	put_padding(t_info *flag, int fill)
{
	char	char_fill;

	// printf("%d\t\tfill (padding test)\n", fill);
	if ((*flag).zero == 1 && (*flag).prec_no_val == 0)
	{
		char_fill = '0';
		if ((*flag).neg == 1)
		{
			ft_putchar('-');
			(*flag).count++;
		}
	}
	else
		char_fill = ' ';
	while (fill > 0)
	{
		ft_putchar(char_fill);
		(*flag).count++;
		fill--;
	}
}