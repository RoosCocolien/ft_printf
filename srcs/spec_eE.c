/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_eE.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:05 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/04 12:51:13 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an double in normalized scientific notation and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_eE(char *s, va_list args, t_info *flag, int x)
{
    long long int new_d_int;
    char *new_d_str;
    int i;
    int j;
    int len;
    int count;
	long double d;

	d = ft_roundup(va_arg(args, double));
    j = 0;
    while (d >= 10 || d <= -10)
    {
        d = d / 10;
        j++;
    }
    new_d_int = d * 1000000;
    new_d_str = ft_itoa_llu(new_d_int);
    len = ft_strlen(new_d_str);
    i = 0;
    while (new_d_str[i] != '\0')
    {
        if (i + 6 == len)
            ft_putchar('.');
        ft_putchar(new_d_str[i]);
        i++;
    }
    ft_putchar(s[x]);
    if (i > 10)
        ft_putstr("+");
    else
        ft_putstr("+0");
    ft_putnbr(j);
	return (x + 1);
}

