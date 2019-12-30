/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 18:36:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/29 22:20:34 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static void					find_len_decimals(t_info *flag)
{
	(*flag).dot = 1;
	if ((*flag).precision != 0 && (*flag).prec_value == 0 && (*flag).hash != 0)
		(*flag).dot = 0;
	if ((*flag).precision == 0)
		(*flag).prec_value = 6;
}

static unsigned long long	find_precision(t_info *flag)
{
	unsigned long long	multiplier;
	int					x;

	multiplier = 1;
	x = (*flag).prec_value;
	if (x > 19)
	{
		(*flag).leftover = x - 18;
		return (1000000000000000000);
	}
	while (x > 0)
	{
		multiplier *= 10;
		x--;
	}
	return (multiplier);
}

char						*get_decimals(long double i, t_info *flag)
{
	char				*dec_str;
	int					len;
	unsigned long long	dec_int;
	unsigned long long	precision;
	int					x;

	x = 1;
	precision = find_precision(flag);
	dec_int = (i - (unsigned long long)i) * precision;
	len = 1 + (*flag).prec_value - (*flag).leftover;
	dec_str = ft_memalloc(sizeof(char) * len + 1);
	dec_str[len] = '\0';
	dec_str[0] = '.';
	while ((len - x) > 0)
	{
		if (dec_int % 10 >= 0 && dec_int % 10 <= 9)
			dec_str[len - x] = dec_int % 10 + '0';
		else
			dec_str[len - x] = '0';
		dec_int = dec_int / 10;
		x++;
	}
	return (dec_str);
}

static char					*make_ret_str(char *before, char *after,\
							int i, int x)
{
	int					len_a;
	int					len_b;
	char				*ret_str;

	len_a = 0;
	len_b = ft_strlen(before);
	ret_str = NULL;
	if (after)
		len_a = ft_strlen(after);
	ret_str = (char*)malloc(sizeof(char) * (len_a + len_b + 1));
	ret_str[len_a + len_b] = '\0';
	while (x < len_a + len_b)
	{
		while (x < len_b && before[x])
		{
			ret_str[x] = before[x];
			x++;
		}
		if (after)
			ret_str[x] = after[i];
		i++;
		x++;
	}
	return (ret_str);
}

char						*make_str_f(long double i, t_info *flag)
{
	char				*ret_str;
	char				*before;
	char				*after;

	i = roundup_f(i, (*flag).prec_value);
	find_len_decimals(flag);
	before = ft_itoa_llu(i);
	after = NULL;
	if ((*flag).dot == 0 && (*flag).hash == 0)
		return (before);
	if ((*flag).hash == 1 || ((*flag).dot == 1 && (*flag).prec_value != 0))
		after = get_decimals(i, flag);
	if (after && (*flag).prec_value <= (int)ft_strlen(after) - 1 &&\
	(*flag).width <= (int)ft_strlen(after) - 1)
		(*flag).zero = 0;
	ret_str = make_ret_str(before, after, 0, 0);
	if (after)
		free(after);
	if (before)
		free(before);
	return (ret_str);
}
