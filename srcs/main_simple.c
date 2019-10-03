/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/27 16:29:05 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		main(void)
{
//	printf("Basic test\n");
//	ft_printf("Basic test\n");
//	printf("Number: %05d\n", 3);
//	printf("Number: %d\n\n", 45);
//	ft_printf("Number: %058d\n", 3);
//	ft_printf("Min: %-d\n", 890);
//	ft_printf("Plus: %+d\n", 890);
//	ft_printf("Space: % d\n", 890);	//deze geeft foutmelding
//	ft_printf("Hash: %#d\n", 890);
//	ft_printf("Width: %78d\n", 890);
//	ft_printf("Asterisk: %*d\n", 890);
//	ft_printf("Precision: %.7d\n", 890);
//	ft_printf("Combi: %+d\n", 890);
//	ft_printf("Number: %-0+ #38d hallo\n", 45);

//	ft_printf("\nNEXT PART\n");
//	ft_printf("Flag precision(%%.*d): %.*d\n", 5689);
//	ft_printf("Flag precision(%%.7d): %.7d\n", 5689);
//	ft_printf("Number: %-0+ #38.45d\n", 3);
//	ft_printf("Number: %0*d\n", 39);

	int a = 10;
	int *p = &a;
	double f;

	//f = -9999999.34;
	f = 9.09;
	// ft_printf("Ekte printf =\t %0*f\n", 4, 7.3412);
	// // ft_printf("Neppe printf =\t {green}%0*f{eoc}\n", 4, 7.3412);

	printf("Echte printf =\t%e\n", f);
	ft_printf("Neppe printf =\t%e\n", f);
	// printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", 0.333333333333333334);
	// ft_printf("%f\n", first_long);
	// printf("\nPOS DOUBLE\n");
	// printf("\nprintf\t%%f\t(0.333333333333make 333334)\n%f\n", first);
	// ft_printf("%f\n", first);
	// printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", first);
	// ft_printf("%f\n", first);



	return (0); 
}
