/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/23 19:42:24 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		check_flag_plus(t_info *flag, int fill, int left_align)
{
	if ((*flag).precision == 0 && (*flag).neg == 0)
		fill--;
	if ((*flag).neg == 0 && (((*flag).precision != 0 || left_align == 1) ||
	(*flag).zero == 1))
	{
		ft_putchar_fd('+', (*flag).fd);
		(*flag).plus++;
		(*flag).count++;
	}
	return (fill);
}

int		check_flag_space(t_info *flag, int fill, int left_align)
{
	left_align = 0; //weghalen
//	if ((*flag).precision == 0 && (*flag).neg == 0)
//		fill--;
//	printf("test\nneg: %d, precision: %d, left_align: %d", (*flag).neg, (*flag).precision, left_align);
	if ((*flag).neg == 0/*&& (((*flag).precision != 0 || left_align == 1) ||\
	(*flag).zero == 1)*/ && (*flag).f_nan == 0)
	{
		ft_putchar_fd(' ', (*flag).fd);
		fill--;
		(*flag).count++;
	}
	return (fill);
}

int		save_prec_width(char *s, t_info *flag, int x)
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

int		check_precision(char *s, t_info *flag, int x)
{
	if (s[x + 1] == '*')
	{
		(*flag).precision = 2;
		x = x + 2;
	}
	else
	{
		(*flag).precision = 1;
		x++;
		x = save_prec_width(s, flag, x);
	}
	return (x);
}

void	set_zero_flags(t_info *flag)
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
}
