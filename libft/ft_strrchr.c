/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 17:45:52 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/14 17:47:43 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int x;

	x = 0;
	while (s[x] != '\0')
		x++;
	while (x >= 0)
	{
		if (s[x] == c)
			return ((char*)&s[x]);
		x--;
	}
	return (NULL);
}
