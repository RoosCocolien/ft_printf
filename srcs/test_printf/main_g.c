/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_g.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:58:16 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/21 17:46:09 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

static void		simple_g(void)
{
	printf("\nSIMPLE_G\n");
	printf("\nSimple test g, general-format floating-point number\n");
	printf("POS < (double)999999.50 DUS f\n");
	printf("\nprintf\t%%g\t(3.1416)\n%g\n", 3.1416);
	ft_printf("%g", 3.1416);
	printf("\nprintf\t%%g\t(6.6589)\n%g\n", 6.6589);
	ft_printf("%g", 6.6589);
	printf("\nprintf\t%%g\t(3.14)\n%g\n", 3.14);
	ft_printf("%g", 3.14);
	printf("\nprintf\t%%g\t(6.65)\n%g\n", 6.65);
	ft_printf("%g", 6.65);
	printf("\nprintf\t%%g\t(0.00)\n%g\n", 0.00);
	ft_printf("%g", 0.00);
	printf("\nprintf\t%%g\t(6.1999999)\n%g\n", 6.1999999);
	ft_printf("%g", 6.1999999);
	printf("\nNEG");
	printf("\nprintf\t%%g\t(-3.1416)\n%g\n", -3.1416);
	ft_printf("%g", -3.1416);
	printf("\nprintf\t%%g\t(-6.6589)\n%g\n", -6.6589);
	ft_printf("%g\n", -6.6589);
	printf("POS < (double)999999.50 DUS f\n");
	printf("\nprintf\t%%g\t(3.1006)\n%g\n", 3.1006);
	ft_printf("%g", 3.1006);
	printf("\nprintf\t%%g\t(0.0)\n%g\n", 0.0);
	ft_printf("%g", 0.0);
	printf("\nprintf\t%%g\t(-0)\n%g\n", -0);
	ft_printf("%g", -0);
	printf("\nprintf\t%%g\t(-1)\n%g\n", -1);
	ft_printf("%g", -1);
	printf("\nprintf\t%%g\t(1.01)\n%g\n", 1.01);
	ft_printf("%g", 1.01);
	printf("\nprintf\t%%g\t(03.040)\n%g\n", 03.04);
	ft_printf("%g", 03.04);
	printf("\nNEG");
	printf("\nprintf\t%%g\t(-0.0102200300)\n%g\n", -0.0102200300);
	ft_printf("%g", -0.0102200300);
	printf("\nprintf\t%%g\t(-6.6009123)\n%g\n", -6.6009123);
	ft_printf("%g\n", -6.6009123);

	printf("\n-- Resultaten f--\n");
	printf("\nprintf\t%%f\t(3.1416)\n%f\n", 3.1416);
	ft_printf("%f", 3.1416);
	printf("\nprintf\t%%f\t(6.6589)\n%f\n", 6.6589);
	ft_printf("%f", 6.6589);
	printf("\nprintf\t%%f\t(3.141614161416)\n%f\n", 3.141614161416);
	ft_printf("%f", 3.141614161416);
	printf("\nprintf\t%%f\t(6.65896589)\n%f\n", 6.65896589);
	ft_printf("%f", 6.65896589);
	printf("\nNEG");
	printf("\nprintf\t%%f\t(-3.1416)\n%f\n", -3.1416);
	ft_printf("%f", -3.1416);
	printf("\nprintf\t%%f\t(-6.6589)\n%f\n", -6.6589);
	ft_printf("%f\n", -6.6589);

	printf("\nPOS > (double)999999.50 DUS e\n");
	printf("\nprintf\t%%g\t(6333125.66)\n%g\n", 6333125.66);
	ft_printf("%g", 6333125.66);
	printf("\nprintf\t%%g\t(999999.50)\n%g\n", 999999.50);
	ft_printf("%g", 999999.50);
	printf("\nprintf\t%%g\t(999995.50)\n%g\n", 999995.50);
	ft_printf("%g", 999995.50);
	printf("\n--RESULTATEN F--\n");
	printf("\nprintf\t%%.1f\t(999995.50)\n%.1f\n", 999995.50);
	ft_printf("%.1f", 999995.50);

	printf("\nprintf\t%%.0f\t(999995.50)\n%.0f\n", 999995.50);
	ft_printf("%.0f", 999995.50);
	printf("\nprintf\t%%e\t(9999999.40)\n%e\n", 9999999.40);
	ft_printf("%e\n", 9999999.40);
	printf("\nprintf\t%%g\t(9999999.40)\n%g\n", 9999999.40);
	ft_printf("%g\n", 9999999.40);
	printf("\nprintf\t%%.1f\t(77770000.00)\n%.1f\n", 77770000.00);
	ft_printf("%.1f", 77770000.00);
	printf("\nprintf\t%%g\t(77770000.00)\n%g\n", 77770000.00);
	ft_printf("%g", 77770000.00);

	printf("\n-- Resultaten e--\n");
	printf("\nprintf\t%%e\t(6333125.66)\n%e\n", 6333125.66);
	ft_printf("%e", 6333125.66);
	printf("\nprintf\t%%e\t(6333125.46)\n%e\n", 6333125.46);
	ft_printf("%e", 6333125.46);
	printf("\nprintf\t%%e\t(999999.50)\n%e\n", 999999.50);
	ft_printf("%e", 999999.50);
	printf("\nprintf\t%%.5e\t(999995.55)\n%.5e\n", 999995.55);
	ft_printf("%.5e", 999995.55);
	printf("\nprintf\t%%e\t(9999999.40)\n%e\n", 9999999.40);
	ft_printf("%e", 9999999.40);
	printf("\nprintf\t%%e\t(99999999.40)\n%e\n", 99999999.40);
	ft_printf("%e\n", 99999999.40);

	printf("\n-- Precision 0 --\n");
	printf("\nprintf\t%%.0g\t(3.1416)\n%.0g\n", 3.1416);
	ft_printf("%.0g\n", 3.1416);
	printf("\nprintf\t%%g\t(6.6589123123)\n%g\n", 6.6589123123);
	ft_printf("%g\n", 6.6589123123);
	printf("\nprintf\t%%.7g\t(3.14)\n%.7g\n", 3.14);
	ft_printf("%.7g\n", 3.14);
	printf("\nprintf\t%%.7g\t(3.14141415)\n%.7g\n", 3.14141415);
	ft_printf("%.7g\n", 3.14141415);
}

static void		simple_g_for_e(void)
{
	printf("If (i < (double)999999.50) than > f\nelse: e\n");
	printf("\nprintf: no precision\t%%g\t(77770000.00)\n%g\n", 77770000.00);
	ft_printf("%g\n", 77770000.00);
	printf("\nprintf: no precision with a lot of decimals and big nb\t%%g\t(77770000.00123123123)\n%g\n", 77770000.00123123123);
	ft_printf("%g\n", 77770000.00123123123);
	printf("\nprintf: no decimals, precision: 3\t%%.3g\t(389389389)\n%g\n", 389389389);
	ft_printf("%g\n", 389389389);
	printf("\nprintf\t%%g\t(6333125.66)\n%g\n", 6333125.66);
	ft_printf("%g\n", 6333125.66);
	printf("\nprintf\t%%g\t(999999.50)\n%g\n", 999999.50);
	ft_printf("%g\n", 999999.50);
}

static void		len_mod_g(void)
{
	printf("\nLEN_MOD_G\n");
	printf("\nLong double test g, general-format floating-point number\n");
	printf("\nPOS\n");
	printf("\nprintf\t%%Lg\t(0.333333333333333334)\n%Lg\n", 0.333333333333333334);
	ft_printf("%Lg\n", 0.333333333333333334);
	printf("\nNEG\n");
	printf("\nprintf\t%%g\t(-0.333333333333333334)\n%g\n", -0.333333333333333334);
	ft_printf("%g\n", -0.333333333333333334);
	printf("\nprintf\t%%g\t(-5498.333333333333333334)\n%g\n", -5498.333333333333333334);
	ft_printf("%g\n", -5498.333333333333333334);
	printf("\nprintf\t%%g\t(-0.333333333333333334)\n%g\n", -0.333333333333333334);
	ft_printf("%g\n", -0.333333333333333334);
	printf("\nprintf\t%%g\t(0.333333333333333334)\n%g\n", 0.333333333333333334);
	ft_printf("%g\n", 0.333333333333333334);
	printf("\nprintf\t%%g\t(-0.1234567)\n%g\n", -0.1234567);
	ft_printf("%g\n", -0.1234567);
	printf("\nprintf\t%%g\t(-0.1234517)\n%g\n", -0.1234517);
	ft_printf("%g\n", -0.1234517);
	printf("\nprintf\t%%g\t(-0.0102200300)\n%g\n", -0.0102200300);
	ft_printf("%g", -0.0102200300);
	printf("\nprintf\t%%g\t(-6.6009123)\n%g\n", -6.6009123);
	ft_printf("%g\n", -6.6009123);
	printf("\nprintf\t%%g\t(-6.60091222222)\n%g\n", -6.60091222222);
	ft_printf("%g\n", -6.60091222222);
	printf("\nprintf\t%%g\t(-0.2222222222)\n%g\n", -0.2222222222);
	ft_printf("%g\n", -0.2222222222);
	printf("\nprintf\t%%g\t(-0.0123456789)\n%g\n", -0.0123456789);
	ft_printf("%g\n", -0.0123456789);
	printf("\nprintf\t%%g\t(-0.222222222222222)\n%g\n", -0.222222222222222);
	ft_printf("%g\n", -0.222222222222222);
	printf("\nprintf\t%%g\t(-123456.222222222222222)\n%g\n", -123456.222222222222222);
	ft_printf("%g\n", -123456.222222222222222);
	printf("\nprintf\t%%g\t(-0.000222222)\n%g\n", -0.000222222);
	ft_printf("%g\n", -0.000222222);

	// printf("\nPOS E\n");
	// printf("\nprintf\t%%Le\t(0.333333333333333334)\n%Le\n", 0.333333333333333334);
	// ft_printf("%Le\n", 0.333333333333333334);
	// printf("\nNEG E\n");
	// printf("\nprintf\t%%Le\t(-0.333333333333333334)\n%Le\n", -0.333333333333333334);
	// ft_printf("%Le\n", -0.333333333333333334);
}

static void		flags_g(void)
{
	printf("\nFLAGS_G\n");
	printf("\nFlags test g, general-format floating-point number\n");
	printf("\nPOS");
	printf("\nprintf\t%%+g\t(89.4567)\n%+g\n", 89.4567);
	ft_printf("%+g\n", 89.4567);
	printf("\nNEG");
	printf("\nprintf\t%%+g\t(-89.4567)\n%+g\n", -89.4567);
	ft_printf("%+g\n", -89.4567);
}

/*
** amount of printed char's
** add zero's or blank spaces at beginning or end
*/

static void		width_asterisk_g(void)
{
	printf("\nWIDTH_ASTERISK_G\n");
	printf("WIDTH ASTERISK, right aligned");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%0*g\t(0, 7.3412)\n%0*g\n", 0, 7.3412);
	ft_printf("%0*g\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%0*g\t(4, 7.3412)\n%0*g\n", 4, 7.3412);
	ft_printf("%0*g\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%0*g\t(18, 7.3412)\n%0*g\n", 18, 7.3412);
	ft_printf("%0*g\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%*g\t(0, 7.3412)\n%*g\n", 0, 7.3412);
	ft_printf("%*g\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%*g\t(4, 7.3412)\n%*g\n", 4, 7.3412);
	ft_printf("%*g\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%*g\t(18, 7.3412)\n%*g\n", 18, 7.3412);
	ft_printf("%*g\n", 18, 7.3412);

	printf("\nWIDTH ASTERISK, left aligned");
	printf("\nflag '0' is ignored when flag '-' (left aligned) is present");
	printf("\nflag '-' always left aligned and filled with spaces");
	printf("\nwith zero: zero's at beginning");
	printf("\nno zero: spaces at beginning (of total amount of printed char's\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 0");
	printf("\nprintf\t%%-0*g\t(0, 7.3412)\n%-0*g\n", 0, 7.3412);
	ft_printf("%-0*g\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 4");
	printf("\nprintf\t%%-0*g\t(4, 7.3412)\n%-0*g\n", 4, 7.3412);
	ft_printf("%-0*g\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*g\t(18, 7.3412)\n%-0*g\n", 18, 7.3412);
	ft_printf("%-0*g\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%-*g\t(0, 7.3412)\n%-*g\n", 0, 7.3412);
	ft_printf("%-*g\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%-*g\t(4, 7.3412)\n%-*g\n", 4, 7.3412);
	ft_printf("%-*g\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*g\t(18, 7.3412)\n%-*g\n", 18, 7.3412);
	ft_printf("%-*g\n", 18, 7.3412);

	printf("\nNEG\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*g\t(18, -7.3412)\n%-0*g\n", 18, -7.3412);
	ft_printf("%-0*g\n", 18, -7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*g\t(18, -7.3412)\n%-*g\n", 18, -7.3412);
	ft_printf("%-*g\n", 18, -7.3412);
	printf("\nNEG value in between 0 and 1\n");
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*g\t(18, -0.3412)\n%-0*g\n", 18, -0.3412);
	ft_printf("%-0*g\n", 18, -0.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*g\t(18, -0.3412)\n%-*g\n", 18, -0.3412);
	ft_printf("%-*g\n", 18, -0.3412);
}


/*
** By default: 6 decimals
** precision value 0: NO DECIMALS PRINTED
** precision value 1: 1 DECIMAL PRINTED
** precision value 8: 8 DECIMALS PRINTED, filled with 0's
*/


static void		precision_g(void)
{
	printf("\nPRECISION_G\n");
	printf("\nPrecision test g notation\n");
	printf("\n- plus sign, precision 0\n");
	printf("\nprintf\t%%+.0g\t(3.1416)\n%+.0g\n", 3.1416);
	ft_printf("%+.0g\n", 3.1416);
	printf("\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*g\t(0, 1.2345)\n%.*g\n", 0, 1.2345);
	ft_printf("%.*g\n", 0, 1.2345);
	printf("\n- precision with asterisk, value: 4");
	printf("\nprintf\t%%.*g\t(4, 1.2345)\n%.*g\n", 4, 1.2345);
	ft_printf("%.*g\n", 4, 1.2345);
	printf("\n- precision with asterisk, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nprintf\t%%22.*g\t(8, 1.2345)\n%22.*g\n", 8, 1.2345);
	ft_printf("%22.*g\n", 8, 1.2345);

	printf("\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*g\t(0, 1.0)\n%.*g\n", 0, 1.0);
	ft_printf("%.*g\n", 0, 1.0);
	printf("\n- precision with asterisk, value: 4");
	printf("\nprintf\t%%.*g\t(4, 368)\n%.*g\n", 4, 368);
	ft_printf("%.*g\n", 4, 368);
	printf("\n normal");
	printf("\nprintf\t%%g\t(368)\n%g\n", 368);
	ft_printf("%g\n", 368);
	printf("\n normal f");
	printf("\nprintf\t%%f\t(368)\n%f\n", 368);
	ft_printf("%f\n", 368);
	printf("\n- precision with asterisk, value: 6");
	printf("\nprintf\t%%.*g\t(6, 35.7412345)\n%.*g\n", 6, 35.7412345);
	ft_printf("%.*g\n", 6, 35.7412345);
	printf("\n- spec_g precision with asterisk, value: 20");
	printf("\nprintf\t%%.*g\t(20, 98.7654321)\n%.*g\n", 20, 98.7654321);
	ft_printf("%.*g\n", 20, 98.7654321);
	printf("\n- spec_f precision with asterisk, value: 20");
	printf("\nprintf\t%%.*f\t(20, 98.7654321)\n%.*f\n", 20, 98.7654321);
	ft_printf("%.*f\n", 20, 98.7654321);
}

static void hash_g(void)
{
	printf("\nHASH_G\n");
	printf("\nPrecision test g notation\n");
	printf("\n- plus sign, precision 0\n");
	printf("\nno #\nprintf\t%%+.0g.\t(3.1416)\n%+.0g.\n", 3.1416);
	ft_printf("%+.0g.\n", 3.1416);
	printf("\nwith #\nprintf\t%%+.0#g.\t(3.1416)\n%+.0#g.\n", 3.1416);
	ft_printf("%+.0#g.\n", 3.1416);

	printf("\nno #\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*g.\t(0, 1.2345)\n%.*g.\n", 0, 1.2345);
	ft_printf("%.*g.\n", 0, 1.2345);
	printf("\nwith #\n- precision with asterisk, value: 0");
	printf("\nprintf\t%%.*#g.\t(0, 1.2345)\n%.*#g.\n", 0, 1.2345);
	ft_printf("%.*#g.\n", 0, 1.2345);

	printf("\n- precision with asterisk, value: 4");
	printf("\nno #\nprintf\t%%.*g\t(4, 1.2345)\n%.*g\n", 4, 1.2345);
	ft_printf("%.*g\n", 4, 1.2345);
	printf("\nwith #\nprintf\t%%.*#g\t(4, 1.2345)\n%.*#g\n", 4, 1.2345);
	ft_printf("%.*#g\n", 4, 1.2345);
	printf("\n- precision with asterisk, value: 8");
	printf("*\nWITH WIDTH: 22, fill left ' '*");
	printf("\nno #\nprintf\t%%22.*g\t(8, 1.234500)\n%22.*g\n", 8, 1.234500);
	ft_printf("%22.*g\n", 8, 1.234500);
	printf("\nwith #\nprintf\t%%22.*#g\t(8, 1.234500)\n%22.*#g\n", 8, 1.234500);
	ft_printf("%22.*#g\n", 8, 1.234500);
}

int				main(void)
{
//	simple_g();
//	simple_g_for_e();
	len_mod_g();
//	flags_g();
//	width_asterisk_g();
//	precision_g();
//	hash_g();
	// while(1);
	return (0);
}
