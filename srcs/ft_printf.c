/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:28:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/26 16:24:54 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** if something goes wrong in print_content, return (-1);
*/

static int	print_content(char *s, int x)
{
	while (s[x] && s[x] != '%')
	{
		ft_putchar(s[x]);
		x++;
	}
	return (x);
}

int			loop_format_args(char *s, va_list args)
{
	t_info	flag;
	int		x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '%')
		{
			x++;
			set_zero_flags(&flag);
			x = save_flags(s, &flag, x);
//			print_flags(flag);	//this can be removed
			if (x == -1)
			{
				printf("Error ft_printf.c from save_flags.c\n");
				return (-1);
			}
			x = find_spec(s, args, flag, x);
			if (x == -1)
			{
				printf("Error ft_printf.c from find_spec.c, %c\n", s[x]);
				return (-1);
			}
		}
		else
		{
			x = print_content(s, x);
			if (x == -1)
			{
				printf("Error ft_printf.c from print_content\n");
				return (-1);
			}
		}
	}
	return (0);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	args;

	va_start(args, format);
	if (loop_format_args((char*)format, args) == -1)
	{
		printf("Error ft_printf.c from loop_format_args\n");
		return (-1);
	}
	va_end(args);
	return (0);
}
