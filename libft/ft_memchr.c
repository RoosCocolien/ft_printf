/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 18:01:27 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/16 18:01:37 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		if (((unsigned char *)s)[x] == (unsigned char)c)
			return ((char*)&s[x]);
		x++;
	}
	return (NULL);
}
