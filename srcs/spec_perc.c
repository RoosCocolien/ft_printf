/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_perc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:45 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/19 14:43:03 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an '%' and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/
int		spec_perc(char *s, va_list args, t_info flag, int x)
{
	ft_putchar('%');
	x++;
	return (x);
}
