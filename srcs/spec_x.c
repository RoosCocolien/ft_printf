/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:49:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/11 16:54:28 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an unsigned int as a hexadecimal number and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

/*
** STEPS: (same as with octal)
** flag.width of flag.precision opslaan
** dan len_mod_check(u)
** getal omzetten naar hex 16 (string)
** dan lengte checken (van string)
** en consideration of other flags
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
	if (s[x] == 'p' && (*flag).precision == 0)
		length += 2;
	printf("spec_x 4\tlength = %d\n", length);
	//vanaf hier
	if ((*flag).precision != 0 && (*flag).prec_value != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	//tm hier is hetzelfde als spec_di && spec_u && spec_o
	if (s[x] == 'p')
	{
		ft_putstr("0x");
		(*flag).count += 2;
	}
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	print_address(flag, hex_str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(hex_str);
	return (x + 1);
}

/*
int		spec_x(char *s, va_list args, t_info *flag, int x)
{
	char *s1;
	// int d;
	// d = va_arg(args, int);
	// if (d < 0)
	// {
	// 	d = -d;
	// 	ft_putchar('-');
	// }
	// i = (unsigned long long)d;

	if (s[x] == 'x')
	{
		s1 = ft_itoa_base(va_arg(args, int), 16);
		ft_putstr(s1);
	}
	else if (s[x] == 'X')
	{
		s1 = ft_itoa_base_cap(va_arg(args, int), 16);
		ft_putstr(s1);
	}
	free(s1);
	return (x + 1);
}
*/

//echte printf geeft undefined behaviour met een min getal