/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 13:41:35 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/09/26 13:41:37 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		color_setter_a(char *str, int x)
{
	if (str[x + 1] == 'r' && str[x + 2] == 'e' && str[x + 3] == 'd' &&
	str[x + 4] == '}')
	{
		ft_putstr("\e[33;31m");
		return (x + 4);
	}
	if (str[x + 1] == 'g' && str[x + 2] == 'r' && str[x + 3] == 'e' &&
	str[x + 4] == 'e' && str[x + 5] == 'n' && str[x + 6] == '}')
	{
		ft_putstr("\e[33;32m");
		return (x + 6);
	}
	if (str[x + 1] == 'y' && str[x + 2] == 'e' && str[x + 3] == 'l' &&
	str[x + 4] == 'l' && str[x + 5] == 'o' && str[x + 6] == 'w' &&
	str[x + 7] == '}')
	{
		ft_putstr("\e[33;33m");
		return (x + 7);
	}
	return (x);
}

static int		color_setter_b(char *str, int x)
{
	if (str[x + 1] == 'b' && str[x + 2] == 'l' && str[x + 3] == 'u' &&
	str[x + 4] == 'e' && str[x + 5] == '}')
	{
		ft_putstr("\e[33;34m");
		return (x + 5);
	}
	if (str[x + 1] == 'p' && str[x + 2] == 'u' && str[x + 3] == 'r' &&
	str[x + 4] == 'p' && str[x + 5] == 'l' && str[x + 6] == 'e' &&
	str[x + 7] == '}')
	{
		ft_putstr("\e[33;35m");
		return (x + 7);
	}
	if (str[x + 1] == 'e' && str[x + 2] == 'o' && str[x + 3] == 'c' &&
	str[x + 4] == '}')
	{
		ft_putstr("\e[0m");
		return (x + 4);
	}
	return (x);
}

int				color_setter(char *str, int x)
{
	int i;

	i = color_setter_a(str, x);
	if (i != x)
		return (i);
	i = color_setter_b(str, x);
	if (i != x)
		return (i);
	return (x - 1);
}
