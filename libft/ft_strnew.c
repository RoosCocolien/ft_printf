/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:11:03 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/17 16:11:32 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(size + 1);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	return (ft_memset(str, '\0', size));
}
