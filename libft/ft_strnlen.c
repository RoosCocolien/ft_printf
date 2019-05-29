/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:23:04 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/21 11:23:05 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *str, char n)
{
	size_t	cx;
	size_t	cy;

	cx = 0;
	cy = 0;
	while (str[cx] != '\0')
	{
		if (str[cx] == n)
			cy++;
		cx++;
	}
	return (cy);
}
