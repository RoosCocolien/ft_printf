/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 13:23:53 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/27 14:12:35 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int		ft_printf(const char *restrict format, int c)
{
	int i;
	char spec;

	i = 0;
	c = 4;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			spec = spec_finder(format[i + 1]);
			if (spec != 0)
			{
				//spec = s
				temp->spec = s;
				temp->data = 
				temp = temp->next;
			}
			else
				ft_putstr("Error, geen goed spec\n");
				exit (1);
			i++;
		}
	}
}