/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:37:53 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:36:56 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static void	check_hash_zero(t_info *flag, char spec)
{
	if (((*flag).hash != 0 || spec == 'p') && (*flag).width != 0 &&\
	(*flag).precision == 0 && (*flag).zero != 0)
		(*flag).prec_value = (*flag).width;
	if ((*flag).precision != 0)
		(*flag).zero = 0;
}

int			spec_x(char *s, va_list args, t_info *flag, int x)
{
	intmax_t	i;
	t_padding	padding;
	char		*hex_str;

	padding.fill_p = 0;
	padding.fill_w = 0;
	padding.length = 0;
	prec_and_zero_check(args, flag, s[x]);
	check_hash_zero(flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	hex_str = make_hex_str(i, flag, s[x], &padding);
	padding.length = check_length_zero(i, hex_str, flag);
	padding.fill_w = fill_width(flag, s[x], padding.length + (*flag).neg);
	if ((*flag).minus == 0 && padding.fill_w > 0)
	{
		put_padding_w(flag, padding.fill_w);
	}
	if (s[x] == 'p' && padding.length == 0 && i == 0)
		padding.length = ft_strlen(hex_str);
	print_address(flag, hex_str, padding.length);
	if ((*flag).minus == 1 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	if (hex_str)
		free(hex_str);
	return (x + 1);
}
