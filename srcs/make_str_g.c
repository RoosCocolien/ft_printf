/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_g.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:23:07 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/16 14:35:10 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	get_var_p(t_info *flag)
{
	int		var_p;

	if ((*flag).precision != 0)
	{
		if ((*flag).prec_value != 0)
			var_p = (*flag).prec_value;
		else
			var_p = 1;
	}
	else
		var_p = 6;
	return (var_p);
}

char	*make_str_g(long double i, t_info *flag)
{
	char	*ret_str;
	double	exp;
	int		var_p;

	// var_p = get_var_p(flag);
	// exp = find_power(i, flag);
	// if (-4 <= exp && exp <= var_p)
	// {
	// 	(*flag).prec_value = var_p - (exp + 1);
	// }
	// else
	// {
	// 	(*flag).prec_value = var_p - 1;
	// }		
	if (i < (double)999999.50)
	{
		//spec_f
		//default is 6 decimals
		(*flag).spec_g = 1;
		ret_str = make_str_f(i, flag);
		// printf("goes in f\n");
	}
	else
	{
		//if precision is not given, set default to 5
		// if ((*flag).precision == 0)
			// (*flag).prec_value = 5;
		(*flag).spec_g = 1;
		ret_str = make_str_e(i, flag, 'e');
	}
	return (ret_str);
}
