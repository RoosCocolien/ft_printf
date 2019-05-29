/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 15:21:20 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/14 15:21:23 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int x;
	int y;
	int z;

	x = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[x] != '\0')
	{
		if (haystack[x] == needle[0])
		{
			y = 0;
			z = x;
			while ((haystack[z] == needle[y]) && needle[y] != '\0')
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
