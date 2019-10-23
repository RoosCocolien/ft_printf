/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_g.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 15:57:54 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/23 18:16:19 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a double in normalized scientific notation
** and consider the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_g(char *s, va_list args, t_info *flag, int x)
{
	long double		i;
	char			*str_spec_g;
	int				length;
	int				fill;

	fill = 0;
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_efg(args, flag);
	str_spec_g = make_str_g(i, flag);
	length = ft_strlen(str_spec_g);
	fill = change_fill(flag, fill, length);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	if ((*flag).neg == 1 && (*flag).zero != 1)
	{
		ft_putchar('-');
		(*flag).count++;
	}
	print_string(flag, str_spec_g, fill);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(str_spec_g);
	return (x + 1);
}
