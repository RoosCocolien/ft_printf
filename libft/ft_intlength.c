/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlength.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 18:28:18 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 18:35:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
