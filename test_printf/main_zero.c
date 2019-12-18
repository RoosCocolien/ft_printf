/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_zero.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:58:16 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/18 17:24:53 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

static void		flag_simple_zero_d_f(void)
{
	int	int_zero;
	long long_zero;
	long long long_long_zero;
	double	double_zero;
	long double long_double_zero;
	float float_zero;

	int_zero = 0;
	long_zero = 0;
	long_long_zero = 0;
	double_zero = 0.0;
	long_double_zero = 0.0;
	float_zero = 0.0;
	ft_printf("flag_Simple zero D\n\n");
	ft_printf("int\t0\n");
	printf("printf\n%d\n", int_zero);
	ft_printf("%d\n", int_zero);
	ft_printf("long int\t0\n");
	printf("printf\n%ld\n", long_zero);
	ft_printf("%ld\n", long_zero);
	ft_printf("long long int\t0\n");
	printf("printf\n%lld\n", long_long_zero);
	ft_printf("%lld\n", long_long_zero);
	ft_printf("double zero\t0.0\n");
	printf("printf\n%f\n", double_zero);
	ft_printf("%f\n", double_zero);
	ft_printf("long double zero\t0.0\n");
	printf("printf =\n%Lf\n", long_double_zero);
	ft_printf("%Lf\n", long_double_zero);
	ft_printf("float zero\t0.0\n");
	printf("printf\n%f\n", float_zero);
	ft_printf("%f\n", float_zero);
}

static void		flag_simple_zero_e(void)
{
	double	double_zero;
	long double long_double_zero;

	double_zero = 0.0;
	long_double_zero = 0.0;
	ft_printf("\n\nflag_Simple zero E\n\n");
	ft_printf("double zero\t0.0\n");
	printf("printf\n%e\n", double_zero);
	ft_printf("%e\n", double_zero);
	ft_printf("long double zero\t0.0\n");
	printf("printf\n%Le\n", long_double_zero);
	ft_printf("%Le\n", long_double_zero);
	ft_printf("float zero\t0.0\n");
}

static void		flag_simple_zero_o(void)
{
	int	int_zero;
	long long_zero;
	long long long_long_zero;

	int_zero = 0;
	long_zero = 0;
	long_long_zero = 0;
	ft_printf("\n\nflag_Simple zero o\n\n");
	ft_printf("int\t0\n");
	printf("printf\n%o\n", int_zero);
	ft_printf("%o\n", int_zero);
	ft_printf("long int\t0\n");
	printf("printf\n%lo\n", long_zero);
	ft_printf("%lo\n", long_zero);
	ft_printf("long long int\t0\n");
	printf("printf\n%llo\n", long_long_zero);
	ft_printf("%llo\n", long_long_zero);
}

static void		flag_simple_zero_u(void)
{
	int	int_zero;
	long long_zero;
	long long long_long_zero;

	int_zero = 0;
	long_zero = 0;
	long_long_zero = 0;
	ft_printf("\n\nflag_Simple zero u\n\n");
	ft_printf("int\t0\n");
	printf("printf\n%u\n", int_zero);
	ft_printf("%u\n", int_zero);
	ft_printf("long int\t0\n");
	printf("printf\n%lu\n", long_zero);
	ft_printf("%lu\n", long_zero);
	ft_printf("long long int\t0\n");
	printf("printf\n%llu\n", long_long_zero);
	ft_printf("%llu\n", long_long_zero);
}

int				main(void)
{
	flag_simple_zero_d_f();
	flag_simple_zero_e();
	flag_simple_zero_o();
	flag_simple_zero_u();
	return (0);
}
