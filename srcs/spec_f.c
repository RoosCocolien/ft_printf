/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:11 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/24 18:19:37 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an double and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

void	ft_putdouble(long long unsigned d)
{
	char	*dub;
	char	*tot;
	char	*dec;
	int j;
	double	len;

	dub = ft_itoa_llu(d / 1000000);
	ft_putstr(dub);
	ft_putchar('.');
	j = ft_deci_count(d);
	while (j < 5)
	{
		ft_putchar('0');
		j++;;
	}
	len = ft_strlen(dub);
	if ((int)d / 1000000 == 0)
		len -= 1;
	tot = ft_itoa_llu(d);
	dec = ft_strsub(tot, len, 6);
	ft_putstr(dec);
	free(dec);
}

int		spec_f(char *s, va_list args, t_info flag, int x)
{
	double 					d;
	long long unsigned 		i;

	d = va_arg(args, double);
	if (d < 0)
	{
		d = -d;
		ft_putchar('-');
	}
	i = (long long unsigned)(1000000 * d);
	ft_putdouble(i);
	return (x + 1);
}
