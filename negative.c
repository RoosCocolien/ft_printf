/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   negative.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 14:52:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		write_neg_count(t_info *flag)
{
	ft_putchar_fd('-', (*flag).fd);
	(*flag).count++;
}

void		print_neg(t_info *flag, int length, char spec)
{
	if ((*flag).neg == 1 && (*flag).zero != 1)
		write_neg_count(flag);
	if ((*flag).neg == 1 && (*flag).zero == 1 && length >= (*flag).prec_value\
	&& (spec == 'd' || spec == 'i'))
		write_neg_count(flag);
	if ((spec == 'e' || spec == 'E' || spec == 'f') &&\
	(*flag).neg == 0 && (*flag).zero == 0)
	{
		if ((*flag).space == 1 && (*flag).plus == 0 && spec != 'f')
		{
			ft_putchar_fd(' ', (*flag).fd);
			(*flag).count++;
		}
		if ((*flag).plus == 1 && (*flag).neg == 0 && (*flag).f_nan == 0)
		{
			put_plus_change_count(flag);
		}
	}
}

void		put_neg(t_info *flag)
{
	write_neg_count(flag);
	(*flag).neg = -1;
}

void		check_print_neg(t_info *flag, t_padding *padding, int nb)
{
	if (nb == 1)
	{
		if ((*padding).fill_w <= 0 || ((*padding).fill_w > 0 &&\
		(*flag).zero == 1))
		{
			put_neg_or_plus(flag);
		}
	}
	if (nb == 2)
	{
		if ((*flag).neg == 1 && (*padding).fill_p > 0)
			put_neg(flag);
		if ((*flag).neg == 0 && (*padding).fill_p > 0 && (*flag).neg == 0\
			&& (*flag).plus == 1)
			put_plus_change_count(flag);
	}
	if (nb == 3)
	{
		if ((*flag).neg == 1)
			put_neg(flag);
		if ((*flag).plus == 1 && (*flag).neg == 0)
			put_plus_change_count(flag);
	}
}

int			float_check_neg_zero(long double i)
{
	t_float	float_nb;
	int		neg;

	neg = 0;
	float_nb = (t_float)i;
	neg = float_nb.float_short[4] >> 15 & 1;
	return (neg);
}
