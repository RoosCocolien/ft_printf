/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_zero.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 18:58:16 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/01 16:11:14 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

// static void		simple_zero_d(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("Simple zero D\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%d\n", int_zero);
// 	ft_printf("Neppe printf =\t%d\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%d\n", long_zero);
// 	ft_printf("Neppe printf =\t%d\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%d\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%d\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%d\n", double_zero);
// 	ft_printf("Neppe printf =\t%d\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%d\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%d\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%d\n", float_zero);
// 	ft_printf("Neppe printf =\t%d\n", float_zero);
// }

// static void		simple_zero_f(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero F\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%f\n", int_zero);
// 	ft_printf("Neppe printf =\t%f\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%f\n", long_zero);
// 	ft_printf("Neppe printf =\t%f\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%f\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%f\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%f\n", double_zero);
// 	ft_printf("Neppe printf =\t%f\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%f\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%f\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%f\n", float_zero);
// 	ft_printf("Neppe printf =\t%f\n", float_zero);
// }

// static void		simple_zero_e(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero E\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%e\n", int_zero);
// 	ft_printf("Neppe printf =\t%e\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%e\n", long_zero);
// 	ft_printf("Neppe printf =\t%e\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%e\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%e\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%e\n", double_zero);
// 	ft_printf("Neppe printf =\t%e\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%e\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%e\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%e\n", float_zero);
// 	ft_printf("Neppe printf =\t%e\n", float_zero);
// }

// static void		simple_zero_g(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero G\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%g\n", int_zero);
// 	ft_printf("Neppe printf =\t%g\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%g\n", long_zero);
// 	ft_printf("Neppe printf =\t%g\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%g\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%g\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%g\n", double_zero);
// 	ft_printf("Neppe printf =\t%g\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%g\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%g\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%g\n", float_zero);
// 	ft_printf("Neppe printf =\t%g\n", float_zero);
// }

// static void		simple_zero_b(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero B\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t0\n");
// 	ft_printf("Neppe printf =\t%b\n", float_zero);
// }


// static void		simple_zero_o(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero o\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%o\n", int_zero);
// 	ft_printf("Neppe printf =\t%o\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%o\n", long_zero);
// 	ft_printf("Neppe printf =\t%o\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%o\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%o\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%o\n", double_zero);
// 	ft_printf("Neppe printf =\t%o\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%o\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%o\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%o\n", float_zero);
// 	ft_printf("Neppe printf =\t%o\n", float_zero);
// }

// static void		simple_zero_u(void)
// {
// 	int	int_zero;
// 	long long_zero;
// 	long long long_long_zero;
// 	double	double_zero;
// 	long double long_double_zero;
// 	float float_zero;

// 	int_zero = 0;
// 	long_zero = 0;
// 	long_long_zero = 0;
// 	double_zero = 0.0;
// 	long_double_zero = 0.0;
// 	float_zero = 0.0;

// 	ft_printf("\n\nSimple zero u\n\n");
// 	ft_printf("int = \t0\n");
// 	printf("Echte printf =\t%u\n", int_zero);
// 	ft_printf("Neppe printf =\t%u\n", int_zero);
// 	ft_printf("long int = \t0\n");
// 	printf("Echte printf =\t%u\n", long_zero);
// 	ft_printf("Neppe printf =\t%u\n", long_zero);
// 	ft_printf("long long int = \t0\n");
// 	printf("Echte printf =\t%u\n", long_long_zero);
// 	ft_printf("Neppe printf =\t%u\n", long_long_zero);
// 	ft_printf("double zero = \t0.0\n");
// 	printf("Echte printf =\t%u\n", double_zero);
// 	ft_printf("Neppe printf =\t%u\n", double_zero);
// 	ft_printf("long double zero = \t0.0\n");
// 	printf("Echte printf =\t%u\n", long_double_zero);
// 	ft_printf("Neppe printf =\t%u\n", long_double_zero);
// 	ft_printf("float zero = \t0.0\n");
// 	printf("Echte printf =\t%u\n", float_zero);
// 	ft_printf("Neppe printf =\t%u\n", float_zero);
// }


// ////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	ft_printf("int = \t0\n");
	printf("Echte printf =\t%d\n", int_zero);
	ft_printf("Neppe printf =\t%d\n", int_zero);
	ft_printf("long int = \t0\n");
	printf("Echte printf =\t%ld\n", long_zero);
	ft_printf("Neppe printf =\t%ld\n", long_zero);
	ft_printf("long long int = \t0\n");
	printf("Echte printf =\t%lld\n", long_long_zero);
	ft_printf("Neppe printf =\t%lld\n", long_long_zero);
	ft_printf("double zero = \t0.0\n");
	printf("Echte printf =\t%f\n", double_zero);
	ft_printf("Neppe printf =\t%f\n", double_zero);
	ft_printf("long double zero = \t0.0\n");
	printf("Echte printf =\t%Lf\n", long_double_zero);
	ft_printf("Neppe printf =\t%Lf\n", long_double_zero);
	ft_printf("float zero = \t0.0\n");
	printf("Echte printf =\t%f\n", float_zero);
	ft_printf("Neppe printf =\t%f\n", float_zero);
}

static void		flag_simple_zero_e(void)
{
	double	double_zero;
	long double long_double_zero;

	double_zero = 0.0;
	long_double_zero = 0.0;

	ft_printf("\n\nflag_Simple zero E\n\n");
	ft_printf("double zero = \t0.0\n");
	printf("Echte printf =\t%e\n", double_zero);
	ft_printf("Neppe printf =\t%e\n", double_zero);
	ft_printf("long double zero = \t0.0\n");
	printf("Echte printf =\t%Le\n", long_double_zero);
	ft_printf("Neppe printf =\t%Le\n", long_double_zero);
	ft_printf("float zero = \t0.0\n");
}

static void		flag_simple_zero_g(void)
{
	double	double_zero;
	long double long_double_zero;
	float float_zero;

	double_zero = 0.0;
	long_double_zero = 0.0;
	float_zero = 0.0;

	ft_printf("\n\nflag_Simple zero G\n\n");
	ft_printf("double zero = \t0.0\n");
	printf("Echte printf =\t%g\n", double_zero);
	ft_printf("Neppe printf =\t%g\n", double_zero);
	ft_printf("long double zero = \t0.0\n");
	printf("Echte printf =\t%Lg\n", long_double_zero);
	ft_printf("Neppe printf =\t%Lg\n", long_double_zero);
	ft_printf("float zero = \t0.0\n");
	printf("Echte printf =\t%g\n", float_zero);
	ft_printf("Neppe printf =\t%g\n", float_zero);
}

static void		flag_simple_zero_b(void)
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

	ft_printf("\n\nflag_Simple zero B\n\n");
	ft_printf("int = \t0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", int_zero);
	ft_printf("long int = \t0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", long_zero);
	ft_printf("long long int = \t0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", long_long_zero);
	ft_printf("double zero = \t0.0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", double_zero);
	ft_printf("long double zero = \t0.0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", long_double_zero);
	ft_printf("float zero = \t0.0\n");
	printf("Echte printf =\t0\n");
	ft_printf("Neppe printf =\t%b\n", float_zero);
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
	ft_printf("int = \t0\n");
	printf("Echte printf =\t%o\n", int_zero);
	ft_printf("Neppe printf =\t%o\n", int_zero);
	ft_printf("long int = \t0\n");
	printf("Echte printf =\t%lo\n", long_zero);
	ft_printf("Neppe printf =\t%lo\n", long_zero);
	ft_printf("long long int = \t0\n");
	printf("Echte printf =\t%llo\n", long_long_zero);
	ft_printf("Neppe printf =\t%llo\n", long_long_zero);
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int				main(void)
{
	// simple_zero_d();
	// simple_zero_f();
	// simple_zero_e();
	// simple_zero_g();
	// //simple_zero_b();
	// simple_zero_o();
	// simple_zero_u();

	flag_simple_zero_d_f();
	flag_simple_zero_e();
	flag_simple_zero_g();
	// //flag_simple_zero_b();
	flag_simple_zero_o();
	//flag_simple_zero_u();
//	len_mod_f();
//	flags_f();
//	width_asterisk_f();
//	precision_f();
	return (0);
}