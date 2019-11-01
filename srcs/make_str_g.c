/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_g.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:23:07 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/01 09:07:00 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

//im not using this, remove?
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
	double	exp;	//remove
	int		var_p;	//remove
	long double	decimals;

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
	//try out
	decimals = i - (int)i;
	printf("**Make str g\tdecimals: %Lf\n", decimals);
	if (decimals == 0)
	{
		printf("**Make str g\tdecimals == 0\n");
		i = 0;
	}
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
//		(*flag).prec_value -= 1;	//toegevoegd
		(*flag).spec_g = 1;
		ret_str = make_str_e(i, flag, 'e');
	}
	return (ret_str);
}
