/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/01 18:19:47 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an integer and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_d_i(char *s, va_list args, t_info flag, int x)
{
	long long int			i;
	int						length;

	i = va_arg(args, long long int);
	ft_putnbr(i);
	x++;
	return (x);
}

/*
	printf("\nminus: %d\nzero: %d\nplus: %d\nspace: %d\nhash: %d\nwidth: %d\nasterisk: %d\nprecision: %d\nprec_value: %d\nl: %d\nll: %d\nh: %d\nhh: %d\nl_cap: %d\n",\
	flag.minus, flag.zero, flag.plus, flag.space, flag.hash, flag.width,\
	flag.asterisk, flag.precision, flag.prec_value, flag.l, flag.ll, flag.h\
	flag.hh, flag.l_cap);
*/