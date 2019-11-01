/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_e.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:58:16 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/01 18:20:36 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

static void		simple_e(void)
{
	printf("\nSimple test eE scientific notation\n");
	printf("POS");
	printf("\nprintf\t%%E\t(3.1416)\n%E\n", 3.1416);
	ft_printf("%E\n", 3.1416);
	printf("\nprintf\t%%e\t(3.1416)\n%e\n", 3.1416);
	ft_printf("%e\n", 3.1416);
	printf("\nprintf\t%%E\t(6.6589)\n%E\n", 6.6589);
	ft_printf("%E\n", 6.6589);
	printf("\nprintf\t%%e\t(6.6589)\n%e\n", 6.6589);
	ft_printf("%e\n", 6.6589);
	printf("\nNEG");
	printf("\nprintf\t%%E\t(-3.1416)\n%E\n", -3.1416);
	ft_printf("%E\n", -3.1416);
	printf("\nprintf\t%%e\t(-6.6589)\n%e\n", -6.6589);
	ft_printf("%e\n", -6.6589);
}

static void		len_mod_efg(void)
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
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(0.333333333333333334)\n%Le\n", first_long);
	ft_printf("%Le\n", first_long);
	printf("\nprintf\t%%LE\t(0.333333333333333334)\n%LE\n", first_long);
	ft_printf("%LE\n", first_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%e\t(0.333333333333333334)\n%e\n", first);
	ft_printf("%e\n", first);
	printf("\nprintf\t%%E\t(0.333333333333333334)\n%E\n", first);
	ft_printf("%E\n", first);

	printf("\nPOS NO STORED VARIABLE\n");
	printf("\nprintf\t%%Le && %%e\t(0.987654321987)\n%Le && %e\n", 0.987654321987, 0.987654321987);
	ft_printf("%Le && %e\n", 0.987654321987, 0.987654321987);
	printf("\nprintf\t%%LE && %%E\t(0.998877665544332211)\n%LE && %E\n", 9.998877665544332211, 9.998877665544332211);
	ft_printf("%LE && %E\n", 9.998877665544332211, 9.998877665544332211);
	printf("\nNEG NO STORED VARIABLE\n");
	printf("\nprintf\t%%Le && %%e\t(-98.999888777666555)\n%Le && %e\n", -98.999888777666555, -98.999888777666555);
	ft_printf("%Le && %e\n", -98.999888777666555, -98.999888777666555);
	printf("\nprintf\t%%LE && %%E\t(-12.456789456789456789)\n%LE && %E\n", -12.456789456789456789, -12.456789456789456789);
	ft_printf("%LE && %E\n", -12.456789456789456789, -12.456789456789456789);

	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(-0.333333333333333334)\n%Le\n", first_long_neg);
	ft_printf("%Le\n", first_long_neg);
	printf("\nprintf\t%%LE\t(-0.333333333333333334)\n%LE\n", first_long_neg);
	ft_printf("%LE\n", first_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%e\t(-0.333333333333333334)\n%Le\n", first_neg);
	ft_printf("%e\n", first_neg);
	printf("\nprintf\t%%E\t(-0.333333333333333334)\n%E\n", first_neg);
	ft_printf("%E\n", first_neg);
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(5.33456456456456456456)\n%Le\n", second_long);
	ft_printf("%Le\n", second_long);
	printf("\nprintf\t%%LE\t(5.33456456456456456456)\n%LE\n", second_long);
	ft_printf("%LE\n", second_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%e\t(5.33456456456456456456)\n%Le\n", second);
	ft_printf("%e\n", second);
	printf("\nprintf\t%%E\t(5.33456456456456456456)\n%E\n", second);
	ft_printf("%E\n", second);
	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(-5.33456456456456456456)\n%Le\n", second_long_neg);
	ft_printf("%Le\n", second_long_neg);
	printf("\nprintf\t%%LE\t(-5.33456456456456456456)\n%LE\n", second_long_neg);
	ft_printf("%LE\n", second_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%e\t(-5.33456456456456456456)\n%Le\n", second_neg);
	ft_printf("%e\n", second_neg);
	printf("\nprintf\t%%E\t(-5.33456456456456456456)\n%E\n", second_neg);
	ft_printf("%E\n", second_neg);
	printf("\nLong double test eE scientific notation\n");
	printf("\nPOS LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(23.145145145145145145145145)\n%Le\n", third_long);
	ft_printf("%Le\n", third_long);
	printf("\nprintf\t%%LE\t(23.145145145145145145145145)\n%LE\n", third_long);
	ft_printf("%LE\n", third_long);
	printf("\nPOS DOUBLE\n");
	printf("\nprintf\t%%e\t(23.145145145145145145145145)\n%Le\n", third);
	ft_printf("%e\n", third);
	printf("\nprintf\t%%E\t(23.145145145145145145145145)\n%E\n", third);
	ft_printf("%E\n", third);
	printf("\nNEG LONG DOUBLE\n");
	printf("\nprintf\t%%Le\t(23.145145145145145145145145)\n%Le\n", third_long_neg);
	ft_printf("%Le\n", third_long_neg);
	printf("\nprintf\t%%LE\t(23.145145145145145145145145)\n%LE\n", third_long_neg);
	ft_printf("%LE\n", third_long_neg);
	printf("\nNEG DOUBLE\n");
	printf("\nprintf\t%%e\t(23.145145145145145145145145)\n%Le\n", third_neg);
	ft_printf("%e\n", third_neg);
	printf("\nprintf\t%%E\t(23.145145145145145145145145)\n%E\n", third_neg);
	ft_printf("%E\n", third_neg);
}

static void		flags_e(void)
{
	printf("\nFlags test eE notation\n");
	printf("\nPOS");
	printf("\nprintf\t%%+e\t(89.4567)\n%+e\n", 89.4567);
	ft_printf("%+e\n", 89.4567);
	printf("\nNEG");
	printf("\nprintf\t%%+e\t(-89.4567)\n%+e\n", -89.4567);
	ft_printf("%+e\n", -89.4567);
}

/*
** amount of printed char's
** add zero's or blank spaces at beginning or end
*/

static void		width_asterisk_e(void)
{
	printf("WIDTH ASTERISK, right aligned");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%0*e\t(0, 7.3412)\n%0*e\n", 0, 7.3412);
	ft_printf("%0*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%0*e\t(4, 7.3412)\n%0*e\n", 4, 7.3412);
	ft_printf("%0*e\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%0*e\t(18, 7.3412)\n%0*e\n", 18, 7.3412);
	ft_printf("%0*e\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%*e\t(0, 7.3412)\n%*e\n", 0, 7.3412);
	ft_printf("%*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%*e\t(4, 7.3412)\n%*e\n", 4, 7.3412);
	ft_printf("%*e\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%*e\t(18, 7.3412)\n%*e\n", 18, 7.3412);
	ft_printf("%*e\n", 18, 7.3412);

	printf("\nWIDTH ASTERISK, left aligned");
	printf("\nflag '0' is ignored when flag '-' (left aligned) is present");
	printf("\nflag '-' always left aligned and filled with spaces");
	printf("\nwith zero: zero's at beginning");
	printf("\nno zero: spaces at beginning (of total amount of printed char's\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%-0*e\t(0, 7.3412)\n%-0*e\n", 0, 7.3412);
	ft_printf("%-0*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%-0*e\t(4, 7.3412)\n%-0*e\n", 4, 7.3412);
	ft_printf("%-0*e\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*e\t(18, 7.3412)\n%-0*e\n", 18, 7.3412);
	ft_printf("%-0*e\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%-*e\t(0, 7.3412)\n%-*e\n", 0, 7.3412);
	ft_printf("%-*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%-*e\t(4, 7.3412)\n%-*e\n", 4, 7.3412);
	ft_printf("%-*e\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*e\t(18, 7.3412)\n%-*e\n", 18, 7.3412);
	ft_printf("%-*e\n", 18, 7.3412);

	printf("\nNEG\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*e\t(18, -7.3412)\n%-0*e\n", 18, -7.3412);
	ft_printf("%-0*e\n", 18, -7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*e\t(18, -7.3412)\n%-*e\n", 18, -7.3412);
	ft_printf("%-*e\n", 18, -7.3412);
	printf("\nNEG value in between 0 and 1\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*e\t(18, -0.3412)\n%-0*e\n", 18, -0.3412);
	ft_printf("%-0*e\n", 18, -0.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*e\t(18, -0.3412)\n%-*e\n", 18, -0.3412);
	ft_printf("%-*e\n", 18, -0.3412);
}


/*
** By default: 6 decimals
** precision value 0: NO DECIMALS PRINTED
** precision value 1: 1 DECIMAL PRINTED
** precision value 8: 8 DECIMALS PRINTED, filled with 0's
*/


static void		precision_e(void)
{
	printf("\nPrecision test eE notation\n");
	printf("\n- plus sign, precision 0\n");
	printf("\nprintf\t%%+.0e\t(3.1416)\n%+.0e\n", 3.1416);
	ft_printf("%+.0e\n", 3.1416);
	printf("\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*e\t(0, 1.2345)\n%.*e\n", 0, 1.2345);
	ft_printf("%.*e\n", 0, 1.2345);
	printf("\n- precision with asterisk, value: 4");
	printf("\nprintf\t%%.*e\t(4, 1.2345)\n%.*e\n", 4, 1.2345);
	ft_printf("%.*e\n", 4, 1.2345);
	printf("\n- precision with asterisk, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nprintf\t%%22.*e\t(8, 1.2345)\n%22.*e\n", 8, 1.2345);
	ft_printf("%22.*e\n", 8, 1.2345);

	printf("\n- plus sign and left align sign, precision 0\n");
	printf("\nprintf\t%%-+.0e\t(3.1416)\n%-+.0e\n", 3.1416);
	ft_printf("%-+.0e\n", 3.1416);
	printf("\n- precision with asterisk and left align, value: 0");
	printf("\nprintf\t%%-.*e\t(0, 1.2345)\n%-.*e\n", 0, 1.2345);
	ft_printf("%-.*e\n", 0, 1.2345);
	printf("\n- precision with asterisk and left align(-), value: 4");
	printf("\nprintf\t%%-.*e\t(4, 1.2345)\n%-.*e\n", 4, 1.2345);
	ft_printf("%-.*e\n", 4, 1.2345);
	printf("\n- precision with asterisk and left align(-), value: 8");
	printf("\nprintf\t%%-.*e\t(8, 1.2345)\n%-.*e\n", 8, 1.2345);
	ft_printf("%-.*e\n", 8, 1.2345);
	printf("\n- precision with asterisk and left align, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nprintf\t{red}%%-22.*e\t(8, 1.2345)\n%-22.*e\n", 8, 1.2345);
	ft_printf("{red}%-22.*e{eoc}\n", 8, 1.2345);
}

static void		no_decimals(void)
{
	printf("\nprintf\t%%E\t(6589)\n%E\n", 6589);
	ft_printf("%E\n", 6589);
	printf("\nprintf\t%%e\t(5891)\n%e\n", 5891);
	ft_printf("%e\n", 5891);
	printf("\nprintf\t%%E\t(-31416)\n%E\n", -31416);
	ft_printf("%E\n", -31416);
	printf("\nprintf\t%%e\t(-66589)\n%e\n", -66589);
	ft_printf("%e\n", -66589);
	printf("\nprintf\t%%E\t(2)\n%E\n", 2);
	ft_printf("%E\n", 2);
	printf("\nprintf\t%%e\t(0)\n%e\n", 0);
	ft_printf("%e\n", 0);
	printf("\nprintf\t%%E\t(-3)\n%E\n", -3);
	ft_printf("%E\n", -3);
	printf("\nprintf\t%%e\t(-0)\n%e\n", -0);
	ft_printf("%e\n", -0);
}

int				main(void)
{
	simple_e();
	len_mod_efg();
	flags_e();
	width_asterisk_e();
	precision_e();
	no_decimals();
	// while(1);
	return (0);
}
