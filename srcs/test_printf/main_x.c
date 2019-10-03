/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 13:57:50 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/13 11:22:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

static void simple_test_x(void)
{
	printf("\nSimple test Hexcadecimal\n");
	printf("\nprintf\t%%x\t(1)\n%x\n", 1);
	ft_printf("%x\n", 1);
	printf("\nprintf\t%%x\t(-5)\n%x\n", -5);
	ft_printf("%x\n", -5);
	printf("\nprintf\t%%x\t(0)\n%x\n", 0);
	ft_printf("%x\n", 0);
	printf("\nSimple test\n");
	printf("\nprintf\t%%x\t(532)\n%x\n", 532);
	ft_printf("%x\n", 532);
	printf("\nprintf\t%%x\t(-689)\n%x\n", -689);
	ft_printf("%x\n", -689);
	printf("\nprintf\t%%x\t(4294967295)\n%x\n", 4294967295);
	ft_printf("%x\n", 4294967295);
	printf("\nprintf\t%%x\t(2147483648 (warning: dit is een long))\n%x\n",\
	2147483648);
	ft_printf("%x\n", 2147483648);
	printf("\nprintf\t%%x\t(2147483647)\n%x\n", 2147483647);
	ft_printf("%x\n", 2147483647);
	printf("\nprintf\t%%x\t(0)\n%x\n", 0);
	ft_printf("%x\n", 0);
}

static void	padding_test_x(void)
{
	printf("\nWidth flag\n");
	printf("\nprintf\t%%7x\t(689) width: 7\n%7x\n", 689);
	ft_printf("%7x\n", 689);
	printf("\nprintf\t%%07x\t(5421) witdh: 7, 0 fill\n%07x\n", 5421);
	ft_printf("%07x\n", 5421);
	printf("\nprintf\t%%0-7x\t(-34) witdh: 7, 0 fill, left aligned\
	\n%0-7x\n", -34);
	ft_printf("%0-7x\n", -34);
	printf("Note: flag '0' is ignored when flag '-' is used.\n");
	printf("\nprintf\t%%-7x\t(427) witdh: 7, no fill, left aligned\
	\n%-7x\n", 427);
	ft_printf("%-7x\n", 427);
}

static void	plus_sign_test_x(void)
{
	printf("\nPlus flag\n");
	printf("\nprintf\t%%+8x\t(327) width: 8, flag: +\n%+8x\n", 327);
	ft_printf("%+8x\n", 327);
	printf("\nprintf\t%%+8x\t(0) width: 8, flag: +\n%+8x\n", 0);
	ft_printf("%+8x\n", 0);
	printf("\nprintf\t%%+8x\t(-327) width: 8, flag: +\n%+8x\n", -327);
	ft_printf("%+8x\n", -327);
	printf("\nprintf\t%%+8x\t(56) flag: + (visible), align left\n%+-x\n", 56);
	ft_printf("%+-x\n", 56);
	printf("\nprintf\t%%+8x\t(998)\
	invisible plus ' ', align left '-'\n% -x\n", 998);
	ft_printf("% -x\n", 998);
	printf("\nprintf\t%%- x\t(-435)\
	invisible plus ' ', align left '-', neg nb\n%- x\n", -435);
	ft_printf("%- x\n", -435);
}

static void	combi_plus_space_zero_x(void)
{
	printf("\nCombination of plus, space, zerx\n");
	printf("\nprintf\t%% 05x\t(0)\
	Invisible plus sign, fill 0, width 5\n% 05x\n", 0);
	ft_printf("% 05x\n", 0);
	printf("\nprintf\t%% 05x\t(-461)\
	Invisible plus sign, fill 0, width 5\n% 05x\n", -461);
	ft_printf("% 05x\n", -461);
	printf("\nprintf\t%%+05x\t(38)\
	Visible plus sign, fill 0, width 5\n%+05x\n", 38);
	ft_printf("%+05x\n", 38);
	printf("\nprintf\t%%+05x\t(97)\
	Visible plus sign, fill 0, width 5\n%+05x\n", 97);
	ft_printf("%+05x\n", 97);
}

/*
**	Precision
**	The min nb of digits to be printed. Leading zeros will be added to
**	make up the field with.
**	All other flags ('-', '+', ' ', '-') will be ignored.
*/

static void	precision_x(void)
{
	printf("\nPrecision\n");
	printf("\nprintf\t%%.7x\t(354) min digits: 7\n%.7x\n", 354);
	ft_printf("%.7x\n", 354);
	printf("\nprintf\t%%-.7x\t(997) min digits: 7, align left ('-')\n%-.7x\n",\
	997);
	ft_printf("%-.7x\n", 997);
	printf("\nprintf\t%%0.7x\t(997) min digits: 7, zerx\n%0.7x\n", 632);
	ft_printf("%0.7x\n", 632);
	printf("\nprintf\t%%+.7x\t(3476) min digits: 7, plus\n%+.7x\n", 3476);
	ft_printf("%+.7x\n", 3476);
	printf("\nprintf\t%% .7x\t(-12) min digits: 7, space\n% .7x\n", -12);
	ft_printf("% .7x\n", -12);
	printf("\nprintf\t%%-.7x\t(15) min digits: 7, minus\n%-.7x\n", 15);
	ft_printf("% .7x\n", 15);
}

/*
**	Asterisk
**	Width && precision
*/

static void asterisk_x(void)
{
	printf("\nAsterisk\n");
	printf("Asterisk PRECISION\n");
	printf("\nprintf\t%%.*o (10, 374)\n%.*x\n", 10, 374);
	ft_printf("%.*x\n", 10, 374);

	printf("\nAsterisk WIDTH\n");
	printf("\nprintf\t%%0*o (11, 798)\n%0*x\n", 11, 798);
	ft_printf("%0*x\n", 11, 798);
}

/*
**	Range check
**	unsigned char			hh	0 - 255
**	unsigned short			h	0 - 65.535
**	unsigned int				0 - 4.294.967.295
**	unsigned long			l	0 - 18.446.744.073.709.551.615
**	unsigned long long		ll	0 - 18.446.744.073.709.551.615
*/

static void	range_check_x(void)
{
	printf("Range check\n");
	//uns char
	printf("\nprintf\t%%hhx\tchar (188)\n%hhx\n", 188);
	ft_printf("%hhx\n", 188);
	printf("\nprintf\t%%hhx\tchar (127)\n%hhx\n", 127);
	ft_printf("%hhx\n", 127);
	printf("\nprintf\t%%hhx\tchar (128)\n%hhx\n", 128);
	ft_printf("%hhx\n", 128);
	printf("\nprintf\t%%hhx\tchar (129)\n%hhx\n", 129);
	ft_printf("%hhx\n", 129);
	//uns char < 0
	printf("\nprintf\t%%hhx\tchar < 0 (0)\n%hhx\n", 0);
	ft_printf("%hhx\n", 0);
	printf("\nprintf\t%%hhx\tchar < 0 (-1)\n%hhx\n", -1);
	ft_printf("%hhx\n", -1);
	printf("\nprintf\t%%hhx\tchar < 0 (-2)\n%hhx\n", -2);
	ft_printf("%hhx\n", -2);
	//uns char > 255
	printf("\nprintf\t%%hhx\tchar > 255 (256)\n%hhx\n", 256);
	ft_printf("%hhx\n", 256);

	//uns short
	printf("\nprintf\t%%hx\tshort (35.748)\n%hx\n", 35748);
	ft_printf("%hx\n", 35748);
	//uns short < 0
	printf("\nprintf\t%%hx\tshort < 0 (-18)\n%hx\n", -18);
	ft_printf("%hx\n", -18);
	//uns short > 63.535
	printf("\nprintf\t%%hx\tshort > 65.535 (65536)\n%hx\n", 65536);
	ft_printf("%hx\n", 65536);


	//uns int
	printf("\nprintf\t%%x\tuns int (28956)\n%x\n", 28956);
	ft_printf("%x\n", 28956);
	//uns int < 0
	printf("\nprintf\t%%x\tuns int (-1)\n%x\n", -1);
	ft_printf("%x\n", -1);
	//uns int > 4.294.967.295
	printf("\nprintf\t%%x\tuns int > 4294967295 (4.294.967.295)\n%x\n", 4294967296);
	ft_printf("%x\n", 4294967296);

	//uns long
	printf("\nprintf\t%%lx\tuns long (789)\n%lx\n", 789);
	ft_printf("%lx\n", 789);
	//uns long < 0
	printf("\nprintf\t%%lx\tuns long < 0 (-2)\n%lx\n", -2);
	ft_printf("%lx\n", -2);
	//uns long > 4.294.967.295
	printf("\nprintf\t%%lx\tuns long > 4.294.967.295 (4294967296)\n%lx\n", 4294967296);
	ft_printf("%lx\n", 4294967296);

	//uns long long
	printf("\nprintf\t%%llx\tuns long long (18.443.744.073.709.551.614)\n%llx\n", 18443744073709551614);
	ft_printf("%llx\n", 18443744073709551614);
	//uns long long < 0
	printf("\nprintf\t%%llx\tuns long long < 0 (-1)\n%llx\n", -1);
	ft_printf("%llx\n", -1);


	//uns long long > 18.466.744.073.709.551.615
/*	printf("\nprintf\t%%llx\tuns long long > 18.446.744.073.709.551.615\n%llx\n", 18446744073709551616);
	ft_printf("%llx\n", 18446744073709551616);
	GEEFT EEN ERROR
*/
}

int main (void)
{
//	simple_test_x();
//	padding_test_x();
//	combi_plus_space_zero_x();
//	precision_x();
//	asterisk_x();
//	range_check_x();

	printf("%.*s", 3, "abcdef");
	printf("%.*f", 3, 123456.897789);
//	ft_printf("%.*s", 3, "abcdef");
	return (0);
}