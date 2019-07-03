/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/01 18:28:31 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an unsigned int in octal (base 8) and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_o(char *s, va_list args, t_info flag, int x)
{
	char *s1;

	s1 = ft_itoa_base(va_arg(args, int), 8);
	ft_putstr(s1);
	free(s1);
	return (x + 1);
}