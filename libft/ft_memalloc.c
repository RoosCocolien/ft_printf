/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:05:24 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/17 13:05:25 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = malloc(sizeof(*str) * size);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	ft_memset(str, 0, size);
	return (str);
}
