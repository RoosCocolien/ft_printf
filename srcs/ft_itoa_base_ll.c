/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_ll.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 10:37:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/12 16:22:32 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static size_t	digit_count(intmax_t value, int base)
{
	size_t	i;

	i = 0;
	if (value == 0)
		i = 1;
	while (value)
	{
		value = value / base;
		i++;
	}
	return (i);
}

/*
static int		check_sign(unsigned long long value, int base)
{
	if (base == 10 && value < 0)
		return (1);
	else
		return (0);
}
*/

static char		*fill_str(intmax_t value, int base,
int len, int cap)/*, int sign)*/
{
	char	*s;
	char	*s_base;
	int		i;

	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	if (cap == 0)
		s_base = "0123456789abcdef";
	else
		s_base = "0123456789ABCDEF";
//	if (sign)
//		s[0] = '-';
	while (len > 0)
	{
		len--;
		s[len] = s_base[value % base];
		value = value / base;
	}
	return (s);
}

char			*ft_itoa_base_ll(intmax_t value, int base, int cap)
{
	int		len;
	char	*s;
//	int		sign;

	if (base < 2 || base > 16)
		return (0);
	// if (base == 10 && value == -2147483648)
	// 	return ("-2147483648");
	// if (base == 10 && value == 2147483647)
	// 	return ("2147483647");
//	sign = check_sign(value, base);
//	if (value < 0)
//		value = -value;
//	if (value == 0)
//		return ("0");
	len = digit_count(value, base);
//	if (sign)
//		len += 1;
	s = fill_str(value, base, len, cap/*, sign*/);
	return (s);
}
