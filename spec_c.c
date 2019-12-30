/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:47:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:23:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

int		spec_c(va_list args, t_info *flag, int x)
{
	int	c;
	int fill;

	c = va_arg(args, int);
	fill = (*flag).width - 1;
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	ft_putchar_fd((char)c, (*flag).fd);
	(*flag).count++;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	x++;
	return (x);
}
