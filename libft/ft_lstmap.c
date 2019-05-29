/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:17:55 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/24 13:17:58 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*temp;
	t_list		*fresh;

	if (!lst || !f)
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	new = f(lst);
	fresh = ft_lstnew(new->content, new->content_size);
	if (fresh == NULL)
		return (NULL);
	lst = lst->next;
	temp = fresh;
	while (lst)
	{
		new = f(lst);
		fresh->next = ft_lstnew(new->content, new->content_size);
		if (fresh->next == NULL)
			return (NULL);
		fresh = fresh->next;
		lst = lst->next;
	}
	return (temp);
}
