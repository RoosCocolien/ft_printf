/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 17:25:00 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "limits.h"

/*
** indien spec == 'p', change settings of the flags
*/

static void		simple_x(void)
{
	char *str1;

	str1 = "Roos";
	printf("%%x (printf)\n%x.\n", str1);
	ft_printf("%x.\n", str1);
}

static void		flags_x(void)
{
	char	*str1;

	str1 = "Roos";
	printf("\nTest flags (#0-+' ') individually\n");
	printf("%%#x (printf #)\n%#x.\n", str1);
	ft_printf("%#x.\n", str1);
	printf("%%0x (printf 0)\n%0x.\n", str1);
	ft_printf("%0x.\n", str1);
	printf("%%-x (printf -)\n%-x.\n", str1);
	ft_printf("%-x.\n", str1);
	printf("%%+x (printf +)\n%+x.\n", str1);
	ft_printf("%+x.\n", str1);
	printf("%% x (printf ' ')\n% x.\n", str1);
	ft_printf("% x.\n", str1);
	printf("\nTest flag combo's\n");
	printf("%%-+x (printf)\n%-+x.\n", str1);
	ft_printf("%-+x.\n", str1);
	printf("%%+ x (printf)\n%+ x.\n", str1);
	ft_printf("%+ x.\n", str1);
	printf("%%- x (printf)\n%- x.\n", str1);
	ft_printf("%- x.\n", str1);
	printf("%%0+x (printf)\n%0+x.\n", str1);
	ft_printf("%0+x.\n", str1);
	printf("\nTest minimum field width\n");
	printf("%%16x (printf)\n%16x.\n", str1);
	ft_printf("%16x.\n", str1);
	printf("%%3x (printf)\n%3x.\n", str1);
	ft_printf("%3x.\n", str1);
	printf("\nTest minimum field width in combi with other flags\n");
	printf("%%-10x (printf)\n%-10x.\n", str1);
	ft_printf("%-10x.\n", str1);
	printf("%%+6x (printf)\n%+6x.\n", str1);
	ft_printf("%+6x.\n", str1);
	printf("%%12x (printf)\n%12x.\n", str1);
	ft_printf("%12x.\n", str1);
	printf("%%012x (printf)\n%012x.\n", str1);
	ft_printf("%012x.\n", str1);
	printf("%%+-012x (printf)\n%+-012x.\n", str1);
	ft_printf("%+-012x.\n", str1);
	printf("\nTest minimum field width asterisk in combi with other flags\n");
	printf("%%-*x (printf, value: 10)\n%-*x.\n", 10, str1);
	ft_printf("%-*x.\n", 10, str1);
	printf("%%+*x (printf value: 6)\n%+*x.\n", 6, str1);
	ft_printf("%+*x.\n", 6, str1);
	printf("%%*x (printf value: 12)\n%*x.\n", 12, str1);
	ft_printf("%*x.\n", 12, str1);
	printf("%%0*x (printf value: 12)\n%0*x.\n", 12, str1);
	ft_printf("%0*x.\n", 12, str1);
	printf("%%+-0*x (printf value: 12)\n%+-0*x.\n", 12, str1);
	ft_printf("%+-0*x.\n", 12, str1);
}

static void		precision_x(void)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = "Coco";
	str2 = "Lien888";
	str3 = "Roosmarijn";
	printf("\nPrecision simple test\n");
	printf("%%.7x (printf)\n%.7x.\n", str1);
	ft_printf("%.7x.\n", str1);
	printf("%%.3x (printf)\n%.3x.\n", str1);
	ft_printf("%.3x.\n", str1);
	printf("%%.17x (printf)\n%.17x.\n", str1);
	ft_printf("%.17x.\n", str1);

	printf("\nPrecision simple with asterisk\n");
	printf("%%.*x (printf, value: 7)\n%.*x.\n", 7, str3);
	ft_printf("%.*x.\n", 7, str3);
	printf("%%.*x (printf, value: 3)\n%.*x.\n", 3, str3);
	ft_printf("%.*x.\n", 3, str3);
	printf("%%.*x (printf, value: 17)\n%.*x.\n", 17, str3);
	ft_printf("%.*x.\n", 17, str3);

	printf("\nPrecision combi with flags\n");
	printf("%%.+7x (printf)\n%.+7x.\n", str2);
	ft_printf("%.+7x.\n", str2);
	printf("%%.03x (printf)\n%.03x.\n", str2);
	ft_printf("%.03x.\n", str2);
	printf("%%.-17x (printf)\n%.-17x.\n", str2);
	ft_printf("%.-17x.\n", str2);
	printf("%% .7x (printf)\n% .7x.\n", str1);
	ft_printf("% .7x.\n", str1);
	printf("%%.3+- x (printf)\n%.3+- x.\n", str1);
	ft_printf("%.3+- x.\n", str1);
	printf("%%.17x (printf)\n%.17x.\n", str1);
	ft_printf("%.17x.\n", str1);
	printf("%%.17#x (printf)\n%.17#x.\n", str1);
	ft_printf("%.17#x.\n", str1);

	printf("\nPrecision combi with flags and asterisk\n");
	printf("%%.*x (printf, value: 7)\n%.*x.\n", 7, str3);
	ft_printf("%.*x.\n", 7, str3);
	printf("%%.*x (printf, value: 3)\n%.*x.\n", 3, str3);
	ft_printf("%.*x.\n", 3, str3);
	printf("%%.*x (printf, value: 17)\n%.*x.\n", 17, str3);
	ft_printf("%.*x.\n", 17, str3);
	printf("%%.*x (printf, value: 1)\n%.*x.\n", 1, str3);
	ft_printf("%.*x.\n", 1, str3);
	printf("%%.*x (printf, value: 3)\n%.*x.\n", 5, str3);
	ft_printf("%.*x.\n", 5, str3);
	printf("%%.*x (printf, value: 17)\n%.*x.\n", 17, str3);
	ft_printf("%.*x.\n", 17, str3);
}

static void		padding_x(void)
{
	char *str1;
	char *str2;

	str1 = "hrkp";
	str2 = "482";
	printf("\n%%-15x (printf)\n");
	printf("%-15x.\n", str1);
	ft_printf("%-15x.\n", str1);

	printf("\n%%015x (printf)\n");
	printf("%015x.\n", str1);
	ft_printf("%015x.\n", str1);

	//if I use the '-' && the width '15', then the '0' will do nothing
	printf("\n%%-015x (printf)\n");
	printf("%-015x.\n", str1);
	ft_printf("%-015x.\n", str1);

	printf("\n%%015x (printf)\n");
	printf("%015x.\n", str1);
	ft_printf("%015x.\n", str1);

	printf("\n%%15x (printf)\n");
	printf("%15x.\n", str1);
	ft_printf("%15x.\n", str1);

	printf("\n%%015+x (printf)\n");
	printf("%015+x.\n", str1);
	ft_printf("%015+x.\n", str1);
	
	printf("return_pf:\t(%%9.0x)\t%d\n", printf("%9.0x$\n", str2));
	printf("return_fpf:\t(%%9.0x)\t%d\n", ft_printf("%9.0x$\n", str2));
	printf("\n");
	printf("return_pf:\t(%%.0x)\t%d\n", printf("%.0x$\n", str2));
	printf("return_fpf:\t(%%.0x)\t%d\n", ft_printf("%.0x$\n", str2));
	printf("\n");
	printf("return_pf:\t(%%9x)\t%d\n", printf("%9x$\n", str2));
	printf("return_fpf:\t(%%9x)\t%d\n", ft_printf("%9x$\n", str2));
	printf("\n");
	printf("return_pf:\t(%%09x)\t%d\n", printf("%09x$\n", str2));
	printf("return_fpf:\t(%%09x)\t%d\n", ft_printf("%09x$\n", str2));
	printf("\n");
	printf("return_pf:\t(%%09.0X)\t%d\n", printf("%09.0X$\n", 482));
	printf("return_fpf:\t(%%09.0X)\t%d\n", ft_printf("%09.0X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%#09.0X)\t%d\n", printf("%#09.0X$\n", 482));
	printf("return_fpf:\t(%%#09.0X)\t%d\n", ft_printf("%#09.0X$\n", 482));
	printf("\n");
}

static void		check_hash_x(void)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = "Coco";
	str2 = "Lien888";
	str3 = "Roosmarijn";
	printf("\nTest minimum field width asterisk & hash in combi with other flags\n");
	printf("%%-*#x (printf, value: 10)\n%-*#x.\n", 10, str1);
	ft_printf("%-*#x.\n", 10, str1);
	printf("%%+*#x (printf value: 6)\n%+*#x.\n", 6, str1);
	ft_printf("%+*#x.\n", 6, str1);
	printf("%%*#x (printf value: 12)\n%*#x.\n", 12, str1);
	ft_printf("%*#x.\n", 12, str1);
	printf("%%0*#x (printf value: 12)\n%0*#x.\n", 12, str1);
	ft_printf("%0*#x.\n", 12, str1);
	printf("%%+-0*#x (printf value: 12)\n%+-0*#x.\n", 12, str1);
	ft_printf("%+-0*#x.\n", 12, str1);
	printf("\nPadding with hash\n");
	printf("\n%%-15#x (printf)\n");
	printf("%-15#x.\n", str1);
	ft_printf("%-15#x.\n", str1);
	printf("\n%%015#x (printf)\n");
	printf("%015#x.\n", str1);
	ft_printf("%015#x.\n", str1);
	printf("%%-*#X (printf, value: 10)\n%-*#X.\n", 10, str1);
	ft_printf("%-*#X.\n", 10, str1);
	printf("%%+*#X (printf value: 6)\n%+*#X.\n", 6, str1);
	ft_printf("%+*#X.\n", 6, str1);
	printf("%%*#X (printf value: 12)\n%*#X.\n", 12, str1);
	ft_printf("%*#X.\n", 12, str1);
	printf("%%0*#X (printf value: 12)\n%0*#X.\n", 12, str1);
	ft_printf("%0*#X.\n", 12, str1);
	printf("%%+-0*#X (printf value: 12)\n%+-0*#X.\n", 12, str1);
	ft_printf("%+-0*#X.\n", 12, str1);
	printf("\nPadding with hash\n");
	printf("\n%%-15#X (printf)\n");
	printf("%-15#X.\n", str1);
	ft_printf("%-15#X.\n", str1);
}

static void		make_test_x(void)
{
	printf("return_pf:\t(%%x)\t%d\n", printf("%x\n", 0));
	printf("return_fpf:\t(%%x)\t%d\n", ft_printf("%x\n", 0));
	printf("\n");
	printf("return_pf:\t(%%x)\t%d\n", printf("%x\n", -42));
	printf("return_fpf:\t(%%x)\t%d\n", ft_printf("%x\n", -42));
	printf("\nlength modifiers (gaat wel goed bij conv spec 'u'\n");
	printf("\n");
	printf("return_pf:\t(%%x)\t%d\n", printf("%x\n", UINT_MAX));
	printf("return_fpf:\t(%%x)\t%d\n", ft_printf("%x\n", UINT_MAX));
	printf("\n");
	printf("return_pf:\t(%%x)\t%d\n", printf("%x\n", UINT_MAX + 12));
	printf("return_fpf:\t(%%x)\t%d\n", ft_printf("%x\n", UINT_MAX + 12));
	printf("\n");
	printf("return_pf:\t(%%lx)\t%d\n", printf("%lx\n", ULONG_MAX - 1));
	printf("return_fpf:\t(%%lx)\t%d\n", ft_printf("%lx\n", ULONG_MAX - 1));
	printf("\n");
	printf("return_pf:\t(%%lx)\t%d\n", printf("%lx\n", ULONG_MAX));
	printf("return_fpf:\t(%%lx)\t%d\n", ft_printf("%lx\n", ULONG_MAX));
	printf("\n");
	printf("return_pf:\t(%%lx)\t%d\n", printf("%lx\n", ULONG_MAX + 5));
	printf("return_fpf:\t(%%lx)\t%d\n", ft_printf("%lx\n", ULONG_MAX + 5));
	printf("\n");
	printf("return_pf:\t(%%#.5x (0))\t%d\n", printf("%#.5x$\n", 0));
	printf("return_fpf:\t(%%#.5x (0))\t%d\n", ft_printf("%#.5x$\n", 0));
	printf("\n");
	printf("return_pf:\t(%%#.5x (32))\t%d\n", printf("%#.5x$\n", 32));
	printf("return_fpf:\t(%%#.5x (32))\t%d\n", ft_printf("%#.5x$\n", 32));
	printf("\n");
	printf("return_pf:\t(%%.5x (32))\t%d\n", printf("%.5x$\n", 32));
	printf("return_fpf:\t(%%.5x (32))\t%d\n", ft_printf("%.5x$\n", 32));
	printf("\n");
	printf("return_pf:\t(%%.5x (32))\t%d\n", printf("%.5x$\n", 32));
	printf("return_fpf:\t(%%.5x (32))\t%d\n", ft_printf("%.5x$\n", 32));
	printf("\n");
	printf("return_pf:\t(%%#09.0X)\t%d\n", printf("%#09.0X$\n", 482));
	printf("return_fpf:\t(%%#09.0X)\t%d\n", ft_printf("%#09.0X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%09X)\t%d\n", printf("%09X$\n", 482));
	printf("return_fpf:\t(%%09X)\t%d\n", ft_printf("%09X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%#09X)\t%d\n", printf("%#09X$\n", 482));
	printf("return_fpf:\t(%%#09X)\t%d\n", ft_printf("%#09X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%09.0X)\t%d\n", printf("%09.0X$\n", 482));
	printf("return_fpf:\t(%%09.0X)\t%d\n", ft_printf("%09.0X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%#9X)\t%d\n", printf("%#9X$\n", 482));
	printf("return_fpf:\t(%%#9X)\t%d\n", ft_printf("%#9X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%#.9X)\t%d\n", printf("%#.9X$\n", 482));
	printf("return_fpf:\t(%%#.9X)\t%d\n", ft_printf("%#.9X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%9X)\t%d\n", printf("%9X$\n", 482));
	printf("return_fpf:\t(%%9X)\t%d\n", ft_printf("%9X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%.9X)\t%d\n", printf("%.9X$\n", 482));
	printf("return_fpf:\t(%%.9X)\t%d\n", ft_printf("%.9X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%9.0X)\t%d\n", printf("%9.0X$\n", 482));
	printf("return_fpf:\t(%%9.0X)\t%d\n", ft_printf("%9.0X$\n", 482));
	printf("\n");
	printf("return_pf:\t(%%09X)\t%d\n", printf("%09X$\n", 482));
	printf("return_fpf:\t(%%09X)\t%d\n", ft_printf("%09X$\n", 482));
	printf("\n");
}

int		main(void)
{
	simple_x();
	flags_x();
	precision_x();
	padding_x();
	check_hash_x();
	make_test_x();
	return (0);
}
