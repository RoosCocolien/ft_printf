/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 12:12:49 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/16 12:12:55 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t cx;

	cx = 0;
	while (cx < n)
	{
		if (((unsigned char *)src)[cx] == (unsigned char)c)
		{
			((unsigned char *)dst)[cx] = ((unsigned char *)src)[cx];
			return ((unsigned char*)&dst[cx + 1]);
		}
		((unsigned char *)dst)[cx] = '\0';
		if (((unsigned char *)src)[cx] != '\0')
			((unsigned char *)dst)[cx] = ((unsigned char *)src)[cx];
		cx++;
	}
	return (NULL);
}
