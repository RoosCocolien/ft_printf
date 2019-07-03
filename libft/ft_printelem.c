/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printelem.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 12:02:07 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/23 12:02:08 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printelem(t_list *elem)
{
	ft_putstr(elem->content);
	ft_putchar('\n');
}
