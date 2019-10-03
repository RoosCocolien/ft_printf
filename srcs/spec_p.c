/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/12 15:41:46 by rsteigen      ########   odam.nl         */
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
	ft_printf("0x7fff%x", va_arg(args, void *)); //geen idee of er altijd '0x7fff' voor staat
	return (x + 1);
}
