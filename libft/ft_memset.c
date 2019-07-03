/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:30:49 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/16 10:30:55 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)str)[x] = c;
		x++;
	}
	return (str);
}
