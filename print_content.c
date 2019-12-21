/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_content.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:11:08 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 17:28:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_content(t_info *flag, char *s, int x)
{
	while (s[x] && s[x] != '%')
	{
		if (s[x] == '{')
			x = color_setter(s, x);
		else
		{
			ft_putchar_fd(s[x], (*flag).fd);
			(*flag).count++;
		}
		x++;
	}
	return (x);
}
