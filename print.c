/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:23:54 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 17:29:18 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_digit(t_info *flag, unsigned long long nb)
{
	char	*str_digit;
	int		i;

	str_digit = ft_itoa_llu(nb);
	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		ft_putchar_fd('+', (*flag).fd);
		(*flag).plus++;
		(*flag).count++;
	}
	if (nb == 0 && (*flag).plus > 1)
		free(str_digit);
	else
	{
		while (str_digit[i])
		{
			ft_putchar_fd(str_digit[i], (*flag).fd);
			(*flag).count++;
			i++;
		}
		free(str_digit);
	}
}

void	print_address(t_info *flag, char *s)
{
	int		i;

	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		(*flag).count++;
		ft_putchar_fd('+', (*flag).fd);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], (*flag).fd);
		(*flag).count++;
		i++;
	}
}

void	print_string(t_info *flag, char *s)
{
	int		i;

	i = 0;
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
	{
		(*flag).count++;
		ft_putchar_fd('+', (*flag).fd);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], (*flag).fd);
		(*flag).count++;
		i++;
	}
	while ((*flag).leftover != 0)
	{
		ft_putchar_fd('0', (*flag).fd);
		(*flag).leftover--;
		(*flag).count++;
	}
}

void	print_neg(t_info *flag)
{
	if ((*flag).neg == 1 && (*flag).zero != 1)
	{
		ft_putchar_fd('-', (*flag).fd);
		(*flag).count++;
	}
}

void	print_zero(t_info *flag, long long i, char *oct_str)
{
	int length;

	length = ft_strlen(oct_str);
	if ((i != 0 && (*flag).hash == 1) &&\
	((*flag).zero == 0 || ((*flag).zero == 1 && (*flag).width <= length)))
	{
		if (oct_str[0] != '0')
		{
			ft_putchar_fd('0', (*flag).fd);
			(*flag).count++;
		}
	}
}
