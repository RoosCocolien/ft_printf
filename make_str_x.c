/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_x.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/22 14:55:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/25 18:43:02 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	change_fill_0x(intmax_t i, t_info *flag, char spec, int fill)
{
	if ((((*flag).hash == 1 && i != 0) || spec == 'p') &&\
	(*flag).precision != 0)
	{
		fill += 2;
	}
	if (fill < 2 && (*flag).hash == 1)
		fill = 2;
	return (fill);
}

static char	*fill_str_with_zeros(intmax_t i, t_info *flag, int len, char spec)
{
	int		fill;
	char	*zeros;
	int		x;

	fill = 0;
	// printf("zero: %d\nminus: %d\nprecision: %d\n", (*flag).zero, (*flag).minus, (*flag).precision);
	if ((*flag).minus == 0 && ((*flag).zero == 1 || (*flag).precision != 0))
		fill = (*flag).prec_value - len;
	// printf("fill: %d\n", fill);
	x = 0;
	if (i == 0 && len == 0 && spec == 'p')
	{
		zeros = (char*)malloc(sizeof(char) * 2);
		zeros[0] = 'x';
		zeros[1] = '\0';
	}
	else
	{
		// printf("fill: %d\n", fill);
		fill = change_fill_0x(i, flag, spec, fill);
		// printf("fill: %d\n", fill);
		zeros = (char*)malloc(sizeof(char) * (fill + 1));
		while (fill > 0)
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
			fill--;
			x++;
		}
		zeros[x] = '\0';
	}
	return (zeros);
}

static int	change_prec_value_hash_p(t_info *flag, int length, char spec)
{
	if (((*flag).hash == 1 && (*flag).prec_value <= length + 1) ||\
	(spec == 'p' && (*flag).prec_value <= length + 1))
	{
		if ((*flag).prec_value == length + 1)
			(*flag).prec_value += 1;
		else
			(*flag).prec_value += 2;
	}
	return ((*flag).prec_value);
}

char		*get_hex_str(intmax_t i, t_info *flag, char spec)
{
	char	*hex;
	int		length;
	char	*hex_str;
	char	*zeros;

	if (spec == 'x' || spec == 'p')
		hex = ft_itoa_base_ll(i, 16, 0);
	else
		hex = ft_itoa_base_ll(i, 16, 1);
	length = check_length_zero(i, hex, flag);
	(*flag).prec_value = change_prec_value_hash_p(flag, length, spec);
	printf("prec_val: %d\n", (*flag).prec_value);
	printf("length: %d\n", length);
	if (((*flag).prec_value <= length && (*flag).hash == 0 && spec != 'p')\
	|| ((*flag).zero == 0 && (*flag).hash == 0 && (*flag).precision == 0\
	&& spec != 'p'))
	{
		printf("no zeros\n");
		hex_str = ft_strdup(hex);
	}
	else
	{
		printf("test\n");
		zeros = fill_str_with_zeros(i, flag, length, spec);
		printf("zeros: %s\n", zeros);
		if (i == 0 && length == 0 && spec == 'p')
			hex_str = ft_strjoin(hex, zeros);
		else
			hex_str = ft_strjoin(zeros, hex);
		free(zeros);
	}
	free(hex);
	return (hex_str);
}
