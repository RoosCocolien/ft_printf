/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/10 13:43:56 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**		int zero == 1			-->		fill with zero
**		int zero == 0			-->		fill with ' '
**		int fill				-->		amount to be filled
**		int neg == 1			-->		it's a neg nb
**		int neg == 0			-->		it's a pos nb
*/

void	put_padding(t_info *flag, int zero, int fill, int neg)
{
	char	char_fill;

	if (zero == 1)
	{
		char_fill = '0';
		if (neg == 1)
		{
			ft_putchar('-');
			(*flag).count++;
		}
	}
	else
		char_fill = ' ';
	while (fill > 0)
	{
		ft_putchar(char_fill);
		(*flag).count++;
		fill--;
	}
}
