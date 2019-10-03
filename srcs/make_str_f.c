/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_f.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 18:36:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/03 15:42:45 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		find_len_decimals(long double i, t_info *flag)
{
	(*flag).dot = 1;
	if ((*flag).precision != 0 && (*flag).prec_value == 0)
		(*flag).dot = 0;
	if ((*flag).precision == 0 && (*flag).precision == 0)
		(*flag).prec_value = 6;
}

static int	find_precision(t_info *flag)
{
	int		multiplier;
	int		x;

	multiplier = 1;
	x = (*flag).prec_value;
	while (x > 0)
	{
		multiplier *= 10;
		x--;
	}
	return (multiplier);
}


static int		ft_intlen(int n)
{
	int		len;

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

static char	*get_decimals(long double i, t_info *flag)
{
	char	*dec_str;
	int		len;
	int		dec_int; //precision, the digits after the '.'
	int		precision; //if (*flag).prec_value is 4, precision is 1000
	int		x;

	x = 1;
	precision = find_precision(flag);
	dec_int = (i - (int)i) * precision;
	len = 1 + (*flag).prec_value;
	dec_str = ft_memalloc(sizeof(char) * len + 1);
	dec_str[len] = '\0';
	dec_str[0] = '.';
	// onderstaande is nutteloos
	// while (ft_intlen(dec_int) - len != 0)
	// {
	// 	dec_str[x] = '0';
	// 	len--;
	// 	x++;
	// }
	// x = 1;
	// len = 1 + (*flag).prec_value;
	while (dec_int && (len - x) > 0)
	{
		dec_str[len - x] = dec_int % 10 + '0';
		dec_int = dec_int / 10;
		x++;
	}
	return (dec_str);
}

static char		*fill_ret_str(t_info *flag, char *before, char *after)
{
	int		len;
	int		len_b;
	int		x;
	int		i;
	char	*ret_str;

	x = 0;
	i = 0;
	len_b = ft_strlen(before);
	ret_str = NULL;
	if ((*flag).dot == 0)
		return (before);
	len = len_b + ft_strlen(after);
	ret_str = (char*)malloc(sizeof(char) * (len + 1));
	ret_str[len + 1] = '\0';
	while (after[i])
	{
		while (x < len_b && before[x])
		{
			ret_str[x] = before[x];
			x++;
		}
		ret_str[x] = after[i];
		i++;
		x++;
	}
	return (ret_str);
}

char		*make_str_f(long double i, t_info *flag)
{
	char		*ret_str;
	char		*before;
	char		*after;
	char		*after_g;

	i = roundup_f(i, (*flag).prec_value);
	find_len_decimals(i, flag);
	before = ft_itoa_llu(i);
	after = NULL;
	if ((*flag).dot == 1)
		after = get_decimals(i, flag);
//	if spec_g is on, then other requirements must be taken into
//	consideration (no 0's to fill up decimals)
	if ((*flag).spec_g == 1 && (*flag).precision == 0)
	{
		after_g = erase_zeros_for_spec_g(after, flag);
		ret_str = fill_ret_str(flag, before, after_g);
	}
	else
		ret_str = fill_ret_str(flag, before, after);
	if (after)
		free(after);
	free(before);
	return (ret_str);
}
