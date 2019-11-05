/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_e.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 16:11:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 11:05:31 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** (*flag).prec_value	--> amount of decimals
** (*flag).neg			--> 1 (neg), 0 (pos)
** ATTENTION: 'long double i' is always neg (check (*flag).neg)
*/

/*
** This functions finds:
** - power
** - first nb before '.'
** - '+' or '-' (0 - 1)
*/

long double			find_power(long double i, t_info *flag)
{
	if (i < 1 && i > 0)
	{
		while (i < 1)
		{
			i = i * 10;
			(*flag).power++;
		}
		(*flag).power_not = '-';
	}
	else
	{
		while (i >= 10)
		{
			i = i / 10;
			(*flag).power++;
		}
		(*flag).power_not = '+';
	}
	return (i);
}

static char			*ret_str_maker(t_info *flag, char e_not)
{
	char	*ret_str;
	int		i;

	i = 0;
	ret_str = (char*)malloc(sizeof(char) * (6 + (*flag).prec_value)\
	- (*flag).no_decimals);
	ret_str[6 + (*flag).prec_value - (*flag).no_decimals] = '\0';
	while (i < 6 + (*flag).prec_value - (*flag).no_decimals)
	{
		ret_str[i] = '0';
		i++;
	}
	if ((*flag).no_decimals == 0)
		ret_str[1] = '.';
	ret_str[2 + (*flag).prec_value - (*flag).no_decimals] = e_not;
	ret_str[3 + (*flag).prec_value - (*flag).no_decimals] = (*flag).power_not;
	if ((*flag).power >= 10)
	{
		ret_str[4 + (*flag).prec_value -\
		(*flag).no_decimals] = ((*flag).power / 10) + 48;
		ret_str[5 + (*flag).prec_value -\
		(*flag).no_decimals] = ((*flag).power % 10) + 48;
	}
	else
	{
		ret_str[4 + (*flag).prec_value -\
		(*flag).no_decimals] = '0';
		ret_str[5 + (*flag).prec_value -\
		(*flag).no_decimals] = (*flag).power + 48;
	}
	return (ret_str);
}

static int			calc_new_i_int(t_info *flag, long double i)
{
	int		decimals;
	int		multiplier;

	multiplier = 1;
	decimals = (*flag).prec_value;
	while (decimals > 0)
	{
		multiplier = multiplier * 10;
		decimals--;
	}
	i = (double)i * multiplier;
	return (i);
}

char				*make_str_e(long double i, t_info *flag, char e_not)
{
	char	*ret_str;
	int		new_i_int;
	char	*new_i_str;
	int		x;

	x = 0;
	i = find_power(i, flag);
	i = roundup_e(i, flag, (*flag).prec_value);
	new_i_int = calc_new_i_int(flag, i);
	ret_str = ret_str_maker(flag, e_not);
	new_i_str = ft_itoa_llu(new_i_int);
	while (new_i_str[x] && x <= (*flag).prec_value)
	{
		if (x > 0)
			ret_str[x + 1] = new_i_str[x];
		else
			ret_str[x] = new_i_str[x];
		x++;
	}
	if (new_i_str)
		free(new_i_str);
	return (ret_str);
}
