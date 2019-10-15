/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_b1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/14 11:43:46 by rsteigen      ########   odam.nl         */
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

static long long	bin_zero_check(long long bin, t_info *flag)
{
	if (bin == 0 || bin == (float)0.0)
	{
		ft_putnbr(0);
		(*flag).count++;
	}
	return (bin);
}

static long long	bin_neg_check(long long bin, t_info *flag)
{
	if (bin < 0)
	{
		bin = bin * -1;
		(*flag).neg = 1;
	}
	return (bin);
}

static int			if_remain_is_zero(int remain, long long *bin_bits, int i)
{
	if (remain == 0)
	{
		i--;
		while (i >= 0)
		{
			bin_bits[i] = 0;
			i--;
		}
	}
	return (i);
}

int					spec_b(char *s, va_list args, t_info *flag, int x)
{
	long long	bin;
	long long	bin_bits[64];
	char		*bin_str;
	int			i;
	int			j;

	bin = va_arg(args, long long);
	if (bin_zero_check(bin, flag) == 0)
		return (x + 1);
	bin = bin_neg_check(bin, flag);
	bin_filler(bin_bits);
	i = 0;
	while (bin_bits[i] <= bin)
		i++;
	j = i - 1;
	bin = bin - bin_bits[j];
	i = if_remain_is_zero(bin, bin_bits, i);
	bin_bits[j] = 1;
	i = i - 2;
	bin_bits_calcu(bin_bits, i, bin);
	bin_str = bin_str_cpy(bin_bits, j, (*flag).neg);
	print_binary(flag, s);
	free(bin_str);
	return (x + 1);
}
