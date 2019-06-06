/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_print.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:13:38 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/06 12:57:35 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_putdouble(double d)
{
	char	*dub;
	char	*tot;
	char	*dec;
	double	len;

	dub = ft_itoa(d);
	ft_putstr(dub);
	ft_putchar('.');
	d = d * 1000000;
	len = ft_strlen(dub);
	tot = ft_itoa(d);
	dec = ft_strsub(tot, len, 6);
	ft_putstr(dec);
}

int		rec_spec(char *str, va_list args, int x)
{
	int		i;
	int		c;
	double	d;
	char	*s;

	if (str[x] == 'd' || str[x] == 'i')
	{
		i = va_arg(args, int);
		ft_putnbr(i);
	}
	else if (str[x] == 'f')
	{
		d = va_arg(args, double);
		ft_putdouble(d);
	}
	else if (str[x] == 'c')
	{
		c = va_arg(args, int);
		ft_putchar((char)c);
	}
	else if (str[x] == 's')
	{
		s = va_arg(args, char*);
		ft_putstr(s);
	}
	else if (str[x] == '%')
	{
		ft_putchar('%');
	}
	if (str[x])			//Ik kan alle if's hierin omsluiten
		x++;			//en dan aan het einde x++ doen????
	return (x);			//ik moet denk ik x++ doen per if statement
}

void	set_zero_flags(t_info *flag)
{
	(*flag).minus = 0;
	(*flag).zero = 0;
	(*flag).plus = 0;
	(*flag).space = 0;
	(*flag).width = 0;
}

int		find_flags(char *str, t_info *flag, int x)
{
	int i;
	char *width;

	while (str[x])
	{
		if (str[x] == '-' && (*flag).minus == 0)
		{
			(*flag).minus = 1;
		}
		else if (str[x] == '0' && (*flag).zero == 0)
		{
			(*flag).zero = 1;
		}
		else if (str[x] == '+' && (*flag).plus == 0)
		{
			(*flag).plus = 1;
		}
		else if (str[x] == ' ' && (*flag).space == 0)
		{
			(*flag).space = 1;
		}
		else if (str[x] > 0 && str[x] < 9)
		{
			i = x;
			while (str[x] > 0 && str[x] < 9)
				x++;
			width = ft_strsub(str, i, x - i);
			(*flag).width = ft_atoi(width);
		}
		if (str[x] == 'd' || str[x] == 'i' || str[x] == 'f' || str[x] == 'c'/
		str[x] == 's' || str[x] == '%')
		{
			return (x);
		}
		x++;
	}
		return (x);
}

int		sim_print(const char *restrict format, ...)
{
	va_list	args;
	int		x;
	t_info	flag;	//*

	va_start(args, format);
	x = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			x++;
			set_zero_flags(&flag);					//*
			x = find_flags(((char*)format), &flag, x);		//*
/*			if (x == -1)	error handling
				return (-1);
*/
			x = rec_spec((char*)format, args, x);
/*			if (x == -1)	error handling
				return (-1);
*/
		}
		else
		{
			while (format[x] && format[x] != '%')
			{
				ft_putchar(format[x]);
				x++;
			}
		}
	}
	va_end(args);
	return (0);
}