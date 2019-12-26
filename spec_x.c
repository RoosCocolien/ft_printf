/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:37:53 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/26 14:27:23 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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
	// int			length;
	t_padding	padding;
	char		*hex_str;

	padding.fill_p = 0;
	padding.fill_w = 0;
	padding.length = 0;
	prec_and_zero_check(args, flag, s[x]);
	check_hash_zero(flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	// printf("width: %d\n", (*flag).width);
	// printf("pv: %d\n", (*flag).prec_value);
	hex_str = make_hex_str(i, flag, s[x], &padding);
	// printf("hex_str: %s\n", hex_str);
	// length = check_length_zero(i, hex_str, flag);
	// padding.fill_p = fill_precision(flag, length);
	padding.fill_w = fill_width(flag, s[x], padding.length + padding.fill_p + (*flag).neg);
	// printf("fill_w: %d\n", padding.fill_w);
	// printf("fill_p: %d\n", padding.fill_p);
	if ((*flag).minus == 0 && padding.fill_w > 0)
	{
		// printf("check padding w1\n");
		put_padding_w(flag, padding.fill_w);
	}
	if (s[x] != 'p' && (*flag).hash != 1)
		put_padding_p(flag, padding.fill_p);
	print_address(flag, hex_str, padding.length);
	if ((*flag).minus == 1 && padding.fill_w > 0)
		put_padding_w(flag, padding.fill_w);
	if (hex_str)
		free(hex_str);
	return (x + 1);
}

// int			spec_x(char *s, va_list args, t_info *flag, int x)
// {
// 	intmax_t	i;
// 	int			length;
// 	int			fill_w;
// 	char		*hex_str;

// 	fill_w = 0;
// 	prec_and_zero_check(args, flag, s[x]);
// 	check_hash_zero(flag, s[x]);
// 	i = len_mod_check_u(args, flag, s[x]);
// 	hex_str = make_hex_str(i, flag, s[x]);
// 	// printf("hex_str: %s\n", hex_str);
// 	length = check_length_zero(i, hex_str, flag);
// 	fill_w = (*flag).width - length;
// 	// printf("fill_w: %d\n", fill_w);
// 	if (fill_w > 0 && (*flag).minus == 0)
// 		put_padding(flag, fill_w);
// 	print_address(flag, hex_str, length);
// 	if (fill_w > 0 && (*flag).minus != 0)
// 		put_padding(flag, fill_w);
// 	free(hex_str);
// 	return (x + 1);
// }
