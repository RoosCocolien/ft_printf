/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/02 16:44:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_p(char *s, va_list args, t_info *flag, int x)
{
	(*flag).plus = 0;
	x = spec_x2(s, args, flag, x);
	return (x);
}
