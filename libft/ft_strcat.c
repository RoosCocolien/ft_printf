/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:57 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 17:13:58 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	cx;
	size_t	cz;

	cx = ft_strlen(s1);
	cz = 0;
	while (s2[cz] != '\0')
	{
		s1[cz + cx] = s2[cz];
		cz++;
	}
	s1[cz + cx] = '\0';
	return (s1);
}
