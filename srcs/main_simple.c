/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/16 14:29:41 by rsteigen      ########   odam.nl         */
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

	ft_printf("Lijn {red}74{eoc} testfile\n");
	printf("Ekte printf =\t %+.0d\n", 0);
	ft_printf("Neppe printf =\t %+.0d\n", 0);
	
	// ft_printf("Lijn {red}75{eoc} testfile\n");

	
	// //f = -9999999.34;
	// f = 9412.2321;
	// printf("Ekte printf =\t %047.d\n", 482);
	// ft_printf("Neppe printf =\t %047.d\n", 482);


	// printf("Echte printf =\t%e\n", f);
	// ft_printf("{red}Neppe printf {eoc}=\t%e\n", f);



	while(a)
		f++;

	return (0); 
}
