/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bbremer <bbremer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 13:38:51 by bvan-de-       #+#    #+#                */
/*   Updated: 2019/03/24 15:46:04 by bbremer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *cont, size_t cont_size)
{
	t_list		*fresh;

	fresh = (t_list*)malloc(sizeof(t_list));
	if (fresh == NULL)
		return (NULL);
	if (cont == NULL)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
	}
	else
	{
		fresh->content = malloc(ft_strlen(cont) + 1);
		if (fresh->content == NULL)
		{
			free(fresh);
			return (NULL);
		}
		ft_memcpy(fresh->content, cont, ft_strlen(cont) + 1);
		fresh->content_size = (int)cont_size;
	}
	fresh->next = NULL;
	return (fresh);
}
