/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:40 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/10 17:44:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an void * (pointer to void) and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

// static int		ft_intmaxlen_base(intmax_t n, int base_len)
// {
// 	int	len;

// 	len = 1;
// 	while (n >= base_len)
// 	{
// 		n = n / base_len;
// 		len++;
// 	}
// 	return (len);
// }

// static char	*ft_imaxtoa_base(intmax_t n)
// {
// 	int				base_len;
// 	int				i;
// 	char			*str;
// 	char 			*base;

// 	base = "0123456789abcdef";
// 	base_len = 16;
// 	i = ft_intmaxlen_base(n, base_len);
// 	str = ft_memset(str, '0', i);
// 	str[i] = '\0';
// 	while (i > 0)
// 	{
// 		i--;
// 		str[i] = base[n % base_len];
// 		n = n / base_len;
// 	}
// 	return (str);
// }

int		spec_p(char *s, va_list args, t_info *flag, int x)
{
	// char *str;

	// str = ft_imaxtoa_base(va_arg(args, intmax_t));
	// if (str)
	// {
	// 	ft_putstr("0x");
	// 	ft_putstr(str);
	// }

//	(*flag).plus mag uitgezet worden
//	"0x" hoort bij de lengte van de string voor field width
//	ook bij precision
	(*flag).plus = 0;
	x = spec_x(s, args, flag, x) - 1;
	return (x + 1);
}
