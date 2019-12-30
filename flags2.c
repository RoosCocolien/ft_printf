/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 18:57:52 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static int	flags_part_five(char *s, t_info *flag, int x)
{
	if (s[x] == 'L')
	{
		(*flag).l_cap = 1;
		x++;
	}
	else if (s[x] == 'd' || s[x] == 'i' || s[x] == 'f' || s[x] == 'c'\
	|| s[x] == 's' || s[x] == '%' || s[x] == 'e' || s[x] == 'E'\
	|| s[x] == 'g' || s[x] == 'n' || s[x] == 'o' || s[x] == 'p'\
	|| s[x] == 'u' || s[x] == 'x')
		return (x);
	else
		return (x++);
	return (x);
}

int			flags_part_four(char *s, t_info *flag, int x)
{
	if (s[x] == 'l' && s[x - 1] == 'l')
	{
		(*flag).l = 0;
		(*flag).ll = 1;
		x++;
	}
	else if (s[x] == 'h' && s[x - 1] != 'h')
	{
		(*flag).hh = 0;
		(*flag).h = 1;
		x++;
	}
	else if (s[x] == 'h' && s[x - 1] == 'h')
	{
		(*flag).h = 0;
		(*flag).hh = 1;
		x++;
	}
	else
		x = flags_part_five(s, flag, x);
	return (x);
}

int			save_prec_width(char *s, t_info *flag, int x)
{
	char	*value_prec_width;
	int		i;

	i = x;
	while (s[x] >= 48 && s[x] <= 57)
		x++;
	value_prec_width = ft_strsub(s, i, x - i);
	if (s[i - 1] == '.')
		(*flag).prec_value = ft_atoi(value_prec_width);
	else
		(*flag).width = ft_atoi(value_prec_width);
	free(value_prec_width);
	return (x);
}

int			check_precision(char *s, t_info *flag, int x)
{
	if (s[x + 1] == '*')
	{
		(*flag).precision = 2;
		x = x + 2;
		if ((*flag).sequence == 0)
			(*flag).sequence++;
		else
			(*flag).sequence--;
	}
	else
	{
		(*flag).precision = 1;
		x++;
		x = save_prec_width(s, flag, x);
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
	(*flag).asterisk_s = 0;
	(*flag).precision = 0;
	(*flag).prec_value = 0;
	(*flag).prec_no_val = 0;
	(*flag).l = 0;
	(*flag).ll = 0;
	(*flag).h = 0;
	(*flag).hh = 0;
	(*flag).l_cap = 0;
	(*flag).neg = 0;
	(*flag).power = 0;
	(*flag).power_not = 0;
	(*flag).no_decimals = 0;
	(*flag).dot = 0;
	(*flag).leftover = 0;
	(*flag).f_nan = 0;
	(*flag).f_inf = 0;
	(*flag).sequence = 0;
}
