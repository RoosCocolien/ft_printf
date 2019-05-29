/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 17:11:41 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/16 17:11:44 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char *s1;
	const unsigned char *s2;
	size_t				cx;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	cx = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (cx < n)
	{
		if (s1[cx] != s2[cx])
			return (s1[cx] - s2[cx]);
		cx++;
	}
	return (0);
}
