/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:29:35 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 15:29:39 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t lengte)
{
	size_t	cx;
	int		div;

	if (lengte == 0)
		return (0);
	cx = 0;
	while (s1[cx] == s2[cx] && cx <= lengte)
	{
		if (s1[cx] == '\0' || s2[cx] == '\0')
			return ((unsigned char)s1[cx] - (unsigned char)s2[cx]);
		cx++;
	}
	if (cx >= lengte)
		cx--;
	div = (unsigned char)s1[cx] - (unsigned char)s2[cx];
	return (div);
}
