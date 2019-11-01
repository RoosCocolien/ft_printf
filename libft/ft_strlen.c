/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:31:21 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/11/01 17:01:32 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t cx;

	cx = 0;
	while (str[cx] != '\0')
		cx++;
	return (cx);
}
