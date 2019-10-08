/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/08 15:41:30 by rsteigen      ########   odam.nl         */
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
	char *str;

	str = (char *)malloc(5);
	str[0] = 'b';
	str[1] = 'e';
	str[2] = 'b';
	str[3] = 'b';
	str[4] = '\0';

	ft_putstr(str);

	//f = -9999999.34;
	f = 9412.2321;
	// ft_printf("Ekte printf =\t %0*f\n", 4, 7.3412);
	// // ft_printf("Neppe printf =\t {green}%0*f{eoc}\n", 4, 7.3412);

	// printf("Echte printf =\t%e\n", f);
	// ft_printf("{red}Neppe printf {eoc}=\t%e\n", f);

	printf("\n- spec_g precision with asterisk, value: 20");
	printf("\nprintf\t%%.*g\t(20, 98.7654321)\n%.*g\n", 9, 98.7654321);
	ft_printf("%.*g\n", 9, 98.7654321);
	printf("\n- spec_f precision with asterisk, value: 20");
	printf("\nprintf\t%%.*f\t(20, 98.7654321)\n%.*f\n", 60, 9.87654321); //max 40, alles erboven print hij een "0"
	ft_printf("%.*f\n", 60, 9.87654321);



	// printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", 0.333333333333333334);
	// ft_printf("%f\n", first_long);
	// printf("\nPOS DOUBLE\n");
	// printf("\nprintf\t%%f\t(0.333333333333make 333334)\n%f\n", first);
	// ft_printf("%f\n", first);
	// printf("\nprintf\t%%f\t(0.333333333333333334)\n%f\n", first);
	// ft_printf("%f\n", first);
	while(a)
		f++;

	return (0); 
}
