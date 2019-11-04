/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:52:24 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/04 15:06:37 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		find_spec_2(/*char *s, va_list args, t_info flag, */int x)
{
/*	else if (s[x] == 'e')
		x = spec_e(s, args, flag, x);
	else if (s[x] == 'g')
		x = spec_g(s, args, flag, x);
	else if (s[x] == 'n')
		x = spec_n(s, args, flag, x);
	else if (s[x] == 'o')
		x = spec_o(s, args, flag, x);
	else if (s[x] == 'p')
		x = spec_p(s, args, flag, x);
	else if (s[x] == 'u')
		x = spec_u(s, args, flag, x);
	else if (s[x] == 'x')
		x = spec_x(s, args, flag, x);
	else
		return (-1);
*/	return (x);

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
		x = spec_c(s, args, flag, x);
	else if (s[x] == 's')
		x = spec_s(s, args, flag, x);
	else if (s[x] == '%')
		x = spec_perc(s, args, flag, x);
	else if (s[x] == 'e' || s[x] == 'E')
	{
		if ((*flag).hash == 1)
			(*flag).dot = 1;
		x = spec_e(s, args, flag, x);
	}
	else if (s[x] == 'o')
		x = spec_o(s, args, flag, x);
	else if (s[x] == 'x' || s[x] == 'X')
		x = spec_x(s, args, flag, x);
	else if (s[x] == 'b')
		x = spec_b(s, args, flag, x);
	else if (s[x] == 'u')
		x = spec_u(s, args, flag, x);
	else if (s[x] == 'p')
		x = spec_p(s, args, flag, x);
	else if (s[x] == 'n')
		x = spec_n(s, args, flag, x);
	else
		return (-1);
	return (x);
}
