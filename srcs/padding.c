/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/27 13:50:20 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	put_padding(int zero, int fill, int neg)
{
	char	char_fill;

	if (zero == 1)
	{
		char_fill = '0';
		if (neg == 1)
			ft_putchar('-');
	}
	else
		char_fill = ' ';
	while (fill > 0)
	{
		ft_putchar(char_fill);
		fill--;
	}
}
