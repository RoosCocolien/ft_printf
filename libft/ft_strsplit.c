/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 18:12:37 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 18:12:44 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(const char *str, char c)
{
	size_t		x;
	size_t		y;

	x = 0;
	y = 0;
	while (x < ft_strlen(str))
	{
		if (str[x] != c)
		{
			y++;
			while (str[x] != c)
				x++;
		}
		if (str[x] == c)
			x++;
	}
	return (y);
}

static char		**ft_fil(char const *s1, char **new, char c, size_t wordlen)
{
	size_t		x;
	size_t		y;
	size_t		start;

	y = 0;
	x = 0;
	while (y < ft_wordcount(s1, c))
	{
		if (s1[x] != c)
		{
			start = x;
			wordlen = 0;
			while (s1[x] != c && s1[x] != '\0')
			{
				x++;
				wordlen++;
			}
			new[y] = ft_strsub(s1, start, wordlen);
			y++;
		}
		x++;
	}
	new[y] = NULL;
	return (new);
}

char			**ft_strsplit(char const *s1, char c)
{
	char		**new;
	size_t		wordlen;

	wordlen = 0;
	if (!s1)
		return (NULL);
	new = (char**)malloc(sizeof(char*) * ft_wordcount(s1, c) + 1);
	if (new == NULL)
		return (NULL);
	return (ft_fil(s1, new, c, wordlen));
}
