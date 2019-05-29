/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 15:01:30 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/21 15:01:31 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlenght(int y)
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

static char		*ft_itoa_cpy(char *str, int cx, int intlen, int n)
{
	int		y;

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

char			*ft_itoa(int n)
{
	int		cx;
	int		intlen;
	char	*str;

	cx = 0;
	intlen = ft_intlenght(n);
	str = (char*)ft_memalloc(intlen + 1);
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
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
