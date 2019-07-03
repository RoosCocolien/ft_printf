/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:47:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/01 18:27:28 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an character and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_c(char *s, va_list args, t_info flag, int x)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar((char)c);
	x++;
	return (x);
}
