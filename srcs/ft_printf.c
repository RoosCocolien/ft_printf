/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:28:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/08 19:48:26 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	print_content(t_info *flag, char *s, int x)
{
	char 	*color_str;
	int 	color;
	int		save;

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
			set_zero_flags(&flag);
			x = save_flags(s, &flag, x);
			if (x == -1)
			{
				printf("Error ft_printf.c from save_flags.c\n");
				return (-1);
			}
			x = find_spec(s, args, &flag, x);
			if (x == -1)
			{
				printf("Error ft_printf.c from find_spec.c, %c\n", s[x]);
				return (-1);
			}
		}
		else
		{
			x = print_content(&flag, s, x);
			if (x == -1)
			{
				printf("Error ft_printf.c from print_content\n");
				return (-1);
			}
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
	{
		printf("Error ft_printf.c from loop_format_args\n");
		return (-1);
	}
	va_end(args);
	return (count);
}
