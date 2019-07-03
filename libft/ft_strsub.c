/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:41:37 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 15:41:38 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	cx;
	size_t			cy;
	char			*str;

	if (!s)
		return (NULL);
	cx = start;
	cy = 0;
	str = (char*)ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (cy < len)
	{
		str[cy] = s[cx];
		cy++;
		cx++;
	}
	str[cy] = '\0';
	return (str);
}
