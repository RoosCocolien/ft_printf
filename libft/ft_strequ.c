/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:00:20 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 15:00:24 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t cx;

	cx = 0;
	if (!s1 || !s2)
		return (0);
	while (cx <= (ft_strlen(s1)))
	{
		if (s1[cx] != s2[cx])
			return (0);
		cx++;
	}
	return (1);
}
