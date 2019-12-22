/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:20:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 17:25:09 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		simple_s(void)
{
	printf("\n%%s (printf)\n");
	printf("%s\n", "roos");
	ft_printf("%s\n", "roos");
}

static void		precision_s(void)
{
	printf("\nprintf\t%%.*s\t\"abcdef\"\n%.*s\n", 3, "abcdef");
	ft_printf("%.*s\n", 3, "abcdef");

	printf("\nMore precision\n");
	//dit doet niks	
	printf("\n%%.7s (printf)\n");
	printf("%.7s\n", "roos");
	ft_printf("%.7s\n", "roos");
	//wat doet dit:
	printf("\n%%.6s (printf)\n");
	printf("%.6s\n", "roosmarijn");
	ft_printf("%.6s\n", "roosmarijn");	
}

static void		padding_s(void)
{
	printf("\n%%-15s (printf)\n");
	printf("%-15s\n", "roos");
	ft_printf("%-15s\n", "roos");

	printf("\n%%015s (printf)\n");
	printf("%015s\n", "roos");
	ft_printf("%015s\n", "roos");

	//if I use the '-' && the width '5', then the '0' will do nothing
	printf("\n%%-015s (printf)\n");
	printf("%-015s\n", "roos");
	ft_printf("%-015s\n", "roos");

	printf("\n%%015-s (printf)\n");
	printf("%015+s\n", "roos");
	ft_printf("%015+s\n", "roos");
}

static void		hash(void)
{
	printf("\n%%#-015s (printf)\n");
	printf("%#-015s\n", "roos");
	ft_printf("%#-015s\n", "roos");
	printf("\n%%#015-s (printf)\n");
	printf("%#015+s\n", "roos");
	ft_printf("%#015+s\n", "roos");
	printf("\n%%#s (printf)\n");
	printf("%#s\n", "roos");
	ft_printf("%#s\n", "roos");
}

static void		make_test_s(void)
{
	printf("return_pf:\t(%%.3s, NULL)\t%d\n", printf("-pf\n%.3s$\n", NULL));	
	printf("return_fpf:\t(%%.3s, NULL)\t%d\n", ft_printf("fpf\n%.3s$\n", NULL));
	printf("\n");
	printf("return_pf:\t(%%50.3s, NULL)\t%d\n", printf("-pf\n%50.3s$\n", NULL));	
	printf("return_fpf:\t(%%50.3s, NULL)\t%d\n", ft_printf("fpf\n%50.3s$\n", NULL));
	printf("\n");
	printf("return_pf:\t(%%.*s, 3, NULL)\t%d\n", printf("-pf\n%.*s$\n", 3, NULL));	
	printf("return_fpf:\t(%%.*s, 3, NULL)\t%d\n", ft_printf("fpf\n%.*s$\n", 3, NULL));
	printf("\n");
	printf("return_pf:\t(%%50.*s, 3, NULL)\t%d\n", printf("-pf\n%50.*s$\n", 3, NULL));	
	printf("return_fpf:\t(%%50.*s, 3, NULL)\t%d\n", ft_printf("fpf\n%50.*s$\n", 3, NULL));
	printf("\n");
	printf("return_pf:\t(%%.s, \"hide\")\t%d\n", printf("-pf\n%.s$\n", "hide"));	
	printf("return_fpf:\t(%%.s,\"hide\")\t%d\n", ft_printf("fpf\n%.s$\n", "hide"));
	printf("\n");
	printf("return_pf:\t(%%.2s, \"hide\")\t%d\n", printf("-pf\n%.2s$\n", "hide"));	
	printf("return_fpf:\t(%%.2s,\"hide\")\t%d\n", ft_printf("fpf\n%.2s$\n", "hide"));
	printf("\n");
	printf("return_pf:\t(%%.0s, \"hide\")\t%d\n", printf("-pf\n%.0s$\n", "hide"));	
	printf("return_fpf:\t(%%.0s,\"hide\")\t%d\n", ft_printf("fpf\n%.0s$\n", "hide"));
	printf("\n");
}

int main(void)
{
	// simple_s();
	// precision_s();
	// padding_s();
	make_test_s();
	return (0);
}
