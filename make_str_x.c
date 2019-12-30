/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_x.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 14:55:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:04:53 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static char		*fill_zeros(intmax_t i, t_info *flag, t_padding *padding,\
				char spec)
{
	char	*zeros;
	int		x;

	x = 0;
	zeros = (char*)malloc(sizeof(char) * ((*padding).fill_p + 1));
	while ((*padding).fill_p > 0)
	{
		if (x == 1 && ((spec == 'p' || ((*flag).hash == 1 && i != 0))))
		{
			if (spec == 'X')
				zeros[x] = 'X';
			else
				zeros[x] = 'x';
		}
		else
			zeros[x] = '0';
		(*padding).fill_p--;
		x++;
	}
	zeros[x] = '\0';
	return (zeros);
}

static char		*fill_str_with_zeros(intmax_t i, t_info *flag,\
				t_padding *padding, char spec)
{
	char	*zeros;

	if (i == 0 && (*padding).length == 0 && spec == 'p')
	{
		zeros = (char*)malloc(sizeof(char) * 2);
		zeros[0] = 'x';
		zeros[1] = '\0';
	}
	else
	{
		(*padding).fill_p = change_fill_0x(i, flag, spec, (*padding).fill_p);
		zeros = fill_zeros(i, flag, padding, spec);
	}
	return (zeros);
}

static void		change_settings_hash_p(t_info *flag, t_padding *padding,\
				char spec)
{
	if ((*flag).precision == 0 && (*padding).fill_p == 0 && (*flag).zero == 1\
	&& (*flag).width != 0 && ((*flag).hash == 1 || spec == 'p'))
	{
		(*flag).precision = 1;
		(*flag).prec_value = (*flag).width;
		(*flag).width = 0;
		(*padding).fill_p = fill_precision(flag, (*padding).length);
		(*padding).fill_p -= 2;
	}
}

static char		*fill_hex(intmax_t i, char spec)
{
	char	*hex;

	if (spec == 'x' || spec == 'p')
		hex = ft_itoa_base_ll(i, 16, 0);
	else
		hex = ft_itoa_base_ll(i, 16, 1);
	return (hex);
}

char			*make_hex_str(intmax_t i, t_info *flag, char spec,\
				t_padding *padding)
{
	char	*hex;
	char	*hex_str;
	char	*zeros;

	hex = fill_hex(i, spec);
	zeros = NULL;
	(*padding).length = check_length_zero(i, hex, flag);
	(*padding).fill_p = fill_precision(flag, (*padding).length);
	change_settings_hash_p(flag, padding, spec);
	if (((*padding).fill_p < 0 && (*flag).hash == 0\
	&& spec != 'p') || ((*flag).zero == 0 && (*flag).hash == 0\
	&& (*flag).precision == 0 && spec != 'p') || ((*flag).hash == 1 && i == 0\
	&& spec != 'p' && (*padding).fill_p <= 0))
		hex_str = ft_strdup(hex);
	else
	{
		zeros = fill_str_with_zeros(i, flag, padding, spec);
		if (i == 0 && (*padding).length == 0 && spec == 'p')
			hex_str = ft_strjoin(hex, zeros);
		else
			hex_str = ft_strjoin(zeros, hex);
		free(zeros);
	}
	free(hex);
	return (hex_str);
}
