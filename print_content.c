/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_content.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:11:08 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 23:05:01 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		print_content(t_info *flag, char *s, int x)
{
	while (s[x] && s[x] != '%')
	{
		if (s[x] == '{')
			x = color_setter(s, x, flag);
		else
		{
			ft_putchar_fd(s[x], (*flag).fd);
			(*flag).count++;
		}
		x++;
	}
	return (x);
}
