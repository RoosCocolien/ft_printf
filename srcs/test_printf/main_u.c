/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 16:43:30 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 16:03:19 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
**	Simple test
*/

static void	simple_test_u(void)
{
	printf("\nSimple test\n");
	printf("\nprintf\t%%u\t(532)\n%u\n", 532);
	ft_printf("%u\n", 532);
	printf("\nprintf\t%%u\t(-689)\n%u\n", -689);
	ft_printf("%u\n", -689);
	printf("\nprintf\t%%u\t(4294967295)\n%u\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	printf("\nprintf\t%%u\t(2147483648 (warning: dit is een long))\n%u\n",\
	2147483648);
	ft_printf("%u\n", 2147483648);
	printf("\nprintf\t%%u\t(2147483647)\n%u\n", 2147483647);
	ft_printf("%u\n", 2147483647);
	printf("\nprintf\t%%u\t(0)\n%u\n", 0);
	ft_printf("%u\n", 0);
}

/*
**	Padding test (width)
*/

static void	padding_test_u(void)
{
	printf("\nWidth flag\n");
	printf("\nprintf\t%%7u\t(689) width: 7\n%7u\n", 689);
	ft_printf("%7u\n", 689);
	printf("\nprintf\t%%07u\t(5421) witdh: 7, 0 fill\n%07u\n", 5421);
	ft_printf("%07u\n", 5421);
	printf("\nprintf\t%%0-7u\t(-34) witdh: 7, 0 fill, left aligned\
	\n%0-7u\n", -34);
	ft_printf("%0-7u\n", -34);
	printf("Note: flag '0' is ignored when flag '-' is used.\n");
	printf("\nprintf\t%%-7u\t(427) witdh: 7, no fill, left aligned\
	\n%-7u\n", 427);
	ft_printf("%-7u\n", 427);
}

/*
**	Requesting a plus sign (+) in case of positive numbers
**	Completely ignored, because it is unsigned
*/

static void	plus_sign_test_u(void)
{
	printf("\nPlus flag\n");
	printf("\nprintf\t%%+8u\t(327) width: 8, flag: +\n%+8u\n", 327);
	ft_printf("%+8u\n", 327);
	printf("\nprintf\t%%+8u\t(0) width: 8, flag: +\n%+8u\n", 0);
	ft_printf("%+8u\n", 0);
	printf("\nprintf\t%%+8u\t(-327) width: 8, flag: +\n%+8u\n", -327);
	ft_printf("%+8u\n", -327);
	printf("\nprintf\t%%+8u\t(56) flag: + (visible), align left\n%+-u\n", 56);
	ft_printf("%+-u\n", 56);
	printf("\nprintf\t%%+8u\t(998)\
	invisible plus ' ', align left '-'\n% -u\n", 998);
	ft_printf("% -u\n", 998);
	printf("\nprintf\t%%- u\t(-435)\
	invisible plus ' ', align left '-', neg nb\n%- u\n", -435);
	ft_printf("%- u\n", -435);
}

static void	combi_plus_space_zero_u(void)
{
	printf("\nCombination of plus, space, zero\n");
	printf("\nprintf\t%% 05u\t(0)\
	Invisible plus sign, fill 0, width 5\n% 05u\n", 0);
	ft_printf("% 05u\n", 0);
	printf("\nprintf\t%% 05u\t(-461)\
	Invisible plus sign, fill 0, width 5\n% 05u\n", -461);
	ft_printf("% 05u\n", -461);
	printf("\nprintf\t%%+05u\t(38)\
	Visible plus sign, fill 0, width 5\n%+05u\n", 38);
	ft_printf("%+05u\n", 38);
	printf("\nprintf\t%%+05u\t(97)\
	Visible plus sign, fill 0, width 5:\n%+05u\n", 97);
	ft_printf("%+05u\n", 97);
}

/*
**	Precision
**	The min nb of digits to be printed. Leading zeros will be added to
**	make up the field with.
**	All other flags ('-', '+', ' ', '-') will be ignored.
*/

static void	precision_u(void)
{
	printf("\nPrecision\n");
	printf("\nprintf\t%%.7u\t(354) min digits: 7\n%.7u\n", 354);
	ft_printf("%.7u\n", 354);
	printf("\nprintf\t%%-.7u\t(997) min digits: 7, align left ('-')\n%-.7u\n",\
	997);
	ft_printf("%-.7u\n", 997);
	printf("\nprintf\t%%0.7u\t(997) min digits: 7, zero\n%0.7u\n", 632);
	ft_printf("%0.7u\n", 632);
	printf("\nprintf\t%%+.7u\t(3476) min digits: 7, plus\n%+.7u\n", 3476);
	ft_printf("%+.7u\n", 3476);
	printf("\nprintf\t%% .7u\t(-12) min digits: 7, space\n% .7u\n", -12);
	ft_printf("% .7u\n", -12);
	printf("\nprintf\t%%-.7u\t(15) min digits: 7, minus\n%-.7u\n", 15);
	ft_printf("% .7u\n", 15);
}

/*
**	Asterisk
**	Width && precision
*/

static void asterisk_u(void)
{
	printf("\nAsterisk\n");
	printf("Asterisk PRECISION");
	printf("\nprintf\t%%.*u (10, 374)\n%.*u\n", 10, 374);
	ft_printf("%.*u\n", 10, 374);

	printf("Asterisk WIDTH");
	printf("\nprintf\t%%0*u (11, 798)\n%0*u\n", 11, 798);
	ft_printf("%0*u\n", 11, 798);
}

/*
**	Range check
**	unsigned char			hh	0 - 255
**	unsigned short			h	0 - 65.535
**	unsigned int				0 - 4.294.967.295
**	unsigned long			l	0 - 18.446.744.073.709.551.615
**	unsigned long long		ll	0 - 18.446.744.073.709.551.615
*/

static void	range_check_u(void)
{
	printf("Range check\n");
	//uns char
	printf("\nprintf\t%%hhu\tchar (188)\n%hhu\n", 188);
	ft_printf("%hhu\n", 188);
	//uns char < 0
	printf("\nprintf\t%%hhu\tchar < 0 (-2)\n%hhu\n", -2);
	ft_printf("%hhu\n", -2);
	//uns char > 255
	printf("\nprintf\t%%hhu\tchar > 255 (256)\n%hhu\n", 256);
	ft_printf("%hhu\n", 256);

	//uns short
	printf("\nprintf\t%%hu\tshort (35.748)\n%hu\n", 35748);
	ft_printf("%hu\n", 35748);
	//uns short < 0
	printf("\nprintf\t%%hu\tshort < 0 (-18)\n%hu\n", -18);
	ft_printf("%hu\n", -18);
	//uns short > 63.535
	printf("\nprintf\t%%hu\tshort > 65.535 (65536)\n%hu\n", 65536);
	ft_printf("%hu\n", 65536);

	//uns int
	printf("\nprintf\t%%u\tuns int (28956)\n%u\n", 28956);
	ft_printf("%u\n", 28956);
	//uns int < 0
	printf("\nprintf\t%%u\tuns int (-1)\n%u\n", -1);
	ft_printf("%u\n", -1);
	//uns int > 4.294.967.295
	printf("\nprintf\t%%u\tuns int > 4294967295 (4.294.967.295)\n%u\n", 4294967296);
	ft_printf("%u\n", 4294967296);

	//uns long
	printf("\nprintf\t%%lu\tuns long (789)\n%lu\n", 789);
	ft_printf("%lu\n", 789);
	//uns long < 0
	printf("\nprintf\t%%lu\tuns long < 0 (-2)\n%lu\n", -2);
	ft_printf("%lu\n", -2);
	//uns long > 4.294.967.295
	printf("\nprintf\t%%lu\tuns long > 4.294.967.295 (4294967296)\n%lu\n", 4294967296);
	ft_printf("%lu\n", 4294967296);

	//uns long long
	printf("\nprintf\t%%llu\tuns long long (18.443.744.073.709.551.614)\n%llu\n", 18443744073709551614);
	ft_printf("%llu\n", 18443744073709551614);
	//uns long long < 0
	printf("\nprintf\t%%llu\tuns long long < 0 (-1)\n%llu\n", -1);
	ft_printf("%llu\n", -1);

	//uns long long > 18.466.744.073.709.551.615
/*	printf("\nprintf\t%%llu\tuns long long > 18.446.744.073.709.551.615\n%llu\n", 18446744073709551616);
	ft_printf("%llu\n", 18446744073709551616);
	GEEFT EEN ERROR
*/
}

static void hash_u(void)
{
	printf("\n**hash**\n");
	printf("\nprintf\t%%#u\t(532)\n%#u\n", 532);
	ft_printf("%#u\n", 532);
	printf("\nprintf\t%%#u\t(-689)\n%#u\n", -689);
	ft_printf("%#u\n", -689);
	printf("\nprintf\t%%#.*u (10, 374)\n%#.*u\n", 10, 374);
	ft_printf("%#.*u\n", 10, 374);
	printf("\nprintf\t%%#0*u (11, 798)\n%#0*u\n", 11, 798);
	ft_printf("%#0*u\n", 11, 798);
}

int		main(void)
{
	simple_test_u();
//	padding_test_u();
//	plus_sign_test_u();
//	combi_plus_space_zero_u();
//	precision_u();
//	asterisk_u();
//	range_check_u();
	hash_u();
	return (0);
}
