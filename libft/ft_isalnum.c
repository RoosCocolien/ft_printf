/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 11:49:02 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/17 11:49:03 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((ft_isalpha(c)) == 1 || (ft_isdigit(c)) == 1)
		return (1);
	else
		return (0);
}
