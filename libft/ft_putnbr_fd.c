/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 18:18:16 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/21 18:18:17 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int cnb, int fd)
{
	if (cnb == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (cnb < 0)
	{
		cnb = -cnb;
		ft_putchar_fd('-', fd);
	}
	if (cnb > 9)
	{
		ft_putnbr_fd(cnb / 10, fd);
		ft_putnbr_fd(cnb % 10, fd);
	}
	else
		ft_putchar_fd(cnb + 48, fd);
}
