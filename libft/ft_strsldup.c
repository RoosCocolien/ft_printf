/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsldup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 13:06:47 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/03/16 17:51:28 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsldup(const char *src, int start, int comprimento)
{
	int		cx;
	int		cy;
	char	*str;

	cx = start;
	str = (char*)malloc(sizeof(char) * comprimento + 1);
	if (str == NULL)
		return (NULL);
	cy = 0;
	while (cy < comprimento)
	{
		str[cy] = src[cx];
		cx++;
		cy++;
	}
	str[cy] = '\0';
	return (str);
}
