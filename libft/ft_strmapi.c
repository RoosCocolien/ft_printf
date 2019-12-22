/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:51:16 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 14:51:27 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	cx;

	if (!s || !*s || !f || !*f)
		return (NULL);
	str = (char*)ft_memalloc(ft_strlen(s) + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	cx = 0;
	while (s[cx] != '\0')
	{
		str[cx] = f(cx, (s[cx]));
		cx++;
	}
	str[cx] = '\0';
	return (str);
}
