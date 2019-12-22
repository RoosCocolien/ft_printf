/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_cap.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 10:37:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 18:56:34 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_sign(int value, int base)
{
	if (base == 10 && value < 0)
		return (1);
	else
		return (0);
}

static char		*fill_str(int value, int base, int len, int sign)
{
	char	*s;
	char	*s_base;
	int		i;

	i = 1;
	s_base = "0123456789ABCDEF";
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (sign)
		s[0] = '-';
	while (value != 0)
	{
		s[len - i] = s_base[value % base];
		value = value / base;
		i++;
	}
	s[len] = '\0';
	return (s);
}

char			*ft_itoa_base_cap(int value, int base)
{
	int		len;
	int		sign;
	char	*s;

	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	if (base == 10 && value == 2147483647)
		return ("2147483647");
	sign = check_sign(value, base);
	if (value < 0)
		value = -value;
	if (value == 0)
		return ("0");
	len = ft_digit_count(value, base);
	if (sign)
		len += 1;
	s = fill_str(value, base, len, sign);
	return (s);
}
