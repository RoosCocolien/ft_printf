/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 17:22:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:17:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void		set_padding_to_zero(t_padding *padding)
{
	(*padding).fill_p = 0;
	(*padding).fill_w = 0;
	(*padding).length = 0;
}

void		put_padding_w(t_info *flag, int fill_w)
{
	char					char_fill;

	if ((*flag).zero == 1 && (*flag).prec_no_val == 0)
		char_fill = '0';
	else
		char_fill = ' ';
	while (fill_w > 0)
	{
		if (char_fill == ' ')
			(*flag).space = 0;
		ft_putchar_fd(char_fill, (*flag).fd);
		(*flag).count++;
		fill_w--;
	}
}

void		put_padding_p(t_info *flag, int fill_p)
{
	char				char_fill;

	char_fill = '0';
	while (fill_p > 0)
	{
		ft_putchar_fd(char_fill, (*flag).fd);
		(*flag).count++;
		fill_p--;
	}
}
