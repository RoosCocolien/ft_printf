/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_d_i2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 12:25:22 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 17:24:19 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

/*
**	SPACE AND PLUS
**	(in)visible plus sign
*/
static void extra_space_plus_di(void)
{
	ft_printf("\n*\t**PLUS SIGN**\t*\\n");
	ft_printf("\nprintf %%+5d, 0\n");
	printf("%+5d\n", 0);
	ft_printf("%+5d\n", 0);
	ft_printf("printf %%+5d, -7\n");
	printf("%+5d\n", -7);
	ft_printf("%+5d\n", -7);
	ft_printf("printf %%+5d, 1536924\n");
	printf("%+5d\n", 1536924);
	ft_printf("%+5d\n", 1536924);

	ft_printf("\n*\t**PLUS SIGN left aligned**\t*\n");
	ft_printf("printf %%+-5d, 0\n");
	printf("%+-5d\n", 0);
	ft_printf("%+-5d\n", 0);
	ft_printf("printf %%+-5d, -7\n");
	printf("%+-5d\n", -7);
	ft_printf("%+-5d\n", -7);

	ft_printf("\n*\t**Invisible PLUS SIGN left aligned**\t*\n");
	ft_printf("\nprintf %% -5d, 0\n");
	printf("% -5d\n", 0);
	ft_printf("% -5d\n", 0);
	ft_printf("printf %% -5d, -7\n");
	printf("% -5d\n", -7);
	ft_printf("% -5d\n", -7);
	ft_printf("printf %% -5d, 1536924\n");
	printf("% -5d\n", 1536924);
	ft_printf("% -5d\n", 1536924);

	ft_printf("\n*\t**Space && Zero**\t*\n");
	ft_printf("\nprintf %% 05d, 0\n");
	printf("% 05d\n", 0);
	ft_printf("% 05d\n", 0);
	ft_printf("printf %% 05d, -7\n");
	printf("% 05d\n", -7);
	ft_printf("% 05d\n", -7);
	ft_printf("printf %% 05d, 1536924\n");
	printf("% 05d\n", 1536924);
	ft_printf("% 05d\n", 1536924);
}

static void	simple_test_di(void)
{
	printf("\nSimple test\n");
	printf("\nprintf\t%%d\t(532)\n%d\n", 532);
	ft_printf("%d\n", 532);
	printf("\nprintf\t%%d\t(-689)\n%d\n", -689);
	ft_printf("%d\n", -689);
	printf("\nprintf\t%%d\t(4294967295)\n%d\n", 4294967295);
	ft_printf("%d\n", 4294967295);
	printf("\nprintf\t%%d\t(2147483648 (warning: dit is een long))\n%d\n",\
	2147483648);
	ft_printf("%d\n", 2147483648);
	printf("\nprintf\t%%d\t(2147483647)\n%d\n", 2147483647);
	ft_printf("%d\n", 2147483647);
	printf("\nprintf\t%%d\t(0)\n%d\n", 0);
	ft_printf("%d\n", 0);
}

static void	padding_test_di(void)
{
	printf("\nWidth flag\n");
	printf("\nprintf\t%%7d\t(689) width: 7\n%7d\n", 689);
	ft_printf("%7d\n", 689);
	printf("\nprintf\t%%07d\t(5421) witdh: 7, 0 fill\n%07d\n", 5421);
	ft_printf("%07d\n", 5421);

	printf("\nprintf\t%%0-7d\t(-33) witdh: 7, left aligned\
	\n%-7d\n", -33);
	ft_printf("%-7d\n", -33);

	printf("\nprintf\t%%0-7d\t(-34) witdh: 7, 0 fill, left aligned\
	\n%0-7d\n", -34);
	ft_printf("%0-7d\n", -34);

	printf("Note: flag '0' is ignored when flag '-' is used.\n");
	printf("\nprintf\t%%-7d\t(427) witdh: 7, no fill, left aligned\
	\n%-7d\n", 427);
	ft_printf("%-7d\n", 427);
}

static void	plus_sign_test_di(void)
{
	printf("\nPlus flag\n");
	printf("\nprintf\t%%+8d\t(327) width: 8, flag: +\n%+8d\n", 327);
	ft_printf("%+8d\n", 327);
	printf("\nprintf\t%%+8d\t(0) width: 8, flag: +\n%+8d\n", 0);
	ft_printf("%+8d\n", 0);
	printf("\nprintf\t%%+8d\t(-327) width: 8, flag: +\n%+8d\n", -327);
	ft_printf("%+8d\n", -327);
	printf("\nprintf\t%%+8d\t(56) flag: + (visible), align left\n%+-d\n", 56);
	ft_printf("%+-d\n", 56);
	printf("\nprintf\t%%+8d\t(998)\
	invisible plus ' ', align left '-'\n% -d\n", 998);
	ft_printf("% -d\n", 998);
	printf("\nprintf\t%%- d\t(-435)\
	invisible plus ' ', align left '-', neg nb\n%- d\n", -435);
	ft_printf("%- d\n", -435);	
}

static void combi_plus_space_zero_di(void)
{
	printf("\nCombination of plus, space, zero\n");
	printf("\nprintf\t%% 05d\t(0)\
	Invisible plus sign, fill 0, width 5\n% 05d\n", 0);
	ft_printf("% 05d\n", 0);
	printf("\nprintf\t%% 05d\t(-461)\
	Invisible plus sign, fill 0, width 5\n% 05d\n", -461);
	ft_printf("% 05d\n", -461);
	printf("\nprintf\t%%+05d\t(38)\
	Visible plus sign, fill 0, width 5\n%+05d\n", 38);
	ft_printf("%+05d\n", 38);
	printf("\nprintf\t%%+05d\t(97)\
	Visible plus sign, fill 0, width 5:\n%+05d\n", 97);
	ft_printf("%+05d\n", 97);
//extra
	ft_printf("\n*\t**Extra**\t*\n");
	ft_printf("\nprintf %%+05d, 0\n");
	printf("%+05d\n", 0);
	printf("return: %d\n", printf("%+05d\n", 0));
	ft_printf("%+05d\n", 0);
	printf("return: %d\n", ft_printf("%+05d\n", 0));
	ft_printf("\nprintf %%+05d, -7\n");
	printf("%+05d\n", -7);
	printf("return: %d\n", printf("%+05d\n", -7));
	ft_printf("%+05d\n", -7);
	printf("return: %d\n", ft_printf("%+05d\n", -7));
	ft_printf("\nprintf %%+05d, 1536924\n");
	printf("%+05d\n", 1536924);
	printf("return: %d\n", printf("%+05d\n", 1536924));
	ft_printf("%+05d\n", 1536924);
	printf("return: %d\n", ft_printf("%+05d\n", 1536924));
}

static void precision_di(void)
{
	printf("\nPrecision\n");
	printf("\nprintf\t%%.7d\t(354) min digits: 7\n%.7d\n", 354);
	printf("return: %d\n", printf("%.7d", 354));
	ft_printf("%.7d\n", 354);
	printf("return: %d\n", ft_printf("%.7d", 354));

	printf("\nprintf\t%%-.7d\t(997) min digits: 7, align left ('-')\n%-.7d\n",\
	997);
	printf("return: %d\n", printf("%-.7d", 997));
	ft_printf("%-.7d\n", 997);
	printf("return: %d\n", ft_printf("%-.7d", 997));

	printf("\nprintf\t%%0.7d\t(632) min digits: 7, zero\n%0.7d\n", 632);
	printf("return: %d\n", printf("%0.7d", 632));
	ft_printf("%0.7d\n", 632);
	printf("return: %d\n", ft_printf("%0.7d", 632));

	printf("\nprintf\t%%+.7d\t(3476) min digits: 7, plus\n%+.7d\n", 3476);
	printf("return: %d\n", printf("%+.7d", 3476));
	ft_printf("%+.7d\n", 3476);
	printf("return: %d\n", ft_printf("%+.7d", 3476));

	printf("\nprintf\t%% .7d\t(-12) min digits: 7, space\n% .7d\n", -12);
	printf("return: %d\n", printf("% .7d", -12));
	ft_printf("% .7d\n", -12);
	printf("return: %d\n", ft_printf("% .7d", -12));

	printf("\nprintf\t%%-.7d\t(15) min digits: 7, minus\n%-.7d\n", 15);
	printf("return: %d\n", printf("%-.7d", 15));
	ft_printf("%-.7d\n", 15);	
	printf("return: %d\n", ft_printf("%-.7d", 15));
}

static void asterisk_di(void)
{
	printf("\nAsterisk\n");
	printf("Asterisk PRECISION");
	printf("\nprintf\t%%.*d (10, 374)\n%.*d\n", 10, 374);
	ft_printf("%.*d\n", 10, 374);

	printf("Asterisk WIDTH");
	printf("\nprintf\t%%0*d (11, 798)\n%0*d\n", 11, 798);
	ft_printf("%0*d\n", 11, 798);
}

static void	range_check_di(void)
{
	printf("\nRange check\n");
	//char
	printf("\nprintf\t%%hhd\tchar (188)\n%hhd\n", 188);
	ft_printf("%hhd\n", 188);
	//char < 0
	printf("\nprintf\t%%hhd\tchar < 0 (-2)\n%hhd\n", -2);
	ft_printf("%hhd\n", -2);
	//char > 255
	printf("\nprintf\t%%hhd\tchar > 255 (256)\n%hhd\n", 256);
	ft_printf("%hhd\n", 256);

	//short
	printf("\nprintf\t%%hd\tshort (35.748)\n%hd\n", 35748);
	ft_printf("%hd\n", 35748);
	//short < 0
	printf("\nprintf\t%%hd\tshort < 0 (-18)\n%hd\n", -18);
	ft_printf("%hd\n", -18);
	//short > 63.535
	printf("\nprintf\t%%hd\tshort > 65.535 (65536)\n%hd\n", 65536);
	ft_printf("%hd\n", 65536);

	//int
	printf("\nprintf\t%%u\tint (28956)\n%d\n", 28956);
	ft_printf("%d\n", 28956);
	//int < 0
	printf("\nprintf\t%%d\tint (-1)\n%d\n", -1);
	ft_printf("%d\n", -1);
	//int > 4.294.967.295
	printf("\nprintf\t%%d\tint > 4294967295 (4.294.967.295)\n%d\n", 4294967296);
	ft_printf("%d\n", 4294967296);

	//long
	printf("\nprintf\t%%ld\tlong (789)\n%ld\n", 789);
	ft_printf("%ld\n", 789);
	//long < 0
	printf("\nprintf\t%%ld\tlong < 0 (-2)\n%ld\n", -2);
	ft_printf("%ld\n", -2);
	//long > 4.294.967.295
	printf("\nprintf\t%%ld\tlong > 4.294.967.295 (4294967296)\n%ld\n", 4294967296);
	ft_printf("%ld\n", 4294967296);

	//long long
	printf("\nprintf\t%%lld\tlong long (18.443.744.073.709.551.614)\n%lld\n", 18443744073709551614);
	ft_printf("%lld\n", 18443744073709551614);
	//long long < 0
	printf("\nprintf\t%%lld\tlong long < 0 (-1)\n%lld\n", -1);
	ft_printf("%lld\n", -1);	
}

static void	hash_flag_di()
{
	ft_printf("\n*\t**Hash**\t*\n");
	ft_printf("\nprintf %%+05#d, 0\n");
	printf("%+05#d\n", 0);
	printf("return: %#d\n", printf("%+05#d\n", 0));
	ft_printf("%+05#d\n", 0);
	printf("return: %#d\n", ft_printf("%+05#d\n", 0));
	ft_printf("\nprintf %%+05#d, -7\n");
	printf("%+05#d\n", -7);
	printf("return: %#d\n", printf("%+05#d\n", -7));
	ft_printf("%+05#d\n", -7);
	printf("return: %#d\n", ft_printf("%+05#d\n", -7));
	ft_printf("\nprintf %%+05#d, 1536924\n");
	printf("%+05#d\n", 1536924);
	printf("return: %#d\n", printf("bla bla %i bla bla %+05#d\n", 3, 1536924));
	ft_printf("%+05#d\n", 1536924);
	printf("return: %#d\n", ft_printf("bla bla %i bla bla %+05#d\n", 3, 1536924));
}

static void	make_test_di_1()
{
	printf("\npart1\n");
	printf("return_pf:\t(%%+.0d, 0)\t%d\n", printf("%+.0d$\n", 0));
	printf("return_fpf:\t(%%+.0d, 0)\t%d\n", ft_printf("%+.0d$\n", 0));
	printf("\n");
	printf("return_pf:\t(%%+.0d, 0)\t%d\n", printf("%+.0d$\n", 5));
	printf("return_fpf:\t(%%+.0d, 0)\t%d\n", ft_printf("%+.0d$\n", 5));
	printf("\n");
	printf("return_pf:\t(%%+ 04d, 40)\t%d\n", printf("%+ 04d$\n", 40));
	printf("return_fpf:\t(%%+ 04d, 40)\t%d\n", ft_printf("%+ 04d$\n", 40));
	printf("\n");
	printf("return_pf:\t(%% +04d, 40)\t%d\n", printf("% +04d$\n", 40));
	printf("return_fpf:\t(%% +04d, 40)\t%d\n", ft_printf("% +04d$\n", 40));
	printf("\n");
	printf("return_pf:\t(%%047.d, 482)\t%d\n", printf("%047.d$\n", 482));
	printf("return_fpf:\t(%%047.d, 482)\t%d\n", ft_printf("%047.d$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%047d, 482)\t%d\n", printf("%047d$\n", 482));
	printf("return_fpf:\t(%%047d, 482)\t%d\n", ft_printf("%047d$\n", 482));
	printf("\n");
}

static void		make_test_di_bonus(void)
{
	printf("\npart2(bonus)\n");
	printf("return_pf:\t(%%*d, 5, 482)\t%d\n", printf("%*d$\n", 5, 482));
	printf("return_fpf:\t(%%*d, 5, 482)\t%d\n", ft_printf("%*d$\n", 5, 482));
	printf("\n");
	printf("return_pf:\t(%%*d, 0, 482)\t%d\n", printf("%*d$\n", 0, 482));
	printf("return_fpf:\t(%%*d, 0, 482)\t%d\n", ft_printf("%*d$\n", 0, 482));
	printf("\n");
	printf("return_pf:\t(%%*d, -5, 482)\t%d\n", printf("%*d$\n", -5, 482));
	printf("return_fpf:\t(%%*d, -5, 482)\t%d\n", ft_printf("%*d$\n", -5, 482));
	printf("\n");
	printf("return_pf:\t(%%*d, -10, 482)\t%d\n", printf("%*d$\n", -10, 482));
	printf("return_fpf:\t(%%*d, -10, 482)\t%d\n", ft_printf("%*d$\n", -10, 482));
	printf("\n");
	printf("return_pf:\t(%%*d, -15, 50)\t%d\n", printf("%*d$\n", -15, 50));
	printf("return_fpf:\t(%%*d, -15, 50)\t%d\n", ft_printf("%*d$\n", -15, 50));
	printf("\n");
	printf("return_pf:\t(%%.*d, -15, 50)\t%d\n", printf("%.*d$\n", -15, 50));
	printf("return_fpf:\t(%%.*d, -15, 50)\t%d\n", ft_printf("%.*d$\n", -15, 50));
	printf("\n");
	printf("return_pf:\t(%%.*d, 15, 50)\t%d\n", printf("%.*d$\n", 15, 50));
	printf("return_fpf:\t(%%.*d, 15, 50)\t%d\n", ft_printf("%.*d$\n", 15, 50));
	printf("\n");
	printf("return_pf:\t(%%.*f, -15, 50.44)\t%d\n", printf("%.*f$\n", -15, 50.44));
	printf("return_fpf:\t(%%.*f, -15, 50.44)\t%d\n", ft_printf("%.*f$\n", -15, 50.44));
	printf("\n");
	printf("return_pf:\t(%%.*f, 15, 50.44)\t%d\n", printf("%.*f$\n", 15, 50.44));
	printf("return_fpf:\t(%%.*f, 15, 50.44)\t%d\n", ft_printf("%.*f$\n", 15, 50.44));
}

static void	make_test_di_loop(void)
{
	printf("return_pf:\t(%%++ ++ d, 482642)\t%d\n", printf("%++ ++ d$\n", 482642));
	printf("return_pf:\t(%%++  + d, 482642)\t%d\n", printf("%++  + d$\n", 482642));
	printf("return_fpf:\t(%%++ ++ d, 482642)\t%d\n", ft_printf("%++ ++ d$\n", 482642));	
	printf("return_pf:\t(%%++  + d, 482642)\t%d\n", ft_printf("%++  + d$\n", 482642));
}

static void extra(void)
{
	printf("%ld (printf)\n", __LONG_MAX__);
	ft_printf("%ld (ft_printf)\n", __LONG_MAX__);
	printf("%lld (printf)\n", __LONG_LONG_MAX__);
	ft_printf("%lld (ft_printf)\n", __LONG_LONG_MAX__);
	printf("%lu (printf)\n", UINT16_MAX);
	ft_printf("%lu (printf)\n", UINT16_MAX);
}

int		main(void)
{
	// extra_space_plus_di();
	// simple_test_di();
	// padding_test_di();
	// combi_plus_space_zero_di();
	// precision_di();
	// asterisk_di();
	// range_check_di();
	// hash_flag_di();
	// make_test_di_1();
	// make_test_di_bonus();
	// make_test_di_loop();
	extra();
	return (0);
}
