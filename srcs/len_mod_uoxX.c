/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_uoxX.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:53:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/16 14:20:41 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	hh	-->	unsigned char		0 - 255
**	h	-->	unsigned short		0 - 65.535
**	l	--> unsigned long		0 - 4.294.967.295
**	ll	-->	unsigned long long	0 - 18.446.744.073.709.551.615
*/

static unsigned long long	check_char_uns(va_list args, t_info *flag)
{
	unsigned char			uns_char;
	unsigned long long		num;

	uns_char = (unsigned char)va_arg(args, int);
	num = (unsigned long long)uns_char;
	return (num);
}

static unsigned long long	check_short_uns(va_list args, t_info *flag)
{
	unsigned short		uns_short;
	unsigned long long	num;

	uns_short = (unsigned short)va_arg(args, int);
	num = (unsigned long long)uns_short;
	return (num);
}

static unsigned long long	check_long_uns(va_list args, t_info *flag)
{
	unsigned long		uns_long;
	unsigned long long	num;

	uns_long = (unsigned long)va_arg(args, long);
	num = (unsigned long long)uns_long;
	return (num);
}

static unsigned long long	check_longlong_uns(va_list args, t_info *flag)
{
	unsigned long long	uns_longlong;
	unsigned long long	num;

	uns_longlong = (unsigned long long)va_arg(args, long long);
	num = (unsigned long long)uns_longlong;
	return (num);
}

unsigned long long		len_mod_check_uoxX(va_list args, t_info *flag,\
char conv_spec)
{
	unsigned long long	i;

	if ((*flag).hh == 1)
		i = check_char_uns(args, flag);
	else if ((*flag).h == 1)
		i = check_short_uns(args, flag);
	else if ((*flag).l == 1)
		i = check_long_uns(args, flag);
	else if ((*flag).ll == 1)
		i = check_longlong_uns(args, flag);
	else
		i = check_uoxX(args, flag, conv_spec);
	return (i);
}
