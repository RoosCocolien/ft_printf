/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:38:08 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/16 14:38:09 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	size_t	start;

	start = 0;
	while (n > start)
	{
		((char *)dst)[n - 1] = ((const char *)src)[n - 1];
		n--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cx;

	cx = 0;
	if (len > ((size_t)dst - (size_t)src))
	{
		return (ft_memcpy_rev((char*)dst, (const char*)src, len));
	}
	return (ft_memcpy((char*)dst, (const char*)src, len));
}
