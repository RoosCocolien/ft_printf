/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:28:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/08 15:45:52 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** if something goes wrong in print_content, return (-1);
*/

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
	int		start_count;

	x = 0;
	start_count = 0;
	while (s[x])
	{
		if (s[x] == '%')
		{
			x++;
			set_zero_flags(&flag, start_count);
			start_count++;
			x = save_flags(s, &flag, x);
//			print_flags(flag);	//this can be removed
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
