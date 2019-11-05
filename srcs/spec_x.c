/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:49:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 15:34:34 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an unsigned int as a hexadecimal number and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_x(char *s, va_list args, t_info *flag, int x)
{
	intmax_t		i;
	int				length;
	int				fill;
	char			*hex_str;

	fill = 0;
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	if (s[x] == 'x' || s[x] == 'p')
		hex_str = ft_itoa_base_ll(i, 16, 0);
	else
		hex_str = ft_itoa_base_ll(i, 16, 1);
	length = ft_strlen(hex_str);
	if ((s[x] == 'p' || (*flag).hash) && (*flag).precision == 0)
		length += 2;
	//vanaf hier
	if ((*flag).precision != 0 && ((*flag).prec_value != 0 || (*flag).width != 0))
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	//tm hier is hetzelfde als spec_di && spec_u && spec_o
	if ((s[x] == 'p' || (*flag).hash == 1) && (*flag).zero != 0) //bepaald wanneer de '0x' wordt geprint
		(*flag).count = put_0x_spec_f((*flag).count, s[x]);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	if ((s[x] == 'p' || (*flag).hash == 1) && (*flag).zero == 0) //bepaald wanneer de 0x wordt geprint
		(*flag).count = put_0x_spec_f((*flag).count, s[x]);
	print_address(flag, hex_str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(hex_str);
	return (x + 1);
}
