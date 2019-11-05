/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   roundup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 15:03:48 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 14:11:08 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned long long	ten_to_the_power_of(int power)
{
	unsigned long long i;

	i = 1;
	while (power > 0)
	{
		i *= 10;
		power--;
	}
	return (i);
}

static long double	get_decimals(long double i, int prec)
{
	long double			one;

	i = i - ((int)i);
	while (i >= 0.99)
		i--;
	return (i);
}

long double			roundup_e(long double i, t_info *flag, int prec)
{
	long double			j;
	int					begin;
	long double			decimals;

	j = i * ten_to_the_power_of(prec);
	decimals = get_decimals(j, prec);
	if (decimals >= 0.5)
		i = ((j + 1) / ten_to_the_power_of(prec));
	begin = (int)i;
	if ((begin == 9 && i < 2) || i >= 10)
		(*flag).power++;
	return (i);
}

long double			roundup_f(long double i, int prec)
{
	long double			j;
	char				*str;
	int					len;

	j = i * ten_to_the_power_of(prec + 1);
	str = ft_itoa_llu(j);
	len = ft_strlen(str);
	if (str[len - 1] >= '5')
		i = ((j / 10 + 1) / ten_to_the_power_of(prec));
	free(str);
	return (i);
}
