/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_b.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:20:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/01 14:35:38 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"


static void		simple_zero_b(void)
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

	ft_printf("\n\nSimple zero B\n\n");
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

int main(void)
{
	simple_zero_b();
	return (0);
}
