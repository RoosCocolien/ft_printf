/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_e.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:36:17 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		spec_e(char *s, va_list args, t_info *flag, int x)
{
	long double		i;
	char			*str_spec_e;
	t_padding		padding;
	int				extra_padding;

	set_padding_to_zero(&padding);
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_efg(args, flag);
	extra_padding = calc_extra_padding(flag);
	str_spec_e = make_str_e(i, flag, s[x]);
	padding.length = ft_strlen(str_spec_e);
	padding.fill_w = fill_width(flag, s[x], padding.length + extra_padding);
	put_space_plus_e(flag, &padding);
	if ((*flag).minus == 0 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	if (padding.length == 0 && i == 0)
		padding.length = ft_strlen(str_spec_e);
	print_neg(flag, padding.length, s[x]);
	print_string(flag, str_spec_e, padding.length);
	if ((*flag).minus == 1 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	if (str_spec_e)
		free(str_spec_e);
	return (x + 1);
}
