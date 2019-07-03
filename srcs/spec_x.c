/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:49:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/01 18:28:48 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print aunsigned int as a hexadecimal number and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_xX(char *s, va_list args, t_info flag, int x)
{
	char *s1;

	if (s[x] == 'x')
	{
		s1 = ft_itoa_base(va_arg(args, int), 16);
		ft_putstr(s1);
	}
	else if (s[x] == 'X')
	{
		s1 = ft_itoa_base_cap(va_arg(args, int), 16);
		ft_putstr(s1);
	}
	free(s1);
	return (x + 1);
}


//echte printf geeft undefined behaviour met een min getal