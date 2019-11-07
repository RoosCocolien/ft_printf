/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 18:36:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 15:10:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		find_len_decimals(long double i, t_info *flag)
{
	int					digits;

	digits = ft_digit_count(i, 10);
	(*flag).dot = 1;
	if ((*flag).precision != 0 && (*flag).prec_value == 0 && (*flag).hash != 0)
		(*flag).dot = 0;
	if ((*flag).precision == 0)
		(*flag).prec_value = 6;
}

static long long	find_precision(t_info *flag)
{
	unsigned long long	multiplier;
	int					x;

	multiplier = 1;
	x = (*flag).prec_value;
	if (x > 19)
	{
		(*flag).leftover = x - 18;
		return(1000000000000000000);
	}
	while (x > 0)
	{
		multiplier *= 10;
		x--;
	}
	return (multiplier);
}

static int		ft_intlen(int n)
{
	int					len;

	len = 0;
	if (n == 0)
		return (1);
//n is made positive in beginning, (*flag).neg stores that
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)	//groter dan 0? of != 0
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*get_decimals(long double i, t_info *flag, int l_before)
{
	char				*dec_str;
	int					len;
	long long			dec_int; //precision, the digits after the '.'
	long long			precision; //if (*flag).prec_value is 4, precision is 1000
	int					x;

	x = 1;
	precision = find_precision(flag);
	dec_int = (i - (int)i) * precision;
	len = 1 + (*flag).prec_value - (*flag).leftover;
	dec_str = ft_memalloc(sizeof(char) * len + 1);
	dec_str[len] = '\0';
	dec_str[0] = '.';
	while ((len - x) > 0)
	{
		//i've added this, because of zero values, a weird very big nb
		//is being stored in 'i', so it should be 0
		if (dec_int % 10 >= 0 && dec_int % 10 <= 9)
			dec_str[len - x] = dec_int % 10 + '0';
		else
			dec_str[len - x] = '0';
		dec_int = dec_int / 10;
		x++;
	}
	return (dec_str);
}

static char		*fill_ret_str(t_info *flag, char *before, char *after)
{
	int					len_a;
	int					len_b;
	int					x;
	int					i;
	char				*ret_str;

	x = 0;
	i = 0;
	len_b = ft_strlen(before);
	ret_str = NULL;
	if (!after)
		len_a = 0;
	else
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

char		*make_str_f(long double i, t_info *flag)
{
	char				*ret_str;
	char				*before;
	char				*after;
	char				*after_g;

	i = roundup_f(i, (*flag).prec_value);
	find_len_decimals(i, flag);
	before = ft_itoa_llu(i);
	if ((*flag).dot == 0 && (*flag).hash == 0)
		return (before);
	after = NULL;
	if ((*flag).hash == 1 || ((*flag).dot == 1 && (*flag).prec_value != 0))
		after = get_decimals(i, flag, ft_strlen(before));
	//to make sure neg will work if precision is on, but there are more decimals than precision
	//onderstaande moet ik ook in een functietje zetten
	if (after && (*flag).prec_value <= ft_strlen(after) - 1 && (*flag).width <= ft_strlen(after) - 1)
		(*flag).zero = 0;
	ret_str = fill_ret_str(flag, before, after);
	if (after)
		free(after);
	if (before)
		free(before);
	return (ret_str);
}
