/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   roundup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 15:03:48 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

unsigned long long	ten_to_the_power_of(int power)
{
	unsigned long long	i;

	i = 1;
	while (power > 0)
	{
		i *= 10;
		power--;
	}
	return (i);
}

long double			get_decimals_roundup(long double i)
{
	i = i - ((unsigned long long)i);
	while (i >= 0.9999999 && i < 2)
		i--;
	if (i >= 2 || i < 0)
		i = 0;
	return (i);
}

long double			roundup_e(long double i, t_info *flag, int prec)
{
	long double			j;
	int					begin;
	long double			decimals;

	j = i * ten_to_the_power_of(prec);
	decimals = get_decimals_roundup(j);
	if (decimals >= 0.5)
		i = ((j + 1) / ten_to_the_power_of(prec));
	begin = (int)i;
	if ((begin == 9 && i < 2) || i >= 10)
		(*flag).power++;
	return (i);
}

long double			roundup_number_to_even(long double j, char *str,\
					long double decimals, int prec)
{
	int					even_odd;
	long double			nb;
	int					len;

	len = ft_strlen(str);
	even_odd = ((int)j / 10) % 10;
	if (even_odd % 2 != 0 || str[len - 1] > '5' ||\
	(str[len - 1] == '5' && decimals > 0.0F))
	{
		nb = ((j / 10 + 1) / ten_to_the_power_of(prec));
	}
	else
	{
		nb = ((j / 10) / ten_to_the_power_of(prec));
	}
	return (nb);
}

long double			roundup_f(long double i, int prec)
{
	long double			j;
	unsigned long long	before;
	char				*str;
	int					len;
	long double			decimals;

	before = (unsigned long long)i;
	if (i >= 10 && prec > 1)
		i = i - before;
	j = i * ten_to_the_power_of(prec + 1);
	decimals = get_decimals_roundup(j);
	str = ft_itoa_llu(j);
	len = ft_strlen(str);
	if (len > 1 && str[len - 1] >= '5')
	{
		i = roundup_number_to_even(j, str, decimals, prec);
	}
	if (i < before)
		i = before + i;
	free(str);
	return (i);
}
