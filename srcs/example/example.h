/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 16:24:34 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/29 16:13:51 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../libft/includes/libft.h"

typedef struct s_info
{
	char left_align;
	char fill_zero;
	char plus_sign;
	char inv_plus;
	int w;		//a number, this is the width
}				t_info;


#endif