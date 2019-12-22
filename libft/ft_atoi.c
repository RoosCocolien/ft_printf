/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:51:58 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 15:52:00 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_whitespace(const char *str, int x)
{
	while (str[x] == 32 || str[x] == 10 || str[x] == 9 || str[x] == 12 ||
		str[x] == 13 || str[x] == 11)
		x++;
	return (x);
}

int			ft_atoi(const char *str)
{
	int		x;
	int		result;
	int		negatief;

	x = 0;
	negatief = 1;
	result = 0;
	if (ft_strcmp(str, "-2147483648") == 0)
		return (-2147483648);
	x = ft_atoi_whitespace(str, x);
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			negatief = -1;
		x++;
	}
	while (str[x] != '\0')
	{
		if (str[x] < 48 || 57 < str[x])
			return (result * negatief);
		else
			result = (result * 10) + (int)(str[x] - '0');
		x++;
	}
	return ((int)result * negatief);
}
