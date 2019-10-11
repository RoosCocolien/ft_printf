/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/11 13:07:17 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an void * (pointer to void) and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_p(char *s, va_list args, t_info *flag, int x)
{
//	(*flag).plus mag uitgezet worden
//	"0x" hoort bij de lengte van de string voor field width
//	ook bij precision
	(*flag).plus = 0;
	x = spec_x(s, args, flag, x) - 1;
	return (x + 1);
}
