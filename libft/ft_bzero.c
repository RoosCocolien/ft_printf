/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 10:30:49 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/11/07 18:35:46 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t x;

	x = 0;
	while (x < n)
	{
		((unsigned char *)s)[x] = '\0';
		x++;
	}
}
