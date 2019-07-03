/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 18:17:47 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/21 18:17:48 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int x;

	if (!s)
		return ;
	x = 0;
	while (s[x] != '\0')
	{
		ft_putchar_fd(s[x], fd);
		x++;
	}
}
