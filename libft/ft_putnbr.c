/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2018/10/29 13:27:53 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/07/05 13:02:40 by rsteigen      ########   odam.nl         */
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
