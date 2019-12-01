/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_perc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:45 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/13 13:48:25 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_perc(char *s, va_list args, t_info *flag, int x)
{
	int fill;

	fill = (*flag).width - 1;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	ft_putchar('%');
	(*flag).count++;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	x++;
	return (x);
}
