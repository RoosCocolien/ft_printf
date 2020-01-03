/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:58 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/31 12:54:17 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		spec_u(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	int					length;
	int					fill_w;
	int					fill_p;

	(*flag).plus = 0;
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	length = check_length_zero_int(i, flag);
	fill_p = fill_precision(flag, length);
	if ((*flag).precision != 0)
		(*flag).zero = 0;
	fill_w = fill_width(flag, s[x], length + fill_p + (*flag).neg);
	if ((*flag).minus == 0 && fill_w > 0)
	{
		put_padding_w(flag, fill_w);
	}
	put_padding_p(flag, fill_p);
	print_digit(flag, i, length);
	if ((*flag).minus == 1 && fill_w > 0)
		put_padding_w(flag, fill_w);
	return (x + 1);
}
