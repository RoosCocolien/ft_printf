/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_g.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:23:07 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/14 15:26:04 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*make_str_g(long double i, t_info *flag)
{
	char *ret_str;

	if (i < (double)999999.50)
	{
		//spec_f
		//default is 6 decimals
		(*flag).spec_g = 1;
		ret_str = make_str_f(i, flag);
	//	printf("goes in f\n");
	}
	else
	{
		//if precision is not given, set default to 5
		if ((*flag).precision == 0)
			(*flag).prec_value = 5;
		(*flag).spec_g = 1;
		ret_str = make_str_e(i, flag, 'e');
	}
	return (ret_str);
}
