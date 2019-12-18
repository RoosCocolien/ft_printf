/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:52 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 14:15:12 by rsteigen      ########   odam.nl         */
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

int			spec_s(va_list args, t_info *flag, int x)
{
	char	*str;
	int		fill;
	int		length;

	pres_width_s(args, flag);
	str = va_arg(args, char*);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
//	if (length < (*flag).width && (*flag).precision != 0)
//		(*flag).width = 0; TESTEN?!
	fill = (*flag).width - (length - (*flag).prec_value);
	if ((*flag).minus != 0 && (*flag).width != 0 && (*flag).zero == 1)
		(*flag).zero = 0;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	if ((*flag).precision != 0 && length > (*flag).prec_value &&\
	(fill < 0 || (*flag).prec_value != 0))
		length = put_part_str(str, (*flag).prec_value);
	else
		ft_putstr(str);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	x++;
	return (x);
}
