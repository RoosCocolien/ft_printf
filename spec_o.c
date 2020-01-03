/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/31 12:54:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		spec_o(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	t_padding			padding;
	char				*oct_str;

	set_padding_to_zero(&padding);
	(*flag).plus = 0;
	if ((*flag).precision != 0)
		(*flag).zero = 0;
	prec_and_zero_check(args, flag, s[x]);
	check_asterisk(flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	oct_str = make_oct_str(i, flag, &padding);
	padding.length = check_length_zero(i, oct_str, flag);
	if ((*flag).hash == 1 && padding.length == 0)
		padding.length = 1;
	padding.fill_w = fill_width(flag, s[x], padding.length);
	if ((*flag).minus == 0 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	print_string(flag, oct_str, padding.length);
	if ((*flag).minus == 1 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	if (oct_str)
		free(oct_str);
	return (x + 1);
}
