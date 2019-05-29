/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 16:35:12 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 16:35:14 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		x;
	size_t		y;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char*)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[x] != '\0')
	{
		str[x] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	str[x] = '\0';
	return (str);
}
