/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/20 18:54:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an unsigned int in octal (base 8) and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

/*
** STEPS:
** flag.width of flag.precision opslaan
** dan len_mod_check(u)
** getal omzetten naar oct 8 (string)
** dan lengte checken (van de string)
** en consideration van andere flags
*/

int		spec_o(char *s, va_list args, t_info *flag, int x)
{
	long long			i;
	int					length;
	int					fill;
	char				*oct_str;

	fill = 0;
	if ((*flag).precision == 2)
		(*flag).width = va_arg(args, int);
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);
	i = len_mod_check_u(args, flag, s[x]);
	oct_str = ft_itoa_base_ll(i, 8, 0);
	length = ft_strlen(oct_str);
	//vanaf hier
	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	//tm hier is hetzelfde als spec_di && spec_u && spec_x
/*
	ft_putstr("Omgezette getal (na len_mod_check_u): \n");
	print_digit(flag, i);
	ft_putchar('\n');
	ft_putstr("Length oct_str: \n");
	ft_putnbr(length);
	ft_putchar('\n');
	ft_putstr("Octal getal: \n");
	ft_putstr(oct_str);
	ft_putchar('\n');
*/
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	ft_putstr(oct_str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(oct_str);
	return (x + 1);
}
