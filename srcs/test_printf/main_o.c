/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 16:43:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/11 13:26:33 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
**	Simple test
*/

static void	simple_test_o(void)
{
	printf("\nSimple test\n");
	printf("\nprintf\t%%o\t(532)\n%o\n", 532);
	ft_printf("%o\n", 532);
	printf("\nprintf\t%%o\t(-689)\n%o\n", -689);
	ft_printf("%o\n", -689);
	printf("\nprintf\t%%o\t(4294967295)\n%o\n", 4294967295);
	ft_printf("%o\n", 4294967295);
	printf("\nprintf\t%%o\t(2147483648 (warning: dit is een long))\n%o\n",\
	2147483648);
	ft_printf("%o\n", 2147483648);
	printf("\nprintf\t%%o\t(2147483647)\n%o\n", 2147483647);
	ft_printf("%o\n", 2147483647);
	printf("\nprintf\t%%o\t(0)\n%o\n", 0);
	ft_printf("%o\n", 0);
}

/*
**	Padding test (width)
*/

static void	padding_test_o(void)
{
	printf("\nWidth flag\n");
	printf("\nprintf\t%%7o\t(689) width: 7\n%7o\n", 689);
	ft_printf("%7o\n", 689);
	printf("\nprintf\t%%07o\t(5421) witdh: 7, 0 fill\n%07o\n", 5421);
	ft_printf("%07o\n", 5421);
	printf("\nprintf\t%%0-7o\t(-34) witdh: 7, 0 fill, left aligned\
	\n%0-7o\n", -34);
	ft_printf("%0-7o\n", -34);
	printf("Note: flag '0' is ignored when flag '-' is used.\n");
	printf("\nprintf\t%%-7o\t(427) witdh: 7, no fill, left aligned\
	\n%-7o\n", 427);
	ft_printf("%-7o\n", 427);
}

/*
**	Requesting a plus sign (+) in case of positive numbers
**	Completely ignored, because it is unsigned
*/

static void	plus_sign_test_o(void)
{
	printf("\nPlus flag\n");
	printf("\nprintf\t%%+8o\t(327) width: 8, flag: +\n%+8o\n", 327);
	ft_printf("%+8o\n", 327);
	printf("\nprintf\t%%+8o\t(0) width: 8, flag: +\n%+8o\n", 0);
	ft_printf("%+8o\n", 0);
	printf("\nprintf\t%%+8o\t(-327) width: 8, flag: +\n%+8o\n", -327);
	ft_printf("%+8o\n", -327);
	printf("\nprintf\t%%+8o\t(56) flag: + (visible), align left\n%+-o\n", 56);
	ft_printf("%+-o\n", 56);
	printf("\nprintf\t%%+8o\t(998)\
	invisible plus ' ', align left '-'\n% -o\n", 998);
	ft_printf("% -o\n", 998);
	printf("\nprintf\t%%- o\t(-435)\
	invisible plus ' ', align left '-', neg nb\n%- o\n", -435);
	ft_printf("%- o\n", -435);
}

static void	combi_plus_space_zero_o(void)
{
	printf("\nCombination of plus, space, zero\n");
	printf("\nprintf\t%% 05o\t(0)\
	Invisible plus sign, fill 0, width 5\n% 05o\n", 0);
	ft_printf("% 05o\n", 0);
	printf("\nprintf\t%% 05o\t(-461)\
	Invisible plus sign, fill 0, width 5\n% 05o\n", -461);
	ft_printf("% 05o\n", -461);
	printf("\nprintf\t%%+05o\t(38)\
	Visible plus sign, fill 0, width 5\n%+05o\n", 38);
	ft_printf("%+05o\n", 38);
	printf("\nprintf\t%%+05o\t(97)\
	Visible plus sign, fill 0, width 5\n%+05o\n", 97);
	ft_printf("%+05o\n", 97);
}

/*
**	Precision
**	The min nb of digits to be printed. Leading zeros will be added to
**	make up the field with.
**	All other flags ('-', '+', ' ', '-') will be ignored.
*/

static void	precision_o(void)
{
	printf("\nPrecision\n");
	printf("\nprintf\t%%.7o\t(354) min digits: 7\n%.7o\n", 354);
	ft_printf("%.7o\n", 354);
	printf("\nprintf\t%%-.7o\t(997) min digits: 7, align left ('-')\n%-.7o\n",\
	997);
	ft_printf("%-.7o\n", 997);
	printf("\nprintf\t%%0.7o\t(997) min digits: 7, zero\n%0.7o\n", 632);
	ft_printf("%0.7o\n", 632);
	printf("\nprintf\t%%+.7o\t(3476) min digits: 7, plus\n%+.7o\n", 3476);
	ft_printf("%+.7o\n", 3476);
	printf("\nprintf\t%% .7o\t(-12) min digits: 7, space\n% .7o\n", -12);
	ft_printf("% .7o\n", -12);
	printf("\nprintf\t%%-.7o\t(15) min digits: 7, minus\n%-.7o\n", 15);
	ft_printf("% .7o\n", 15);
}

/*
**	Asterisk
**	Width && precision
*/

static void asterisk_o(void)
{
	printf("\nAsterisk\n");
	printf("Asterisk PRECISION\n");
	printf("\nprintf\t%%.*o (10, 374)\n%.*o\n", 10, 374);
	ft_printf("%.*o\n", 10, 374);

	printf("\nAsterisk WIDTH\n");
	printf("\nprintf\t%%0*o (11, 798)\n%0*o\n", 11, 798);
	ft_printf("%0*o\n", 11, 798);
}

/*
**	Range check
**	unsigned char			hh	0 - 255
**	unsigned short			h	0 - 65.535
**	unsigned int				0 - 4.294.967.295
**	unsigned long			l	0 - 18.446.744.073.709.551.615
**	unsigned long long		ll	0 - 18.446.744.073.709.551.615
*/

static void	range_check_o(void)
{
	printf("Range check\n");
	//uns char
	printf("\nprintf\t%%hho\tchar (188)\n%hho\n", 188);
	ft_printf("%hho\n", 188);
	printf("\nprintf\t%%hho\tchar (127)\n%hho\n", 127);
	ft_printf("%hho\n", 127);
	printf("\nprintf\t%%hho\tchar (128)\n%hho\n", 128);
	ft_printf("%hho\n", 128);
	printf("\nprintf\t%%hho\tchar (129)\n%hho\n", 129);
	ft_printf("%hho\n", 129);
	//uns char < 0
	printf("\nprintf\t%%hho\tchar < 0 (0)\n%hho\n", 0);
	ft_printf("%hho\n", 0);
	printf("\nprintf\t%%hho\tchar < 0 (-1)\n%hho\n", -1);
	ft_printf("%hho\n", -1);
	printf("\nprintf\t%%hho\tchar < 0 (-2)\n%hho\n", -2);
	ft_printf("%hho\n", -2);
	//uns char > 255
	printf("\nprintf\t%%hho\tchar > 255 (256)\n%hho\n", 256);
	ft_printf("%hho\n", 256);

	//uns short
	printf("\nprintf\t%%ho\tshort (35.748)\n%ho\n", 35748);
	ft_printf("%ho\n", 35748);
	//uns short < 0
	printf("\nprintf\t%%ho\tshort < 0 (-18)\n%ho\n", -18);
	ft_printf("%ho\n", -18);
	//uns short > 63.535
	printf("\nprintf\t%%ho\tshort > 65.535 (65536)\n%ho\n", 65536);
	ft_printf("%ho\n", 65536);


	//uns int
	printf("\nprintf\t%%o\tuns int (28956)\n%o\n", 28956);
	ft_printf("%o\n", 28956);
	//uns int < 0
	printf("\nprintf\t%%o\tuns int (-1)\n%o\n", -1);
	ft_printf("%o\n", -1);
	//uns int > 4.294.967.295
	printf("\nprintf\t%%o\tuns int > 4294967295 (4.294.967.295)\n%o\n", 4294967296);
	ft_printf("%o\n", 4294967296);

	//uns long
	printf("\nprintf\t%%lo\tuns long (789)\n%lo\n", 789);
	ft_printf("%lo\n", 789);
	//uns long < 0
	printf("\nprintf\t%%lo\tuns long < 0 (-2)\n%lo\n", -2);
	ft_printf("%lo\n", -2);
	//uns long > 4.294.967.295
	printf("\nprintf\t%%lo\tuns long > 4.294.967.295 (4294967296)\n%lo\n", 4294967296);
	ft_printf("%lo\n", 4294967296);

	//uns long long
	printf("\nprintf\t%%llo\tuns long long (18.443.744.073.709.551.614)\n%llo\n", 18443744073709551614);
	ft_printf("%llo\n", 18443744073709551614);
	//uns long long < 0
	printf("\nprintf\t%%llo\tuns long long < 0 (-1)\n%llo\n", -1);
	ft_printf("%llo\n", -1);


	//uns long long > 18.466.744.073.709.551.615
/*	printf("\nprintf\t%%llo\tuns long long > 18.446.744.073.709.551.615\n%llo\n", 18446744073709551616);
	ft_printf("%llo\n", 18446744073709551616);
	GEEFT EEN ERROR
*/
}

int		main(void)
{
	simple_test_o();
//	padding_test_o();
//	plus_sign_test_o();
//	combi_plus_space_zero_o();
//	precision_o();
//	asterisk_o();
//	range_check_o();
	return (0);
}
