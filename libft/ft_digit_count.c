/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digit_count.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:05:00 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/10 14:53:58 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t			ft_digit_count(intmax_t value, int base)
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
