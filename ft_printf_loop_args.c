/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_loop_args.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:14:15 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/23 20:17:48 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			loop_format_args(char *s, va_list args, int fd, int x)
{
	t_info	flag;

	flag.count = 0;
	flag.fd = fd;
	while (s[x])
	{
		if (s[x] == '%')
		{
			x++;
			x = save_flags(s, &flag, x);
			if (x == -1)
				return (-1);
			x = find_spec(s, args, &flag, x);
			if (x == -1)
				return (-1);
		}
		else
		{
			x = print_content(&flag, s, x);
			if (x == -1)
				return (-1);
		}
	}
	return (flag.count);
}
