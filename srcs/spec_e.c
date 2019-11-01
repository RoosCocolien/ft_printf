/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_e.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:36:17 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/01 14:57:15 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a double in normalized scientific notation
** and consider the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_e(char *s, va_list args, t_info *flag, int x)
{
	long double		i;
	char			*str_spec_e;
	int				length;
	int				fill;
	//fill is voor de width, opvullen met ' ' of '0'

//	if ((*flag).minus == 1)
//		(*flag).zero = 0;
	fill = 0;
	//sla de waardes op als precision aan staat
	prec_and_zero_check(args, flag, s[x]);
	//if 'L' and check if neg value, returned altijd een pos getal
	i = len_mod_check_efg(args, flag);
	str_spec_e = make_str_e(i, flag, s[x]);
	length = ft_strlen(str_spec_e);
	fill = change_fill(flag, fill, length);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	//neg?
	if ((*flag).neg == 1 && (*flag).zero != 1)
	{
		ft_putchar('-');
		(*flag).count++;
	}
	print_string(flag, str_spec_e, fill);
	//PADDING AAN HET EINDE? (only blank spaces)
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(str_spec_e);
	return (x + 1);
}
