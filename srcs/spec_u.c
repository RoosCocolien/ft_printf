/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:58 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/19 14:44:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a decimal unsigned int and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_u(char *s, va_list args, t_info flag, int x)
{
	long long int i;
	i = va_arg(args, int);
	if (i < 0)
		ft_putstr("random undefined behaviour");
	else 
		ft_putnbr(i);
	return (x + 1);
}
