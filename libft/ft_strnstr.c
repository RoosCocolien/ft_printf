/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 18:04:56 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/14 18:04:58 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t x;
	size_t y;
	size_t z;

	x = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (x < len && haystack[x] != '\0')
	{
		if (haystack[x] == needle[0])
		{
			y = 0;
			z = x;
			while (((haystack[z] == needle[y]) && needle[y] != '\0') && z < len)
			{
				z++;
				y++;
			}
			z = 0;
			if (needle[y] == '\0')
				return ((char*)&haystack[x]);
		}
		x++;
	}
	return (NULL);
}
