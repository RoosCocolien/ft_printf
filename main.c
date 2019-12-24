/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/23 14:02:05 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/24 14:09:45 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include <math.h>

static void	check_f()
{
	double f;
	double g;
	long double lf;
	long double lf2;

	lf = INFINITY;
	ft_printf("[%+Lf]\n", lf);
	printf("{%+Lf}\n", lf);
	ft_printf("[% Lf]\n", lf);
	printf("{% Lf}\n", lf);
	lf = -0.0L;
	ft_printf("[%Lf]\n", lf);
	printf("{%Lf}\n", lf);
	lf2 = 0.0L;
	ft_printf("[%Lf]\n", lf2);
	printf("{%Lf}\n", lf2);
	f = -0.0;
	g = 0.0;
	printf("\n%0#4.0f$\t(%%0#4.0f\t-0.0\tprintf)\n", f);
	ft_printf("%0#4.0f$\t(%%0#4.0f\t-0.0\tft_printf)\n", f);
	printf("\n%5.0#f$\t(%%5.0#f\t-0.0\tprintf)\n", f);
	ft_printf("%5.0#f$\t(%%5.0#f\t-0.0\tft_printf)\n", f);
	printf("\n%5.0f$\t(%%5.0f\t-0.0\tprintf)\n", f);
	ft_printf("%5.0f$\t(%%5.0f\t-0.0\tft_printf)\n", f);
	printf("\n%.0#f$\t(%%.0#f\t-0.0\tprintf)\n", f);
	ft_printf("%.0#f$\t(%%.0#f\t-0.0\tft_printf)\n", f);
	printf("\n%.0f$\t(%%.0f\t-0.0\tprintf)\n", f);
	ft_printf("%.0f$\t(%%.0f\t-0.0\tft_printf)\n", f);
	printf("\n%0#4.0f$\t(%%0#4.0f\t5.3\tprintf)\n", 5.3);
	ft_printf("%0#4.0f$\t(%%0#4.0f\t5.3\tft_printf)\n", 5.3);
	printf("\n%#1.0f$\t(%%#1.0f\t-0.0\tprintf)\n", f);
	ft_printf("%#1.0f$\t(%%#1.0f\t-0.0\tft_printf)\n", f);
	printf("\n%#2.0f$\t(%%#2.0f\t-0.0\tprintf)\n", f);
	ft_printf("%#2.0f$\t(%%#2.0f\t-0.0\tft_printf)\n", f);
	printf("\n%#0.0f$\t(%%#0.0f\t-0.0\tprintf)\n", f);
	ft_printf("%#0.0f$\t(%%#0.0f\t-0.0\tft_printf)\n", f);
	printf("\n%#.0f$\t(%%#.0f\t-0.0\tprintf)\n", f);
	ft_printf("%#.0f$\t(%%#.0f\t-0.0\tft_printf)\n", f);
	printf("\n%0#4.0f$\t(%%0#4.0f\t0.0\tprintf)\n", g);
	ft_printf("%0#4.0f$\t(%%0#4.0f\t0.0\tft_printf)\n", g);
	printf("\n%5.0#f$\t(%%5.0#f\t0.0\tprintf)\n", g);
	ft_printf("%5.0#f$\t(%%5.0#f\t0.0\tft_printf)\n", g);
	printf("\n%5.0f$\t(%%5.0f\t0.0\tprintf)\n", g);
	ft_printf("%5.0f$\t(%%5.0f\t0.0\tft_printf)\n", g);
	printf("\n%.0#f$\t(%%.0#f\t0.0\tprintf)\n", g);
	ft_printf("%.0#f$\t(%%.0#f\t0.0\tft_printf)\n", g);
	printf("\n%.0f$\t(%%.0f\t0.0\tprintf)\n", g);
	ft_printf("%.0f$\t(%%.0f\t0.0\tft_printf)\n", g);
	long double lf_nan;
	long double lf_inf;
	int retp;
	int retftp;
	lf_nan = NAN;
	retftp = ft_printf("[% 8Lf]\n", lf_nan);
	printf("return: %d\n", retftp);
	retp = printf("{% 8Lf}\n", lf_nan);
	printf("return: %d\n", retp);
	retftp = ft_printf("[%Lf]\n", lf_nan);
	printf("return: %d\n", retftp);
	retp = printf("{%Lf}\n", lf_nan);
	printf("return: %d\n", retp);
	lf_inf = INFINITY;
	ft_printf("[%+Lf]\n", lf_inf);
	printf("{%+Lf}\n", lf_inf);
	printf("\n%.0f$\t(%%.0f\t0.0\tprintf)\n", 0.0);
	ft_printf("%.0f$\t(%%.0f\t0.0\tft_printf)\n", 0.0);
	printf("\n% 10.0f$\t(%% 10.0f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("% 10.0f$\t(%% 10.0f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n%10f$\t(%%10f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("%10f$\t(%%10f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n% 10f$\t(%% 10f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("% 10f$\t(%% 10f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n% 8f$\t(%% 8f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("% 8f$\t(%% 8f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n%8f$\t(%%8f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("%8f$\t(%%8f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n%.0f$\t(%%.0f\t1/0.0\tprintf)\n", 1 / 0.0);
	ft_printf("%.0f$\t(%%.0f\t1/0.0\tft_printf)\n", 1 / 0.0);
	printf("\n%.0f$\t(%%.0f\t-1/0.0\tprintf)\n", -1 / 0.0);
	ft_printf("%.0f$\t(%%.0f\t-1/0.0\tft_printf)\n", -1 / 0.0);
	printf("\n%.0f$\t(%%.0f\t-45/0.0\tprintf)\n", -45 / 0.0);
	ft_printf("%.0f$\t(%%.0f\t-45/0.0\tft_printf)\n", -45 / 0.0);
	printf("\n% .1f$\t(%% .1f\t0.0\tprintf)\n", 0.0);
	ft_printf("% .1f$\t(%% .1f\t0.0\tft_printf)\n", 0.0);
	printf("\n% f$\t(%% f\t0.0\tprintf)\n", 0.0);
	ft_printf("% f$\t(%% f\t0.0\tft_printf)\n", 0.0);
	printf("\n%.1f$\t(%%.1f\t0/0.0\tprintf)\n", 0 / 0.0);
	ft_printf("%.1f$\t(%%.1f\t0/0.0\tft_printf)\n", 0 / 0.0);
	printf("\n%.1f$\t(%%.1f\t1/0.0\tprintf)\n", 1 / 0.0);
	ft_printf("%.1f$\t(%%.1f\t1/0.0\tft_printf)\n", 1 / 0.0);
	printf("\n%.1f$\t(%%.1f\t-1/0.0\tprintf)\n", -1 / 0.0);
	ft_printf("%.1f$\t(%%.1f\t-1/0.0\tft_printf)\n", -1 / 0.0);
	printf("\n%f$\t(%%f\tsrt(-1)\tprintf)\n", sqrt(-1));
	ft_printf("%f$\t(%%f\tsrt(-1)\tft_printf)\n", sqrt(-1));
}

static void	check_s(void)
{
	char *str = "hoi";
	printf("\n%*5d$\t(%%*5d\t-15, 34\tprintf)\n", -15, 34);
	ft_printf("%*5d$\t(%%*5d\t-15, 34\tft_printf)\n", -15, 34);
	printf("\n%*5d$\t(%%*5d\t15, 34\tprintf)\n", 15, 34);
	ft_printf("%*5d$\t(%%*5d\t15, 34\tft_printf)\n", 15, 34);
	printf("\n%*d$\t(%%*d\t15, 34\tprintf)\n", 15, 34);
	ft_printf("%*d$\t(%%*d\t15, 34\tft_printf)\n", 15, 34);
	printf("\n%s$\t(%%s\tstr\tprintf)\n", str);
	ft_printf("%s$\t(%%s\tstr\tft_printf)\n", str);
	printf("\n%*s$\t(%%*s\tstr\tprintf)\n", 5, str);
	ft_printf("%*s$\t(%%*s\tstr\tft_printf)\n", 5, str);
	printf("\n%*7s$\t(%%*5s\tstr\tprintf)\n", 5, str);
	ft_printf("%*7s$\t(%%*5s\tstr\tft_printf)\n", 5, str);
	printf("\n%7*s$\t(%%5*s\tstr\tprintf)\n", 5, str);
	ft_printf("%7*s$\t(%%5*s\tstr\tft_printf)\n", 5, str);
	printf("\n%0-*s$\t(%%0-*s\tstr\tprintf)\n", 5, str);
	ft_printf("%0-*s$\t(%%0-*s\tstr\tft_printf)\n", 5, str);
}

static void check_x(void)
{
	int d;
	d = 0;
	printf("\n%5.0X$\n(%%5.0X\t0\tprintf)\n", d);
	ft_printf("%5.0X$\n(%%5.0X\t0\tft_printf)\n", d);
	printf("\n%0.0x$\n(%%0.0x\t0\tprintf)\n", d);
	ft_printf("%0.0x$\n(%%0.0x\t0\tft_printf)\n", d);
	printf("\n%0.0o$\n(%%0.0o\t0\tprintf)\n", d);
	ft_printf("%0.0o$\n(%%0.0o\t0\tft_printf)\n", d);
	printf("\n%0.0d$\n(%%0.0d\t0\tprintf)\n", d);
	ft_printf("%0.0d$\n(%%0.0d\t0\tft_printf)\n", d);
	printf("\n%0.0f$\n(%%0.0f\t0\tprintf)\n", d);
	ft_printf("%0.0f$\n(%%0.0f\t0\tft_printf)\n", d);
	printf("\n%0.0e$\n(%%0.0e\t0\tprintf)\n", d);
	ft_printf("%0.0e$\n(%%0.0e\t0\tft_printf)\n", d);
	printf("\n%0.0p$\n(%%0.0p\t0\tprintf)\n", d);
	ft_printf("%0.0p$\n(%%0.0p\t0\tft_printf)\n", d);
	printf("\n%0.0s$\n(%%0.0s\t0\tprintf)\n", d);
	ft_printf("%0.0s$\n(%%0.0s\t0\tft_printf)\n", d);
	printf("\n%0.0c$\n(%%0.0c\t0\tprintf)\n", d);
	ft_printf("%0.0c$\n(%%0.0c\t0\tft_printf)\n", d);
	printf("\n%0.0u$\n(%%0.0u\t0\tprintf)\n", d);
	ft_printf("%0.0u$\n(%%0.0u\t0\tft_printf)\n", d);
	d = 4242;
	printf("\n%0.5X$\n(%%0.5X\t0\tprintf)\n", d);
	ft_printf("%0.5X$\n(%%0.5X\t0\tft_printf)\n", d);
	printf("\n%3.5x$\n(%%3.5x\t0\tprintf)\n", d);
	ft_printf("%3.5x$\n(%%3.5x\t0\tft_printf)\n", d);
	printf("\n%13.5x$\n(%%13.5x\t0\tprintf)\n", d);
	ft_printf("%13.5x$\n(%%13.5x\t0\tft_printf)\n", d);
	printf("\n%3.4x$\n(%%3.4x\t0\tprintf)\n", d);
	ft_printf("%3.4x$\n(%%3.4x\t0\tft_printf)\n", d);
	printf("\n%#25X$\n(%%#25X\t0\tprintf)\n", d);
	ft_printf("%#25X$\n(%%#25X\t0\tft_printf)\n", d);
	printf("\n%#25.0X$\n(%%#25.0X\t0\tprintf)\n", 45);
	ft_printf("%#25.0X$\n(%%#25.0X\t0\tft_printf)\n", 45);
}

static void	check_d(void)
{
	int d;
	d = -666666;
	printf("{%.5d}\n", d);
	ft_printf("[%.5d]\n", d);
	printf("{%.6d}\n", d);
	ft_printf("[%.6d]\n", d);
	printf("{%.#6d}\n", d);
	ft_printf("[%.#6d]\n", d);
	printf("{%.15d}\n", d);
	ft_printf("[%.15d]\n", d);
	printf("{%+05#d}\n", -7);
	ft_printf("[%+05#d]\n", -7);
	d = -4242;
	printf("{%.5d}\n", d);
	ft_printf("[%.5d]\n", d);
	// printf("{%5.12d}\n", d);
	// ft_printf("[%5.12d]\n", d);
	// printf("{%12.7d}\n", d);
	// ft_printf("[%12.7d]\n", d);
	// printf("{%.7d}\n", d);
	// ft_printf("[%.7d]\n", d);
	// int u = 4242;
	// printf("{%12.5u}\n", u);
	// ft_printf("[%12.5u]\n", u);
	// printf("{%12.5o}\n", u);
	// ft_printf("[%12.5o]\n", u);
	// printf("{%12.5x}\n", u);
	// ft_printf("[%12.5x]\n", u);
	// printf("{%5.12d}\n", d);
	// ft_printf("[%5.12d]\n", d);
	// printf("{%.5d}\n", d);
	// ft_printf("[%.5d]\n", d);
	// printf("{%12d}\n", d);
	// ft_printf("[%12d]\n", d);
	// long l = 9223372036854775807;
	// printf("{%-5.*ld}\n", 32, l);
	// ft_printf("[%-5.*ld]\n", 32, l);
}

static void	check_o(void)
{
	int d;
	d = 42;
	ft_printf("%0-5hho", (unsigned char)d);
	long l;
	l = 9223372036854775807;
	ft_printf("[%-5.*lo]\n", 32, l);
	printf("{%-5.*lo}\n", 32, l);
	l = 42;
	ft_printf("[%5.*lo]\n", -5, l);
	printf("{%5.*lo}\n", -5, l);
}

static void	check_p(void)
{
	char *str = "Roos";
	ft_printf("[%p]\n", str);
	printf("{%p}\n", str);
}

static void	check_uu(void)
{
	unsigned int u = 4242;
	ft_printf("[%.0u]\n", u);
	printf("{%.0u}\n", u);	
}

static void check_e(void)
{
	printf("De asterisk werkt niet goed.");
	printf("\nprintf\t%%#*e\t(18, 7.3412)\n%#*e\n", 18, 7.3412);
	ft_printf("%#*e\n", 18, 7.3412);
	printf("\nprintf\t%%#-*e\t(0, 7.3412)\n%#-*e\n", 0, 7.3412);
	ft_printf("%#-*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 0");
	printf("\nprintf\t%%-*e\t(0, 7.3412)\n%-*e\n", 0, 7.3412);
	ft_printf("%-*e\n", 0, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 4");
	printf("\nprintf\t%%-*e\t(4, 7.3412)\n%-*e\n", 4, 7.3412);
	ft_printf("%-*e\n", 4, 7.3412);
	printf("\n- asterisk pointing to width value NO ZERO: 18");
	printf("\nprintf\t%%-*e\t(18, 7.3412)\n%-*e\n", 18, 7.3412);
	ft_printf("%-*e\n", 18, 7.3412);
	printf("\n- asterisk pointing to width value WITH ZERO: 18");
	printf("\nprintf\t%%-0*e\t(18, -7.3412)\n%-0*e\n", 18, -7.3412);
	ft_printf("%-0*e\n", 18, -7.3412);	
}

int		main(void)
{
	// check_f();
	// check_s();
	// check_x();
	check_d();
	// check_o();
	// check_p();
	// check_uu();
	// check_e();
	return (0);
}
