/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:49:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/24 16:55:34 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an unsigned int as a hexadecimal number and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

static char	*get_hex_str(intmax_t i, char spec)
{
	char	*hex_str;

	if (spec == 'x' || spec == 'p')
		hex_str = ft_itoa_base_ll(i, 16, 0);
	else
		hex_str = ft_itoa_base_ll(i, 16, 1);
	return (hex_str);
}

int			spec_x(char *s, va_list args, t_info *flag, int x)
{
	intmax_t		i;
	int				length;
	int				fill;
	char			*hex_str;

	fill = 0;
	// printf("precision: %d\n", (*flag).precision);
	// printf("prec_value: %d\n", (*flag).prec_value);
	// printf("width: %d\n", (*flag).width);
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	hex_str = get_hex_str(i, s[x]);
	length = ft_strlen(hex_str);
	// printf("hex_Str = %s\n", hex_str);
	// printf("s[x]: %c\n", s[x]);
	// printf("length: %d\n", length);	
	if ((s[x] == 'p' /*&& (*flag).precision == 0*/) || (*flag).hash == 1)
		length += 2;
	// printf("length: %d\n", length);
	// printf("before zero: %d\n", (*flag).zero);
	fill = fill_width_prec(flag, length);
	if (i == 0)
		fill += 2;
	// printf("after zero: %d\n", (*flag).zero);
	// printf("zero: %d\n", (*flag).zero);
	if (s[x] == 'p' || ((*flag).hash == 1 && (*flag).zero != 0 && i != 0))
	{
		// printf("put_0x 1\n");
		(*flag).count = put_0x_spec_f((*flag).count, s[x]);
	}
	// printf("\nwidth: %d\n", (*flag).width);
	// printf("minus: %d\n", (*flag).minus);
	// printf("fill: %d\n", fill);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
	{
		// printf("put_padding 1\n");
		put_padding(flag, fill);
	}
	if ((s[x] == 'p' || (*flag).hash == 1) && (*flag).zero == 0 && i != 0)
	{
		// printf("put_0x 2\n");
		(*flag).count = put_0x_spec_f((*flag).count, s[x]);
	}
	print_address(flag, hex_str);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
	{
		// printf("put_padding 2\n");
		put_padding(flag, fill);
	}
	free(hex_str);
	return (x + 1);
}
