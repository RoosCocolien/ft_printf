/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:58 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/26 14:29:26 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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
	fill_w = fill_width(flag, s[x], length + fill_p + (*flag).neg);
	if ((*flag).minus == 0 && fill_w > 0)
	{
		// printf("check padding w1\n");
		put_padding_w(flag, fill_w);
	}
	put_padding_p(flag, fill_p);
	print_digit(flag, i, length);
	if ((*flag).minus == 1 && fill_w > 0)
		put_padding_w(flag, fill_w);
	return (x + 1);
}

// int		spec_u(char *s, va_list args, t_info *flag, int x)
// {
// 	unsigned long long	i;
// 	int					length;
// 	int					fill;

// 	fill = 0;
// 	(*flag).plus = 0;
// 	prec_and_zero_check(args, flag, s[x]);
// 	i = len_mod_check_u(args, flag, s[x]);
// //	check_asterisk(flag, s[x]); dit doe ik in prec_and_zero_check
// 	length = check_length_zero_int(i, flag);
// 	fill = fill_width_prec(flag, length);
// 	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
// 		put_padding(flag, fill);
// 	print_digit(flag, i, length);
// 	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
// 		put_padding(flag, fill);
// 	return (x + 1);
// }
