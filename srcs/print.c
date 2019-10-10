/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:23:54 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/10 18:03:20 by rsteigen      ########   odam.nl         */
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
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		ft_putchar('+');
		(*flag).count++;
	}
	while (str_digit[i])
	{
		ft_putchar(str_digit[i]);
		(*flag).count++;
		i++;
	}
	free(str_digit);
}

void	print_address(t_info *flag, char *s)
{
	int		i;

	i = 0;
//	ft_putstr("0x");	verplaatst ivm padding
//	(*flag).count = (*flag).count + 2;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		(*flag).count++;
		ft_putchar('+');
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		(*flag).count++;
		i++;
	}
	while ((*flag).leftover != 0)
	{
		ft_putchar('0');
		(*flag).leftover--;
		(*flag).count++;
	}
}

void	print_string(t_info *flag, char *s)
{
	int		i;

	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		(*flag).count++;
		ft_putchar('+');
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		(*flag).count++;
		i++;
	}
	while ((*flag).leftover != 0)
	{
		ft_putchar('0');
		(*flag).leftover--;
		(*flag).count++;
	}
}

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
