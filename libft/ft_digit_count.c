/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_count.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:05:00 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 16:50:00 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_digit_count(unsigned long long value, int base)
{
	size_t	i;

	i = 0;
	if (value == 0)
		i = 1;
	while (value != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}
