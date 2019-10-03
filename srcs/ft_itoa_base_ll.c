/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_ll.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 10:37:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/01 16:25:52 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static size_t	digit_count(unsigned long long value, int base)
{
	size_t	i;

	i = 0;
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

static char		*fill_str(unsigned long long value, int base,
int len, int cap)/*, int sign)*/
{
	char	*s;
	char	*s_base;
	int		i;

	i = 1;
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (cap == 0)
		s_base = "0123456789abcdef";
	else
		s_base = "0123456789ABCDEF";
//	if (sign)
//		s[0] = '-';
	while (value != 0)
	{
		s[len - i] = s_base[value % base];
		value = value / base;
		i++;
	}
	s[len] = '\0';
	return (s);
}

char			*ft_itoa_base_ll(unsigned long long value, int base, int cap)
{
	int		len;
	char	*s;
//	int		sign;
	if (base < 2 || base > 16)
		return (0);
	if (base == 10 && value == -2147483648)
		return ("-2147483648");
	if (base == 10 && value == 2147483647)
		return ("2147483647");
//	sign = check_sign(value, base);
//	if (value < 0)
//		value = -value;
	if (value == 0)
		return ("0");
	len = digit_count(value, base);
//	if (sign)
//		len += 1;
	s = fill_str(value, base, len, cap/*, sign*/);
	return (s);
}
