/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/29 13:27:53 by bvan-de-      #+#    #+#                 */
/*   Updated: 2018/10/30 15:16:09 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int cnb)
{
	if (cnb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (cnb < 0)
	{
		cnb = -cnb;
		ft_putchar('-');
	}
	if (cnb > 9)
	{
		ft_putnbr(cnb / 10);
		ft_putnbr(cnb % 10);
	}
	else
	{
		ft_putchar(cnb + 48);
	}
}
