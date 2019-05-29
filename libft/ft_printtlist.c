/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printtlist.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 12:02:07 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/03/16 18:54:51 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printtlist(t_list *list)
{
	while (list)
	{
		ft_putstr(list->content);
		ft_putchar('\n');
		list = list->next;
	}
}
