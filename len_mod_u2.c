/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_u2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 13:09:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

unsigned long long		check_u(va_list args, char conv_spec)
{
	unsigned int		uns_int;
	unsigned long long	i;

	i = 0;
	uns_int = 0;
	if (conv_spec == 'u' || conv_spec == 'o' || conv_spec == 'x'\
	|| conv_spec == 'X')
	{
		uns_int = va_arg(args, unsigned int);
		i = (unsigned long long)uns_int;
	}
	return (i);
}

intmax_t				check_intmax_t(va_list args)
{
	intmax_t			num;

	num = va_arg(args, intmax_t);
	return (num);
}
