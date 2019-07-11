/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_ll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 15:45:33 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_intlength(long long unsigned y)
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

static char		*ft_itoa_cpy(char *str, int cx, int intlen, long long unsigned n)
{
	long long unsigned		y;

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

char			*ft_itoa_llu(long long unsigned n)
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
	return (ft_itoa_cpy(str, cx, intlen, n));
}