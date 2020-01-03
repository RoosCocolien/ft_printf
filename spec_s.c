/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	print_string_s(char *str, t_info *flag, t_padding *padding)
{
	int i;
	int max_length;

	i = 0;
	max_length = (*padding).fill_p;
	while (str[i] && max_length > 0)
	{
		ft_putchar_fd(str[i], (*flag).fd);
		(*flag).count++;
		max_length--;
		i++;
	}
}

int			spec_s(va_list args, t_info *flag, int x)
{
	char		*str;
	t_padding	padding;

	set_padding_to_zero(&padding);
	pres_width_s(args, flag);
	str = (char*)va_arg(args, char*);
	if (!str)
		str = "(null)";
	padding.length = ft_strlen(str);
	if ((*flag).precision > 0 && (*flag).prec_value < padding.length)
		padding.fill_p = (*flag).prec_value;
	else
		padding.fill_p = padding.length;
	padding.fill_w = (*flag).width - padding.fill_p;
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && padding.fill_w > 0)
		put_padding(flag, padding.fill_w);
	print_string_s(str, flag, &padding);
	if ((*flag).width > 0 && (*flag).minus == 1 && padding.fill_w > 0)
		put_padding(flag, padding.fill_w);
	x++;
	return (x);
}
