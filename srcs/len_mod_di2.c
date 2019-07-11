/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_di2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/27 16:02:08 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/08 17:08:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned long long		check_int(va_list args, t_info *flag)
{
	int					num_int;
	unsigned long long	i;

	num_int = va_arg(args, int);
	if (num_int < 0)
	{
		(*flag).neg = 1;
		i = -(unsigned long long)num_int;
	}
	else
		i = (unsigned long long)num_int;
	return (i);
}
