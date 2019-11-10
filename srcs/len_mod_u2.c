/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_u2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 17:41:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 17:46:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned long long		check_u(va_list args, t_info *flag, char conv_spec)
{
	unsigned int		uns_int;
	unsigned long long	i;

	if (conv_spec == 'u' || conv_spec == 'o' || conv_spec == 'x'\
	|| conv_spec == 'X')
	{
		uns_int = va_arg(args, unsigned int);
		i = (unsigned long long)uns_int;
	}
	return (i);
}
