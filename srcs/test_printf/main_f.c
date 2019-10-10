/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:58:16 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/08 16:26:14 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

static void		simple_f(void)
{
	printf("\nSimple test f, floating-point number\n");
	printf("POS");
	printf("\nprintf\t%%f\t(3.1416)\n%f\n", 3.1416);
	ft_printf("%f", 3.1416);
	printf("\nprintf\t%%f\t(6.65899)\n%f\n", 6.65899);
	ft_printf("%f", 6.65899);
	printf("\nprintf\t%%f\t(367.14168949)\n%f\n", 367.14168949);
	ft_printf("%f", 367.14168949);
	printf("\nprintf\t%%f\t(0.2)\n%f\n", 0.2);
	ft_printf("%f", 0.2);
	printf("\nNEG");
	printf("\nprintf\t%%f\t(-3.1416)\n%f\n", -3.1416);
	ft_printf("%f", -3.1416);
	printf("\nprintf\t%%f\t(-6.6589)\n%f\n", -6.6589);
	ft_printf("%f\n", -6.6589);
	printf("\nprintf\t%%f\t(-367.14168989)\n%f\n", -367.14168989);
	ft_printf("%f", -367.14168989);
	printf("\nprintf\t%%f\t(-0.2)\n%f\n", -0.2);
	ft_printf("%f", -0.2);
}

static void		len_mod_f(void)
{
	double		first;
	long double	first_long;
	double		second;
	long double	second_long;
	double		third;
	long double	third_long;
	double		first_neg;
	long double	first_long_neg;
	double		second_neg;
	long double	second_long_neg;
	double		third_neg;
	long double	third_long_neg;

	first = 0.333333333333333334;
	first_long = 0.333333333333333334;
	second = 5.33456456456456456456;
	second_long = 5.33456456456456456456;
	third = 23.145145145145145145145145;
	third_long = 23.145145145145145145145145;
	first_neg = -0.333333333333333334;
	first_long_neg = -0.333333333333333334;
	second_neg = -5.33456456456456456456;
	second_long_neg = -5.33456456456456456456;
	third_neg = -23.14514514514514514514514599999;
	third_long_neg = -23.14514514514514514514514599999;
	ft_printf("\n{yellow}KAK{eoc}\n");
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf dit is raar\t%%f\t(0.333333333333333334)\n%f\n", first_long);
	ft_printf("%f\n", first_long);
	printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", first_long);
	ft_printf("%f\n", first_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", first);
	ft_printf("%f\n", first);
	printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", first);
	ft_printf("%f\n", first);

	printf("\nPOS NO STORED VARIABLE\n");
	printf("\nprintf\t%%f && %%f\t(0.987654321987)\n%f && %f\n", 0.987654321987, 0.987654321987);
	ft_printf("%f && %f\n", 0.987654321987, 0.987654321987);
	printf("\nprintf\t%%f && %%f\t(0.998877665544332211)\n%f && %f\n", 9.998877665544332211, 9.998877665544332211);
	ft_printf("%f && %f\n", 9.998877665544332211, 9.998877665544332211);
	printf("\nNEG NO STORED VARIABLE\n");
	printf("\nprintf\t%%f && %%f\t(-98.999888777666555)\n%f && %f\n", -98.999888777666555, -98.999888777666555);
	ft_printf("%f && %f\n", -98.999888777666555, -98.999888777666555);
	printf("\nprintf\t%%f && %%f\t(-12.456789456789456789)\n%f && %f\n", -12.456789456789456789, -12.456789456789456789);
	ft_printf("%f && %f\n", -12.456789456789456789, -12.456789456789456789);

	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%f\t(-0.333333333333333334)\n%f\n", first_long_neg);
	ft_printf("%f\n", first_long_neg);
	printf("\nprintf\t%%f\t(-0.333333333333333334)\n%f\n", first_long_neg);
	ft_printf("%f\n", first_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%f\t(-0.333333333333333334)\n%f\n", first_neg);
	ft_printf("%f\n", first_neg);
	printf("\nprintf\t%%f\t(-0.333333333333333334)\n%f\n", first_neg);
	ft_printf("%f\n", first_neg);
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf\t%%f\t(5.33456456456456456456)\n%f\n", second_long);
	ft_printf("%f\n", second_long);
	printf("\nprintf\t%%f\t(5.33456456456456456456)\n%f\n", second_long);
	ft_printf("%f\n", second_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%f\t(5.33456456456456456456)\n%f\n", second);
	ft_printf("%f\n", second);
	printf("\nprintf\t%%f\t(5.33456456456456456456)\n%f\n", second);
	ft_printf("%f\n", second);
	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%f\t(-5.33456456456456456456)\n%f\n", second_long_neg);
	ft_printf("%f\n", second_long_neg);
	printf("\nprintf\t%%f\t(-5.33456456456456456456)\n%f\n", second_long_neg);
	ft_printf("%f\n", second_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%f\t(-5.33456456456456456456)\n%f\n", second_neg);
	ft_printf("%f\n", second_neg);
	printf("\nprintf\t%%f\t(-5.33456456456456456456)\n%f\n", second_neg);
	ft_printf("%f\n", second_neg);
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_long);
	ft_printf("%f\n", third_long);
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_long);
	ft_printf("%f\n", third_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third);
	ft_printf("%f\n", third);
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third);
	ft_printf("%f\n", third);
	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_long_neg);
	ft_printf("%f\n", third_long_neg);
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_long_neg);
	ft_printf("%f\n", third_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_neg);
	ft_printf("%f\n", third_neg);
	printf("\nprintf\t%%f\t(23.145145145145145145145145)\n%f\n", third_neg);
	ft_printf("%f\n", third_neg);
}

static void		flags_f(void)
{
	printf("\nFlags test f, floating-point number\n");
	printf("\nPOS");
	printf("\nprintf\t%%+f\t(89.4567)\n%+f\n", 89.4567);
	ft_printf("%+f\n", 89.4567);
	printf("\nNEG");
	printf("\nprintf\t%%+f\t(-89.4567)\n%+f\n", -89.4567);
	ft_printf("%+f\n", -89.4567);
}

/*
** amount of printed char's
** add zero's or blank spaces at beginning or end
*/

static void		width_asterisk_f(void)
{
	printf("WIDTH ASTERISK, right aligned");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%0*f\t(0, 7.3412)\n%0*f\n", 0, 7.3412);
	ft_printf("%0*f\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%0*f\t(4, 7.3412)\n%0*f\n", 4, 7.3412);
	ft_printf("%0*f\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%0*f\t(18, 7.3412)\n%0*f\n", 18, 7.3412);
	ft_printf("%0*f\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%*f\t(0, 7.3412)\n%*f\n", 0, 7.3412);
	ft_printf("%*f\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%*f\t(4, 7.3412)\n%*f\n", 4, 7.3412);
	ft_printf("%*f\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%*f\t(18, 7.3412)\n%*f\n", 18, 7.3412);
	ft_printf("%*f\n", 18, 7.3412);

	printf("\nWIDTH ASTERISK, left aligned");
	printf("\nflag '0' is ignored when flag '-' (left aligned) is present");
	printf("\nflag '-' always left aligned and filled with spaces");
	printf("\nwith zero: zero's at beginning");
	printf("\nno zero: spaces at beginning (of total amount of printed char's\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%-0*f\t(0, 7.3412)\n%-0*f\n", 0, 7.3412);
	ft_printf("%-0*f\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%-0*f\t(4, 7.3412)\n%-0*f\n", 4, 7.3412);
	ft_printf("%-0*f\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*f\t(18, 7.3412)\n%-0*f\n", 18, 7.3412);
	ft_printf("%-0*f\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%-*f\t(0, 7.3412)\n%-*f\n", 0, 7.3412);
	ft_printf("%-*f\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%-*f\t(4, 7.3412)\n%-*f\n", 4, 7.3412);
	ft_printf("%-*f\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*f\t(18, 7.3412)\n%-*f\n", 18, 7.3412);
	ft_printf("%-*f\n", 18, 7.3412);

	printf("\nNEG\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*f\t(18, -7.3412)\n%-0*f\n", 18, -7.3412);
	ft_printf("%-0*f\n", 18, -7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*f\t(18, -7.3412)\n%-*f\n", 18, -7.3412);
	ft_printf("%-*f\n", 18, -7.3412);
	printf("\nNEG value in between 0 and 1\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*f\t(18, -0.3412)\n%-0*f\n", 18, -0.3412);
	ft_printf("%-0*f\n", 18, -0.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*f\t(18, -0.3412)\n%-*f\n", 18, -0.3412);
	ft_printf("%-*f\n", 18, -0.3412);
}


/*
** By default: 6 decimals
** precision value 0: NO DECIMALS PRINTED
** precision value 1: 1 DECIMAL PRINTED
** precision value 8: 8 DECIMALS PRINTED, filled with 0's
*/


static void		precision_f(void)
{
	printf("\nPrecision test f notation\n");
	printf("\n- plus sign, precision 0\n");
	printf("\nprintf\t%%+.0f\t(3.1416)\n%+.0f\n", 3.1416);
	ft_printf("%+.0f\n", 3.1416);
	printf("\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*f\t(0, 1.2345)\n%.*f\n", 0, 1.2345);
	ft_printf("%.*f\n", 0, 1.2345);
	printf("\n- precision with asterisk, value: 4");
	printf("\nprintf\t%%.*f\t(4, 1.2345)\n%.*f\n", 4, 1.2345);
	ft_printf("%.*f\n", 4, 1.2345);
	printf("\n- precision with asterisk, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nprintf\t%%22.*f\t(8, 1.2345)\n%22.*f\n", 8, 1.2345);
	ft_printf("%22.*f\n", 8, 1.2345);

	printf("\n- plus sign and left align sign, precision 0\n");
	printf("\nprintf\t%%-+.0f\t(3.1416)\n%-+.0f\n", 3.1416);
	ft_printf("%-+.0f\n", 3.1416);
	printf("\n- precision with asterisk and left align, value: 0");
	printf("\nprintf\t%%-.*f\t(0, 1.2345)\n%-.*f\n", 0, 1.2345);
	ft_printf("%-.*f\n", 0, 1.2345);
	printf("\n- precision with asterisk and left align(-), value: 4");
	printf("\nprintf\t%%-.*f\t(4, 1.2345)\n%-.*f\n", 4, 1.2345);
	ft_printf("%-.*f\n", 4, 1.2345);
	printf("\n- precision with asterisk and left align, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nprintf\t{red}%%-22.*f{eoc}\t(8, 1.2345)\n%-22.*f\n", 8, 1.2345);
	ft_printf("{red}%-22.*f{eoc}\n", 8, 1.2345);	
}

int				main(void)
{
	simple_f();
	len_mod_f();
	flags_f();
	width_asterisk_f();
	precision_f();
	while(1);
	return (0);
}
