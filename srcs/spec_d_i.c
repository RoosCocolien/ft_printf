/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/10 18:08:03 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_d_i(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long		i;
	int						length;
	int						fill;

	fill = 0;
	prec_and_zero_check(args, flag, s[x]);
	if ((*flag).zero == 1 && (*flag).minus == 1)
		(*flag).zero = 0;
	i = len_mod_check_di(args, flag);
	length = ft_intlength(i);
	fill = fill_width_prec(flag, length);
	if ((*flag).neg == 1 && (*flag).precision == 0)
		fill--;
	if ((*flag).plus == 1)
		fill = check_flag_plus(flag, fill, (*flag).minus);
	if ((*flag).space == 1)
		fill = check_flag_space(flag, fill, (*flag).minus);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill, s[x]);
	print_neg(flag);
	print_digit(flag, i);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill, s[x]);
	x++;
	return (x);
}
