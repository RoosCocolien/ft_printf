/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:05:42 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 14:05:43 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	cx;

	cx = 0;
	while (src[cx] != '\0' && cx < len)
	{
		dst[cx] = src[cx];
		cx++;
	}
	while (cx < len)
	{
		dst[cx] = '\0';
		cx++;
	}
	return (dst);
}
