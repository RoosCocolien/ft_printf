/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:52:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		find_spec_2(char *s, va_list args, t_info *flag, int x)
{
	if (s[x] == 'o')
		x = spec_o(s, args, flag, x);
	else if (s[x] == 'x' || s[x] == 'X')
		x = spec_x(s, args, flag, x);
	else if (s[x] == 'u')
		x = spec_u(s, args, flag, x);
	else if (s[x] == 'p')
		x = spec_p(s, args, flag, x);
	else
		return (x);
	return (x);
}

int		find_spec(char *s, va_list args, t_info *flag, int x)
{
	if (s[x] == 'd' || s[x] == 'i')
		x = spec_d_i(s, args, flag, x);
	else if (s[x] == 'f')
	{
		if ((*flag).hash == 1)
			(*flag).dot = 1;
		x = spec_f(s, args, flag, x);
	}
	else if (s[x] == 'c')
		x = spec_c(args, flag, x);
	else if (s[x] == 's')
		x = spec_s(args, flag, x);
	else if (s[x] == '%')
		x = spec_perc(flag, x);
	else if (s[x] == 'e' || s[x] == 'E')
	{
		if ((*flag).hash == 1)
			(*flag).dot = 1;
		x = spec_e(s, args, flag, x);
	}
	else
		x = find_spec_2(s, args, flag, x);
	return (x);
}
