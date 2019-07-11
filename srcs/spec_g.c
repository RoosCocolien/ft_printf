/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_g.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:19 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/10 14:13:10 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an general-format floating-point number and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

long long unsigned		ft_roundup_g(long double d)
{
	long long int i;
	int len;
	int j;
	char *str;

	i = d * 1000000;
	len = ft_intlength(i);
	str = ft_itoa_llu(i);
	j = len;
	if (str[len - 12] >= '5')
	{
		str[len - 7] += 1;
		d += 1;
	}
	return (d);
}

static void		ft_put_e_for_g(long double d)
{
	long long int new_d_int;
	char *new_d_str;
	char *str;
	int i;
	int j;
	int x;
	int y;
	int len;
	int count;

	j = 0;
	while (d >= 10 || d <= -10)
	{
		d = d / 10;
		j++;
	}
	x = d * 1000000;
	if (ft_intlength(x) > 5)
		d = ft_roundup_g(d);
	new_d_int = d * 1000000;
	new_d_str = ft_itoa_llu(new_d_int);
	len = ft_strlen(new_d_str);
	i = 0;
	y = ft_intlength(x / 1000000);
	str = ft_strsub(new_d_str, x, len);
	if (ft_zero_count(str) == 1)
	{
		while (new_d_str[i + 1] != '\0')
		{
			if (i + 6 == len)
			ft_putchar('.');
			ft_putchar(new_d_str[i]);
			i++;
		}
	}
	else
		ft_putnbr(x / 1000000);
	ft_putchar('e');
	if (j > 10)
		ft_putstr("+");
	else
		ft_putstr("+0");
	ft_putnbr(j);
}

static int		zero_stop(char *str, int i)
{
	int j;
	int point;

	j = 0;
	point = i - 1;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			j = i;
			while (str[j] != '\0')
			{
				if (str[j] != '0')
					break ;
				j++;
			}
			if (str[j + 1] == '\0')
				return (i - point);
		}
		i++;
	}
	return (6);
}

void	ft_put_g(long double d)
{
	char	*dub;
	char	*tot;
	char	*dec;
	double	len;
	int		j;

	dub = ft_itoa(d);
	ft_putstr(dub);
	//printf("d= %llu\n", d);
	d = d * 1000000;
	len = ft_strlen(dub);
	tot = ft_itoa(d);
	dec = ft_strsub(tot, len, zero_stop(tot, len) - len);
	if (ft_strlen(dec) > 0)
		ft_putchar('.');
	ft_putstr(dec);
	free(dec);
	free(tot);
	free(dub);
}

int		spec_g(char *s, va_list args, t_info *flag, int x)
{
	long long int new_d_int;
	char *new_d_str;
	int j;
	int len;
	int count;
	long double d;
	long long unsigned 		i;

	d = va_arg(args, double);
	if (d < 0)
	{
		d = -d;
		ft_putchar('-');
	}
	i = (long long unsigned)(1000000 * d);
	if (d >= (long long unsigned)1000000)
	{
		d = ft_roundup_g(d);
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
