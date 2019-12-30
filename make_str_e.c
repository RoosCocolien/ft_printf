/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_e.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/20 16:11:04 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/29 16:45:51 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

long double					find_power(long double i, t_info *flag)
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

static char					*fill_ret_str(t_info *flag, char not,\
							int mal_size, int i)
{
	char	*ret_str;

	ret_str = (char*)malloc(sizeof(char) * 5 + mal_size + 1);
	ret_str[5 + mal_size] = '\0';
	while (i < 5 + mal_size)
	{
		ret_str[i] = '0';
		i++;
	}
	if ((*flag).no_decimals == 0 || (*flag).dot == 1)
		ret_str[1] = '.';
	ret_str[1 + mal_size] = not;
	ret_str[2 + mal_size] = (*flag).power_not;
	if ((*flag).power >= 10)
	{
		ret_str[3 + mal_size] = ((*flag).power / 10) + 48;
		ret_str[4 + mal_size] = ((*flag).power % 10) + 48;
	}
	else
	{
		ret_str[3 + mal_size] = '0';
		ret_str[4 + mal_size] = (*flag).power + 48;
	}
	return (ret_str);
}

static char					*ret_str_maker(t_info *flag, char e_not)
{
	char	*ret_str;
	int		malloc_size;

	malloc_size = (*flag).prec_value + (*flag).dot;
	ret_str = fill_ret_str(flag, e_not, malloc_size, 0);
	return (ret_str);
}

static unsigned long long	calc_spec_e(t_info *flag, long double i)
{
	int		precision;
	int		multiplier;

	multiplier = 1;
	precision = (*flag).prec_value;
	while (precision > 0)
	{
		multiplier = multiplier * 10.0;
		precision--;
	}
	i = (double)i * multiplier;
	return (i);
}

char						*make_str_e(long double i, t_info *flag, char e_not)
{
	char	*ret_str;
	int		new_i_int;
	char	*new_i_str;
	int		x;

	x = 0;
	i = find_power(i, flag);
	i = roundup_e(i, flag, (*flag).prec_value);
	new_i_int = calc_spec_e(flag, i);
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
