/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/27 14:25:36 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	If a '*' comes after a '.' then the prec_value will be computed
**	from the next arg (which must be an int).
**	The (*flag).precision will be set to 2.
*/

int		check_precision(char *s, t_info *flag, int x)
{
	char	*value_precision;
	int		i;

	if (s[x + 1] == '*')
	{
		//asterisk flag hoeft niet aan, die gaat alleen aan als het voor de width is
		(*flag).precision = 2;
		x = x + 2; //+2 want we moeten '*' ook overslaan
	}
	else
	{
		(*flag).precision = 1;
		x++;
		//onderstaand stukje code is precies hetzelfde als bij width
		i = x;
		while (s[x] >= 48 && s[x] <= 57)
			x++;
		value_precision = ft_strsub(s, i, x - i);
		(*flag).prec_value = ft_atoi(value_precision);
	}
	return (x);
}

void		set_zero_flags(t_info *flag)
{
	(*flag).minus = 0;
	(*flag).zero = 0;
	(*flag).plus = 0;
	(*flag).space = 0;
	(*flag).hash = 0;
	(*flag).width = 0;
	(*flag).asterisk = 0;
	(*flag).precision = 0;
	(*flag).prec_value = 0;
	(*flag).l = 0;
	(*flag).ll = 0;
	(*flag).h = 0;
	(*flag).hh = 0;
	(*flag).l_cap = 0;
	(*flag).neg = 0;
}