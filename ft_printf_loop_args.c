/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_loop_args.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:14:15 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 20:11:01 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			loop_format_args(char *str, va_list args, int fd, int x)
{
	t_info	flag;

	flag.count = 0;
	flag.fd = fd;
	while (str[x])
	{
		if (str[x] == '%')
		{
			x++;
			x = save_flags(str, &flag, x);
			if (x == -1)
				return (-1);
			x = find_spec(str, args, &flag, x);
			if (x == -1)
				x = print_content(&flag, str, x);
		}
		else
		{
			x = print_content(&flag, str, x);
			if (x == -1)
				return (-1);
		}
	}
	return (flag.count);
}
