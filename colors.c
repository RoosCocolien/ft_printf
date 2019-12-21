/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:41:35 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/12/21 23:10:13 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		color_setter_a(char *str, int x, int fd)
{
	if (str[x + 1] == 'r' && str[x + 2] == 'e' && str[x + 3] == 'd' &&
	str[x + 4] == '}')
	{
		ft_putstr_fd("\e[33;31m", fd);
		return (x + 4);
	}
	if (str[x + 1] == 'g' && str[x + 2] == 'r' && str[x + 3] == 'e' &&
	str[x + 4] == 'e' && str[x + 5] == 'n' && str[x + 6] == '}')
	{
		ft_putstr_fd("\e[33;32m", fd);
		return (x + 6);
	}
	if (str[x + 1] == 'y' && str[x + 2] == 'e' && str[x + 3] == 'l' &&
	str[x + 4] == 'l' && str[x + 5] == 'o' && str[x + 6] == 'w' &&
	str[x + 7] == '}')
	{
		ft_putstr_fd("\e[33;33m", fd);
		return (x + 7);
	}
	return (x);
}

static int		color_setter_b(char *str, int x, int fd)
{
	if (str[x + 1] == 'b' && str[x + 2] == 'l' && str[x + 3] == 'u' &&
	str[x + 4] == 'e' && str[x + 5] == '}')
	{
		ft_putstr_fd("\e[33;34m", fd);
		return (x + 5);
	}
	if (str[x + 1] == 'p' && str[x + 2] == 'u' && str[x + 3] == 'r' &&
	str[x + 4] == 'p' && str[x + 5] == 'l' && str[x + 6] == 'e' &&
	str[x + 7] == '}')
	{
		ft_putstr_fd("\e[33;35m", fd);
		return (x + 7);
	}
	if (str[x + 1] == 'e' && str[x + 2] == 'o' && str[x + 3] == 'c' &&
	str[x + 4] == '}')
	{
		ft_putstr_fd("\e[0m", fd);
		return (x + 4);
	}
	return (x);
}

int				color_setter(char *str, int x, t_info *flag)
{
	int i;

	i = color_setter_a(str, x, (*flag).fd);
	if (i != x)
		return (i);
	i = color_setter_b(str, x, (*flag).fd);
	if (i != x)
		return (i);
	return (x - 1);
}
