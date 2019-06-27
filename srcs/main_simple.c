/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/24 18:31:32 by rsteigen      ########   odam.nl         */
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

	f = 9999999999.0109011234;

	printf("Ekte printf =\t %f\n", f);
	//ft_printf("Neppe Fprintf =\t %e\n", -1234569.79 * 1.99);
	ft_printf("Neppe printf =\t %f\n", f);
	return (0);
}
