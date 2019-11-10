/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_perc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:45 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/10 15:24:21 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_perc(char *s, va_list args, t_info *flag, int x)
{
	ft_putchar('%');
	(*flag).count++;
	x++;
	return (x);
}
