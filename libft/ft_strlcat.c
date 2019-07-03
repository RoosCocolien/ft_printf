/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 19:17:33 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 19:18:11 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lengtesrc;
	size_t	lengtedst;
	size_t	lengte;
	size_t	i;
	size_t	j;

	lengtedst = ft_strlen(dst);
	lengtesrc = ft_strlen(src);
	lengte = (lengtedst + lengtesrc);
	if (size <= lengtedst)
		return (lengtesrc + size);
	i = 0;
	while (dst[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < (size - lengtedst - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lengte);
}
