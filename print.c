/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:23:54 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		print_content(t_info *flag, char *str, int x)
{
	while (str[x] && str[x] != '%')
	{
		if (str[x] == '{')
			x = color_setter(str, x, flag);
		else
		{
			ft_putchar_fd(str[x], (*flag).fd);
			(*flag).count++;
		}
		x++;
	}
	return (x);
}

void	print_digit(t_info *flag, unsigned long long nb, int length)
{
	char	*str_digit;
	int		x;

	str_digit = ft_itoa_llu(nb);
	x = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0 && (*flag).f_nan == 0)
	{
		put_plus_change_count(flag);
	}
	if ((*flag).plus == 1 && (*flag).neg == 0 && (*flag).f_nan == 0)
		put_plus_change_count(flag);
	while (str_digit[x] && length != 0)
	{
		ft_putchar_fd(str_digit[x], (*flag).fd);
		(*flag).count++;
		x++;
	}
	free(str_digit);
}

void	print_address(t_info *flag, char *str, int length)
{
	int		i;

	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		(*flag).count++;
		ft_putchar_fd('+', (*flag).fd);
	}
	while (str[i] && length != 0)
	{
		ft_putchar_fd(str[i], (*flag).fd);
		(*flag).count++;
		i++;
	}
}

void	print_string(t_info *flag, char *str, int length)
{
	int		i;

	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).f_nan == 0)
		put_plus_change_count(flag);
	if ((*flag).plus == 1 && (*flag).neg == 0 && (*flag).f_nan == 0)
		put_plus_change_count(flag);
	if ((*flag).f_nan != 0 || (*flag).f_inf != 0)
		print_nan_f(flag);
	while (str[i] && (*flag).f_nan == 0 && (*flag).f_inf == 0 && length > 0)
	{
		ft_putchar_fd(str[i], (*flag).fd);
		(*flag).count++;
		length--;
		i++;
	}
	while ((*flag).leftover != 0 && (*flag).f_nan == 0 && (*flag).f_inf == 0)
	{
		ft_putchar_fd('0', (*flag).fd);
		(*flag).leftover--;
		(*flag).count++;
	}
}

void	print_zero(t_info *flag, long long i, char *oct_str,\
		t_padding *padding)
{
	if ((i != 0 && (*flag).hash == 1) && (*padding).fill_p < 1 &&\
	((*flag).zero == 0 || ((*flag).zero == 1 && (*padding).fill_w < 1)))
	{
		if (oct_str[0] != '0')
		{
			ft_putchar_fd('0', (*flag).fd);
			(*flag).count++;
		}
	}
}
