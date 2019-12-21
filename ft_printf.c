/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:28:36 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 17:34:40 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			ft_printf(const char *restrict format, ...)
{
	va_list	args;
	int		count;
	int		fd;

	fd = 1;
	va_start(args, format);
	count = loop_format_args((char*)format, args, fd, 0);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = loop_format_args((char*)format, args, fd, 0);
	if (count == -1)
		return (-1);
	va_end(args);
	return (count);
}
