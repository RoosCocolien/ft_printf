/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_b2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/25 15:55:14 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a double in normalized scientific notation
** and consider the used flags.
** print: 					OK
** consideration of flags:	NO
**
** DOESN'T WORK WITH:
** -
*/

void			bin_bits_filler(long long *arr, int len)
{
	int			i;

	i = 0;
	while (i <= 3)
	{
		ft_putnbr(arr[i]);
		i++;
	}
}

void			bin_filler(long long *bin_bits)
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	while (i <= 64)
	{
		bin_bits[i] = j;
		j = j * 2;
		i++;
	}
}

void			bin_bits_calcu(long long *bin_bits, int i, int remain)
{
	while (i >= 0)
	{
		if (bin_bits[i] > remain)
			bin_bits[i] = 0;
		else
		{
			remain = remain - bin_bits[i];
			bin_bits[i] = 1;
		}
		i--;
	}
}

char			*bin_str_cpy(long long *bin_bits, int j, int min)
{
	int			i;
	char		*bin_str;

	bin_str = (char*)malloc(j + min + 1);
	i = min;
	bin_str[j + min + 1] = '\0';
	if (min == 1)
		bin_str[0] = '-';
	while (j >= 0)
	{
		bin_str[i] = bin_bits[j] + 48;
		j--;
		i++;
	}
	return (bin_str);
}
