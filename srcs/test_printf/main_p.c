/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 15:33:45 by rsteigen      ########   odam.nl         */
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
	printf("%%p (printf)\n%p.\n", str1);
	ft_printf("%p.\n", str1);
}

static void		flags_p(void)
{
	char	*str1;

	str1 = "Roos";
	printf("\nTest flags (#0-+' ') individually\n");
	printf("%%#p (printf #)\n%#p.\n", str1);
//	ft_printf("%#p.\n", str1);
	printf("%%0p (printf 0)\n%0p.\n", str1);
	ft_printf("%0p.\n", str1);
	printf("%%-p (printf -)\n%-p.\n", str1);
	ft_printf("%-p.\n", str1);
	printf("%%+p (printf +)\n%+p.\n", str1);
	ft_printf("%+p.\n", str1);
	printf("%% p (printf ' ')\n% p.\n", str1);
	ft_printf("% p.\n", str1);
	printf("\nTest flag combo's\n");
	printf("%%-+p (printf)\n%-+p.\n", str1);
	ft_printf("%-+p.\n", str1);
	printf("%%+ p (printf)\n%+ p.\n", str1);
	ft_printf("%+ p.\n", str1);
	printf("%%- p (printf)\n%- p.\n", str1);
	ft_printf("%- p.\n", str1);
	printf("%%0+p (printf)\n%0+p.\n", str1);
	ft_printf("%0+p.\n", str1);
	printf("\nTest minimum field width\n");
	printf("%%16p (printf)\n%16p.\n", str1);
	ft_printf("%16p.\n", str1);
	printf("%%3p (printf)\n%3p.\n", str1);
	ft_printf("%3p.\n", str1);
	printf("\nTest minimum field width in combi with other flags\n");
	printf("%%-10p (printf)\n%-10p.\n", str1);
	ft_printf("%-10p.\n", str1);
	printf("%%+6p (printf)\n%+6p.\n", str1);
	ft_printf("%+6p.\n", str1);
	printf("%%12p (printf)\n%12p.\n", str1);
	ft_printf("%12p.\n", str1);
	printf("%%012p (printf)\n%012p.\n", str1);
	ft_printf("%012p.\n", str1);
	printf("%%+-012p (printf)\n%+-012p.\n", str1);
	ft_printf("%+-012p.\n", str1);
	printf("\nTest minimum field width asterisk in combi with other flags\n");
	printf("%%-*p (printf, value: 10)\n%-*p.\n", 10, str1);
	ft_printf("%-*p.\n", 10, str1);
	printf("%%+*p (printf value: 6)\n%+*p.\n", 6, str1);
	ft_printf("%+*p.\n", 6, str1);
	printf("%%*p (printf value: 12)\n%*p.\n", 12, str1);
	ft_printf("%*p.\n", 12, str1);
	printf("%%0*p (printf value: 12)\n%0*p.\n", 12, str1);
	ft_printf("%0*p.\n", 12, str1);
	printf("%%+-0*p (printf value: 12)\n%+-0*p.\n", 12, str1);
	ft_printf("%+-0*p.\n", 12, str1);
}

static void		precision_p(void)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = "Coco";
	str2 = "Lien888";
	str3 = "Roosmarijn";
	// printf("\nPrecision simple test\n");
	// printf("%%.7p (printf)\n%.7p.\n", str1);
	// ft_printf("%.7p.\n", str1);
	// printf("%%.3p (printf)\n%.3p.\n", str1);
	// ft_printf("%.3p.\n", str1);
	// printf("%%.17p (printf)\n%.17p.\n", str1);
	// ft_printf("%.17p.\n", str1);

	printf("\nPrecision simple with asterisk\n");
	printf("%%.*p (printf, value: 7)\n%.*p.\n", 7, str3);
	ft_printf("%.*p.\n", 7, str3);
	printf("%%.*p (printf, value: 3)\n%.*p.\n", 3, str3);
	ft_printf("%.*p.\n", 3, str3);
	printf("%%.*p (printf, value: 17)\n%.*p.\n", 17, str3);
	ft_printf("%.*p.\n", 17, str3);

	printf("\nPrecision combi with flags\n");
	printf("%%.+7p (printf)\n%.+7p.\n", str2);
	ft_printf("%.+7p.\n", str2);
	printf("%%.03p (printf)\n%.03p.\n", str2);
	ft_printf("%.03p.\n", str2);
	printf("%%.-17p (printf)\n%.-17p.\n", str2);
	ft_printf("%.-17p.\n", str2);
	printf("%% .7p (printf)\n% .7p.\n", str1);
	ft_printf("% .7p.\n", str1);
	printf("%%.3+- p (printf)\n%.3+- p.\n", str1);
	ft_printf("%.3+- p.\n", str1);
	printf("%%.17p (printf)\n%.17p.\n", str1);
	ft_printf("%.17p.\n", str1);
	printf("%%.17#p (printf)\n%.17#p.\n", str1);
	ft_printf("%.17#p.\n", str1);

	printf("\nPrecision combi with flags and asterisk\n");
	printf("%%.*p (printf, value: 7)\n%.*p.\n", 7, str3);
	ft_printf("%.*p.\n", 7, str3);
	printf("%%.*p (printf, value: 3)\n%.*p.\n", 3, str3);
	ft_printf("%.*p.\n", 3, str3);
	printf("%%.*p (printf, value: 17)\n%.*p.\n", 17, str3);
	ft_printf("%.*p.\n", 17, str3);
	printf("%%.*p (printf, value: 1)\n%.*p.\n", 1, str3);
	ft_printf("%.*p.\n", 1, str3);
	printf("%%.*p (printf, value: 3)\n%.*p.\n", 5, str3);
	ft_printf("%.*p.\n", 5, str3);
	printf("%%.*p (printf, value: 17)\n%.*p.\n", 17, str3);
	ft_printf("%.*p.\n", 17, str3);
}

static void		padding_p(void)
{
	char *str1;

	str1 = "hrkp";
	printf("\n%%-15p (printf)\n");
	printf("%-15p.\n", str1);
	ft_printf("%-15p.\n", str1);
	printf("\n%%015p (printf)\n");
	printf("%015p.\n", str1);
	ft_printf("%015p.\n", str1);
	//if I use the '-' && the width '15', then the '0' will do nothing
	printf("\n%%-015p (printf)\n");
	printf("%-015p.\n", str1);
	ft_printf("%-015p.\n", str1);

	printf("\n%%015+p (printf)\n");
	printf("%015+p.\n", str1);
	ft_printf("%015+p.\n", str1);
}

static void		troubles(void)
{
	char *str1;
	char *str2;
	char *str3;

	str1 = "Coco";
	str2 = "Lien888";
	str3 = "Roosmarijn";
	printf("%%.*p (printf, value: 17)\n%.*p.\n", 17, str3);
	ft_printf("%.*p.\n", 17, str3);
	printf("%%.*x (printf, value: 17)\n%.*x.\n", 17, str3);
	ft_printf("%.*x.\n", 17, str3);
}

int		main(void)
{
	simple_p();
	flags_p();
	precision_p();
	padding_p();
	troubles();
	return (0);
}
