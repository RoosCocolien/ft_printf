/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 14:55:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/11 15:28:57 by rsteigen      ########   odam.nl         */
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

int		change_fill(t_info *flag, int fill, int length)
{
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	if ((*flag).neg == 1 && (*flag).precision == 0)
		fill--;
	if ((*flag).plus == 1)
	{
//		print plus sign on positive numbers
		fill = check_flag_plus(flag, fill, (*flag).minus);
	}
	if ((*flag).space == 1)
	{
//		invisible plus sign
		fill = check_flag_space(flag, fill, (*flag).minus);
	}
	return (fill);
}

void	put_padding(t_info *flag, int fill)
{
	char	char_fill;

	if ((*flag).zero == 1)
	{
		char_fill = '0';
		if ((*flag).neg == 1)
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
