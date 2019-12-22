/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcharfind.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 13:05:59 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/02/22 13:06:00 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcharfind(const char *s, int c)
{
	int x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return (x);
		x++;
	}
	return (-1);
}
