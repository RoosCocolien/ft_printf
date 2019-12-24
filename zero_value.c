/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_value.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 21:24:25 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/23 21:50:17 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	print_string_count_length(unsigned long long i, t_info *flag,\
		char *str, int length)
{
	if (i != 0 && length != 0)
	{
		ft_putstr_fd(str, (*flag).fd);
		(*flag).count += length;
	}
}

int		check_length_zero_int(unsigned long long i, t_info *flag)
{
	int length;

	length = 0;
	if (i == 0 && (*flag).precision != 0 && (*flag).prec_value == 0)
	{
		length = 0;
	}
	else
	{
		length = ft_intlength(i);
	}
	return (length);
}

int		check_length_zero(intmax_t i, char *str, t_info *flag)
{
	int length;

	length = 0;
	if (i == 0 && (*flag).precision != 0 && (*flag).prec_value == 0)
	{
		length = 0;
	}
	else
	{
		length = ft_strlen(str);
	}
	return (length);
}
