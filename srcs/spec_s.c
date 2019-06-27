/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/19 14:43:27 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an null-terminated string and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_s(char *s, va_list args, t_info flag, int x)
{
	char *str;

	str = va_arg(args, char*);
	ft_putstr(str);
	x++;
	return (x);
}
