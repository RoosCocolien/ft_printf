/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 16:54:44 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 16:55:12 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_length(char const *s1)
{
	int		y;

	y = (int)ft_strlen(s1);
	while (s1[y - 1] == '\t' || s1[y - 1] == '\n' || s1[y - 1] == ' ')
		y--;
	if (y <= 0)
		y = 0;
	return (y);
}

static int	ft_strtrim_size(int x, int y)
{
	int		size;

	size = (y - x) + 1;
	if (size <= 0)
		size = 1;
	return (size);
}

char		*ft_strtrim(char const *s1)
{
	int		x;
	int		y;
	int		z;
	int		size;
	char	*str;

	x = 0;
	if (!s1)
		return (NULL);
	while (s1[x] == '\t' || s1[x] == '\n' || s1[x] == ' ')
		x++;
	y = ft_strtrim_length(s1);
	size = ft_strtrim_size(x, y);
	str = (char*)ft_memalloc(size);
	if (str == NULL)
		return (NULL);
	z = 0;
	while (x < y)
	{
		str[z] = s1[x];
		z++;
		x++;
	}
	str[z] = '\0';
	return (str);
}
