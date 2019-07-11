/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:23:54 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/08 12:42:49 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	(*flag).count opplussen bij elke print
*/
void	print_digit(t_info *flag, unsigned long long nb)
{
	char	*str_digit;
	int		i;

	str_digit = ft_itoa_llu(nb);
	i = 0;
	while (str_digit[i])
	{
		ft_putchar(str_digit[i]);
		(*flag).count++;
		i++;
	}
}

/*
void	print_flags(t_info flag)
{
	printf("Value flag.minus: %d\n", flag.minus);
	printf("Value flag.zero: %d\n", flag.zero);
	printf("Value flag.plus: %d\n", flag.plus);
	printf("Value flag.space: %d\n", flag.space);
	printf("Value flag.hash: %d\n", flag.hash);
	printf("Value flag.width: %d\n", flag.width);
	printf("Value flag.asterisk: %d\n", flag.asterisk);
	printf("Value flag.precision: %d\n", flag.precision);
	printf("Value flag.prec_value: %d\n", flag.prec_value);
	printf("Value flag.l: %d\n", flag.l);
	printf("Value flag.ll: %d\n", flag.ll);
	printf("Value flag.h: %d\n", flag.h);
	printf("Value flag.hh: %d\n", flag.hh);
	printf("Value flag.l_cap: %d\n", flag.l_cap);
	printf("Value flag.neg: %d\n", flag.neg);
}
*/
