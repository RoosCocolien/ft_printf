/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_x.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/11 19:43:42 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
** indien spec == 'p', change settings of the flags
*/

static void		simple_p(void)
{
	char *str1;

	str1 = "Roos";
	printf("%%x (printf)\n%x.\n", str1);
	ft_printf("%x.\n", str1);
}

static void		flags_p(void)
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

static void		precision_p(void)
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

static void		padding_p(void)
{
	char *str1;

	str1 = "hrkp";
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

	printf("\n%%015+x (printf)\n");
	printf("%015+x.\n", str1);
	ft_printf("%015+x.\n", str1);
}

int		main(void)
{
	simple_p();
	flags_p();
	precision_p();
	padding_p();
	return (0);
}
