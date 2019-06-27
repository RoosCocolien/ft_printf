/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 13:38:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/27 16:24:47 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	wat gebeurt er als er meerdere length modifiers aan staan?
*/

static char		check_char(va_list args, t_info *flag)
{
	char				num_char;
	unsigned long long	num;

	num_char = (char)va_arg(args, int);
	if (num_char < 0)
	{
		(*flag).neg = 1;
		num = (unsigned long long)-num_char;
	}
	else
		num = (unsigned long long)num_char;
	return (num);
}

static short int	check_short(va_list args, t_info *flag)
{
	short int			num_short;
	unsigned long long	num;

	num_short = (short int)va_arg(args, int);
	if (num_short < 0)
	{
		(*flag).neg = 1;
		num = (unsigned long long)-num_short;
	}
	else
		num = (unsigned long long)num_short;
	return (num);
}

static long int	check_long(va_list args, t_info *flag)
{
	long int			num_long;
	unsigned long long	num;

	num_long = (long int)va_arg(args, int);
	if (num_long < 0)
	{
		(*flag).neg = 1;
		num = (unsigned long long)-num_long;
	}
	else
		num = (unsigned long long)num_long;
	return (num);
}

static long long int		check_longlong(va_list args, t_info *flag)
{
	long long int		num_longlong;
	unsigned long long	num;

	num_longlong = (long long int)va_arg(args, int);
	if (num_longlong < 0)
	{
		(*flag).neg = 1;
		num = (unsigned long long)-num_longlong;
	}
	else
		num = (unsigned long long)num_longlong;
	return (num);
}

unsigned long long int		len_mod_check(va_list args, t_info *flag)
{
	unsigned long long int	i;

	if (flag.precision == 2)
		flag.width = va_args(args, int);
	if ((*flag).hh == 1)
		i = check_char(args, &(*flag));
	else if ((*flag).h == 1)
		i = check_short(args, &(*flag));
	else if ((*flag).l == 1)
		i = check_long(args, &(*flag));
	else if ((*flag).ll == 1)
		i = check_longlong(args, &(*flag));
	else
		i = check_int(args, &(*flag));
	return (i);
}
