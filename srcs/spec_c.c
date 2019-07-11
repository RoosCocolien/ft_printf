/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:47:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 15:28:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an character and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_c(char *s, va_list args, t_info *flag, int x)
{
	int	c;
	int fill;

	c = va_arg(args, int);
	fill = (*flag).width - 1;
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, (*flag).zero, fill, 0);
	ft_putchar((char)c);
	(*flag).count++;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, (*flag).zero, fill, 0);
	x++;
	return (x);
}
