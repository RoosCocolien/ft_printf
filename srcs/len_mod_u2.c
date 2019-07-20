/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   len_mod_uoxX2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 17:41:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 17:46:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

unsigned long long		check_uoxX(va_list args, t_info *flag, char conv_spec)
{
//	unsigned int (u)	
	unsigned int		uns_int;
//	octal int (o)
//	hexal int (x)
//	hexal int (X)
	unsigned long long	i;

	if (conv_spec == 'u')
	{
		uns_int = (unsigned int)va_arg(args, int);
		i = (unsigned long long)uns_int;
	}
	return (i);
}