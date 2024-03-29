/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base_ll.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/28 10:37:26 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 16:54:29 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char		*fill_str(unsigned long long value, int base, int len, int cap)
{
	char	*s;
	char	*s_base;

	s = (char*)malloc(sizeof(char) * (len + 1));
	s[len] = '\0';
	if (cap == 0)
		s_base = "0123456789abcdef";
	else
		s_base = "0123456789ABCDEF";
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

	if (base < 2 || base > 16)
		return (0);
	len = ft_digit_count(value, base);
	s = fill_str((unsigned long long)value, base, len, cap);
	return (s);
}
