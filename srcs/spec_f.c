/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_f.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 18:15:44 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/27 13:17:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an double and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_f(char *s, va_list args, t_info *flag, int x)
{
	long double		i;
	char			*str_spec_f;
	int				length;
	int				fill;

	fill = 0;
	//sla de waardes op als precision aan staat
	prec_and_zero_check(args, flag, s[x]);
	//if 'L' and check if neg value, returned altijd een pos getal
	i = len_mod_check_efg(args, flag);
	str_spec_f = make_str_f(i, flag);
	length = ft_strlen(str_spec_f);
	fill = change_fill(flag, fill, length);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	//neg?
	if ((*flag).neg == 1 && (*flag).zero != 1)
	{
		ft_putchar('-');
		(*flag).count++;
	}
	print_string(flag, str_spec_f, fill);
	//PADDING AAN HET EINDE? (only blank spaces)
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(str_spec_f);
	return (x + 1);
}
