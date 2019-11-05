/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_ll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 11:05:55 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int				ft_intlength(unsigned long long y)
{
	int		cx;

	cx = 0;
	if (y == 0)
	{
		return (1);
	}
	while (y != 0)
	{
		cx++;
		y = y / 10;
	}
	return (cx);
}

static char		*ft_itoa_cpy(char *str, int cx, int intlen,
unsigned long long n)
{
	unsigned long long		y;

	while (intlen >= cx)
	{
		y = n;
		while (n > 9)
			n = n % 10;
		str[intlen] = n + 48;
		n = y / 10;
		intlen--;
	}
	return (str);
}

char			*ft_itoa_llu(unsigned long long n)
{
	int		cx;
	int		intlen;
	char	*str;

	cx = 0;
	intlen = ft_intlength(n);
	str = (char*)ft_memalloc(intlen + 1);
	if (str == NULL)
		return (NULL);
	str[intlen] = '\0';
	intlen--;
	str = ft_itoa_cpy(str, cx, intlen, n);
	return (str);
}
