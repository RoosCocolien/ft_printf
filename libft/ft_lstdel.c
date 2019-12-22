/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:38:39 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/23 13:38:43 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *alst;
	while (temp)
	{
		temp2 = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = temp2;
	}
	*alst = NULL;
}
