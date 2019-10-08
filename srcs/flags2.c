/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/02 17:43:42 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

//check visible plus sign
//plus and minus or invisible plus is part of length!!
//--> flag.width--
//check neg or pos
//put a space first? how does that work?

//print plus sign on positive numbers
int		check_flag_plus(t_info *flag, int fill, int left_align)
{
	//first if: to let '+' be counted as well in the fill
	if ((*flag).precision == 0 && (*flag).neg == 0)
		fill--;
	if ((*flag).neg == 0 && (((*flag).precision != 0 || left_align == 1) ||
	(*flag).zero == 1))
	{
		ft_putchar('+');
		(*flag).count++;
	}
	return (fill);
}

//invisible plus sign
int		check_flag_space(t_info *flag, int fill, int left_align)
{
	//first if: to let ' ' be counted as well in the fill
	if ((*flag).precision == 0 && (*flag).neg == 0)
		fill--;
	if ((*flag).neg == 0 && (((*flag).precision != 0 || left_align == 1) ||\
	(*flag).zero == 1))
	{
		ft_putchar(' ');
		(*flag).count++;
	}
	return (fill);
}

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

void		set_zero_flags(t_info *flag, int start_count)
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
	if (start_count == 0)
		(*flag).count = 0;
	(*flag).power = 0;
	(*flag).power_not = 0;
	(*flag).no_decimals = 0;
	(*flag).spec_g = 0;
	(*flag).dot = 0;
	(*flag).leftover = 0;
}
