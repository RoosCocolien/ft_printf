/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_print.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:13:38 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/28 16:51:36 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../../libft/includes/libft.h"
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
	if (str[x])
		x++;
	return (x);
}

int		sim_print(const char *restrict format, ...)
{
	va_list	args;
	int		x;
	va_start(args, format);

	x = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			x++;
			x = rec_spec((char*)format, args, x);
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

int		main(void)
{
	//simple test
	printf("printf\t\t%% int: %d char: %c float: %f float: %f string: %s\n", \
	3, 'a', 1.999, 42.5, "Roos");
	sim_print("sim_print\t%% int: %d char: %c float: %f float: %f %s is een dikzak\n", \
	3, 'a', 1.999, 42.5, "Roos");

	//backslash
	printf("printf\t\tQuotations in the \"middle\" of the sentence\n");
	sim_print("sim_print\tQuotations in the \"middle\" of the sentence\n");

	//percentage sign
	printf("printf\t\tThis is a percentage sign: %%\n");
	sim_print("sim_print\tThis is a percentage sign: %%\n");

	//decimals
	printf("This is a %%f %f\n", 25.4);
	sim_print("This is a %%f %f\n", 25.4);

	//negative numbers
	printf("Neg number: %i\n", -36);
	sim_print("Neg number: %i\n", -36);


	return (0);
}