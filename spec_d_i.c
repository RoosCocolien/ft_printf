/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			spec_d_i(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long		i;
	t_padding				padding;
	int						length_new;

	set_padding_to_zero(&padding);
	prec_and_zero_check(args, flag, s[x]);
	if ((*flag).precision != 0)
		(*flag).zero = 0;
	i = len_mod_check_di(args, flag);
	padding.length = check_length_zero_int(i, flag);
	padding.fill_p = fill_precision(flag, padding.length);
	length_new = padding.length + padding.fill_p + (*flag).neg;
	padding.fill_w = fill_width(flag, s[x], length_new);
	check_flag_plus_space(flag, &padding, (*flag).minus);
	check_print_neg(flag, &padding, 1);
	if ((*flag).minus == 0 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	check_print_neg(flag, &padding, 2);
	put_padding_p(flag, padding.fill_p);
	check_print_neg(flag, &padding, 3);
	print_digit(flag, i, padding.length);
	if ((*flag).minus == 1 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	x++;
	return (x);
}
