/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   roundup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 15:03:48 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/19 13:50:14 by rsteigen      ########   odam.nl         */
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

static long double	get_decimals(long double i)
{
	i = i - ((int)i);
	while (i >= 0.999999)
		i--;
	return (i);
}

long double			roundup_e(long double i, t_info *flag, int prec)
{
	long double			j;
	int					begin;
	long double			decimals;

	j = i * ten_to_the_power_of(prec);
	decimals = get_decimals(j);
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
	int					even_odd;
	long double			decimals;

	even_odd = 0;
	j = i * ten_to_the_power_of(prec + 1);
	decimals = get_decimals(j);
	str = ft_itoa_llu(j);
	len = ft_strlen(str);
	if (len > 1 && str[len - 1] >= '5')
	{
		even_odd = ((int)j / 10) % 10;
		if (even_odd % 2 != 0 || str[len - 1] > '5' ||\
		(str[len - 1] == '5' && decimals > 0.0F))
			i = ((j / 10 + 1) / ten_to_the_power_of(prec));
	}
	free(str);
	return (i);
}
