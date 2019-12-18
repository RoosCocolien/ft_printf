/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:28:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 14:35:55 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	print_content(t_info *flag, char *s, int x)
{
	while (s[x] && s[x] != '%')
	{
		if (s[x] == '{')
			x = color_setter(s, x);
		else
		{
			ft_putchar(s[x]);
			(*flag).count++;
		}
		x++;
	}
	return (x);
}

int			loop_format_args(char *s, va_list args)
{
	t_info	flag;
	int		x;

	x = 0;
	flag.count = 0;
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

int			ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = loop_format_args((char*)format, args);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}
