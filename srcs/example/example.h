/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 16:24:34 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/03 16:48:09 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../libft/includes/libft.h"

/*
**	by default it is set to '0' which means that it's off
**	otherwise it will be set to '1', which means it's on
*/
typedef struct s_info
{
	char minus;			//'-' -> left align
	char zero;			//'0' --> fill zero
	char plus;			//'+' --> plus sign
	char space;			//' ' --> align neg pos numbers
	int width;			//'6' (example)
}				t_info;


#endif