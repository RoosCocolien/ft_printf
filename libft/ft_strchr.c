/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:34:16 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/14 16:34:17 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return ((char*)&s[x]);
		x++;
	}
	if (s[x] == c)
		return ((char*)&s[x]);
	return (NULL);
}
