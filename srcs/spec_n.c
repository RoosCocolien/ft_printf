/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_n.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 19:31:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print nothing, will read the argument and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_n(char *s, va_list args, t_info *flag, int x)
{
	void *n;

	n = va_arg(args, void *);
	return (x + 1);
}
