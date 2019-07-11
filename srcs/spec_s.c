/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 15:32:22 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an null-terminated string and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

int		spec_s(char *s, va_list args, t_info *flag, int x)
{
	char	*str;
	int		fill;
	int		length;

	str = va_arg(args, char*);
	length = ft_strlen(str);
	fill = (*flag).width - length;
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, (*flag).zero, fill, 0);
	ft_putstr(str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, (*flag).zero, fill, 0);	
	x++;
	return (x);
}
