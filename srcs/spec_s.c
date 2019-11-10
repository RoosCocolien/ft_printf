/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/10 18:08:03 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	put_part_str(char *str, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (max);
}

int			spec_s(char *s, va_list args, t_info *flag, int x)
{
	char	*str;
	int		fill;
	int		length;

	pres_width_s(args, flag);
	str = va_arg(args, char*);
	length = ft_strlen(str);
	if (length < (*flag).width && (*flag).precision != 0)
		(*flag).width = 0;
	fill = (*flag).width - length;
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill, s[x]);
	if ((*flag).precision != 0 && length > (*flag).width && (*flag).width != 0)
		length = put_part_str(str, (*flag).width);
	else
		ft_putstr(str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill, s[x]);
	x++;
	return (x);
}
