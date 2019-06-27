/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_g.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:19 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/20 15:35:32 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an general-format floating-point number and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

static void		ft_put_e_for_g(long double d)
{
    long long int new_d_int;
    char *new_d_str;
    int i;
    int j;
    int len;
    int count;

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
    while (new_d_str[i + 1] != '\0')
    {
        if (i + 6 == len)
            ft_putchar('.');
        ft_putchar(new_d_str[i]);
        i++;
    }
    ft_putchar('e');
    if (i > 10)
        ft_putstr("+");
    else
        ft_putstr("+0");
    ft_putnbr(j);
}

void	ft_put_g(double d)
{
	char	*dub;
	char	*tot;
	char	*dec;
	double	len;
    int     j;

	dub = ft_itoa(d);
	ft_putstr(dub);
	ft_putchar('.');
	d = d * 1000000;
	len = ft_strlen(dub);
	tot = ft_itoa(d);
	dec = ft_strsub(tot, len, 6 - len);
	ft_putstr(dec);
}

int		spec_g(char *s, va_list args, t_info flag, int x)
{
	long long int new_d_int;
    char *new_d_str;
    int i;
    int j;
    int len;
    int count;
	long double d;

	d = va_arg(args, double);
	if (d >= 1000000 || d <= -1000000)
	{
		d = ft_roundup(d);
		ft_put_e_for_g(d);
		return (x + 1);
	}
    new_d_int = d * 10;
    new_d_str = ft_itoa_llu(new_d_int);
    len = ft_strlen(new_d_str);
	if (len <= 7)
	{
		ft_put_g(d);
		return (x + 1);
	}
    if (new_d_str[len - 1] > '5')
    	new_d_str[len - 2] += 1;
    new_d_str[len - 1] = '\0';
    ft_putstr(new_d_str);
	return (x + 1);
}
 //meer dan 6 getalen? Dan doe hij pas short, anders gewoon input printen.
