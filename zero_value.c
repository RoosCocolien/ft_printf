/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zero_value.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 21:24:25 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 19:19:40 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

void	prec_and_zero_check(va_list args, t_info *flag, char spec)
{
	(*flag).dot = 1;
	if ((*flag).sequence < -1 || (*flag).sequence > 1)
		get_sequence_prec_width(args, flag);
	else
		get_prec_width(args, flag, spec);
	if ((*flag).prec_value == 0 && spec != 'p' && spec != 'd' && spec != 'i'\
	&& spec != 'u' && spec != 'x' && spec != 'X' && spec != 'o')
	{
		if ((*flag).precision != 0)
		{
			(*flag).no_decimals = 1;
			if ((*flag).hash != 1)
				(*flag).dot = 0;
		}
		else
			(*flag).prec_value = 6;
	}
	if ((*flag).minus == 1)
		(*flag).zero = 0;
	if (spec == 'x' || spec == 'X')
		(*flag).plus = 0;
	check_asterisk(flag, spec);
}

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
	if (i == 0 && (((*flag).precision != 0 && (*flag).prec_value == 0)\
	|| (*flag).prec_no_val == 1))
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
