/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sim_print.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:13:38 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/03 17:23:44 by rsteigen      ########   odam.nl         */
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
	int width;

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
			(*flag).width = ft_atoi;
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
			set_zero_flags(flag);							//*
			x = find_flags(((char*)format), flag, x);		//*
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

	//FLAGS
	printf("**-----------------------**\n\tFLAGS 4 integers\n**-----------------------**\n");
	printf("******** right aligned, without fill option ********\n");
	printf("%5d\n", 45);

	printf("******** left aligned, without fill option ********\n");
	printf("%-5d\n", 45);

	printf("******** right aligned, with fill option 0 ********\n");
	printf("%05d\n", 45);
	//printf("%*5d\n", 45); you can't use '*' as fill option

	printf("******** left aligned, with fill option 0 ********\n");
	printf("error: flag 0 is ignored when '-' is present");
	/*printf("%-05d\n", 45);	flag 0 is ignored when '-' is present*/

	printf("******** request plus sign for pos & neg number ********\n");
	//requesting a plus sign
	printf("%+5d\n", 45);
	//requesting plus sign for neg number
	printf("%+5d\n", -45);

	//invisible plus sign && left aligned
	printf("******** left aligned && + sign ********\n");
	printf("%+-5d\n", 36);
	printf("+ - reversed\n");
	printf("%-+5d\n", 46);

	printf("******** left aligned && invisible + sign ********\n");
	printf("% -5d\n", 36);
	printf("% -5d\n", -36);

	printf("******** %%- 5d ********THIS IS STRANGE BEHAVIOR, the amount of spaces does not matter\n");
	//the minus sign prints a space before a positive number
	printf("%-   5d\n", 28);


	printf("**-----------------------**\n\tFLAGS 4 strings\n**-----------------------**\n");
	printf("zero fill (0), plus sign(+) and invisible plus( +) sign are meaningless\
	and will result in undefined behavior with 's' conversion specifier\n");
	printf("%5s\n", "");
	printf("%5s\n", "ab");
	printf("%5s\n", "abcdefghijklm");
	printf("%-5s\n", "");
	printf("%-5s\n", "ab");
	printf("%5s\n", "abcdefghijklm");

	printf("**-----------------------**\n\tFLAGS 4 floating point numbers\n**-----------------------**\n");
	printf("all the same flags and rules apply for floats as for ints\n");
	printf("precision examples\n");
	float nb = 2.7182818;
	printf("%.0f\n", nb);	//hij rondt alles af naar boven
	printf("%.0f.\n", nb);	//die punt na 'f' is gewoon onderdeel van de string
	printf("%.1f\n", nb);
	printf("%.2f\n", nb);
	printf("%.6f\n", nb);
	printf("%f\n", nb);
	printf("%.7f\n", nb);
	float nb2 = 0.7182818;
	printf("%.0f\n", nb2);
	printf("%.0f.\n", nb2);
	printf("%.1f\n", nb2);
	printf("%.5f\n", nb2);
	printf("%.9f\n", nb2);
	printf("%.11f\n", nb2);
	printf("default (6 decimal behind .): (%%f)\n");
	printf("%f\n", nb2);
	printf("\n******** standard flags 4 floating point numbers ********\n");
	printf("%5.1f\n", 2.73);
	printf("%-5.1f\n", 2.73);
	printf("%05.1f\n", 2.73);
	printf("%+5.1f\n", 2.73);
	printf("% 5.1f\n", 2.73);
	printf("%+-5.1f\nAND\n%-+5.1f\n", 2.73, 2.73);
	printf("spatie min:\n% -5.1f\nmin spatie\n%- 5.1f\n", 2.73, 2.73);
	printf("spatie min:\n% -5.1f\nmin spatie\n%- 5.1f\n", -2.73, -2.73);
	printf("% 05.1f\n", 2.73);
	printf("%+05.1f\n", 2.73);
	printf("\n% 5.1f\n", -33.44);

	return (0);
}
