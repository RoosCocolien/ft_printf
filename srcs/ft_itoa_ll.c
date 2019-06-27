/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_ll.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/12 14:25:20 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/20 14:23:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_intlength(long long int y)
{
	int		cx;

	cx = 0;
	if (y == 0)
	{
		return (1);
	}
	if (y < 0)
		cx++;
	while (y != 0)
	{
		cx++;
		y = y / 10;
	}
	return (cx);
}

static char		*ft_itoa_cpy(char *str, int cx, int intlen, long long int n)
{
	long long int		y;

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

char			*ft_itoa_ll(long long int n)
{
	int		cx;
	int		intlen;
	char	*str;

	//printf("this is itoa ll %lld\n", n);
	cx = 0;
	intlen = ft_intlength(n);
	str = (char*)ft_memalloc(intlen + 1);
	if (str == NULL)
		return (NULL);
	// if (n == -2147483648)
	// 	return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[cx] = '-';
		n = -n;
		cx++;
	}
	str[intlen] = '\0';
	intlen--;
	return (ft_itoa_cpy(str, cx, intlen, n));
}