/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_g.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 17:23:07 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/01 18:03:58 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*make_str_g(long double i, t_info *flag)
{
	char		*ret_str;
	long double	decimals;

	decimals = i - (int)i;
	if (decimals == 0)
		i = 0;
	if (i < (double)999999.50)
	{
		(*flag).spec_g = 1;
		ret_str = make_str_f(i, flag);
	}
	else
	{
		(*flag).spec_g = 1;
		ret_str = make_str_e(i, flag, 'e');
	}
	return (ret_str);
}
