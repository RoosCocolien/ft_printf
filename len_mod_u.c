/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_u.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:53:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 16:55:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	hh	-->	unsigned char		0 - 255
**	h	-->	unsigned short		0 - 65.535
**	l	--> unsigned long		0 - 4.294.967.295
**	ll	-->	unsigned long long	0 - 18.446.744.073.709.551.615
*/

static unsigned long long	check_char_uns(va_list args)
{
	unsigned char			uns_char;
	unsigned long long		num;

	uns_char = (unsigned char)va_arg(args, int);
	num = (unsigned long long)uns_char;
	return (num);
}

static unsigned long long	check_short_uns(va_list args)
{
	unsigned short			uns_short;
	unsigned long long		num;

	uns_short = (unsigned short)va_arg(args, int);
	num = (unsigned long long)uns_short;
	return (num);
}

static unsigned long long	check_long_uns(va_list args)
{
	unsigned long			uns_long;
	unsigned long long		num;

	uns_long = (unsigned long)va_arg(args, long);
	num = (unsigned long long)uns_long;
	return (num);
}

static unsigned long long	check_longlong_uns(va_list args)
{
	unsigned long long		uns_longlong;
	unsigned long long		num;

	uns_longlong = (unsigned long long)va_arg(args, long long);
	num = (unsigned long long)uns_longlong;
	return (num);
}

static intmax_t	check_intmax_t(va_list args)
{
	intmax_t		num;

	num = va_arg(args, intmax_t);
	return (num);
}

intmax_t			len_mod_check_u(va_list args, t_info *flag, char conv_spec)
{
	intmax_t		i;

	if (conv_spec == 'p')
		i = check_intmax_t(args);
	else if ((*flag).hh == 1)
		i = check_char_uns(args);
	else if ((*flag).h == 1)
		i = check_short_uns(args);
	else if ((*flag).l == 1)
		i = check_long_uns(args);
	else if ((*flag).ll == 1)
		i = check_longlong_uns(args);
	else
		i = check_u(args, conv_spec);
	return (i);
}
