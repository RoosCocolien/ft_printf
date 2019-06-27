/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_d_i2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 12:25:22 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/27 14:15:22 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"
#include <stdio.h>

int		main(void)
{
/*
**	Length modifiers
*/
//	ft_printf("Flags \"l, ll, h, hh\"\n");
//	ft_printf("%%hhd (-35)\n");
//	ft_printf("%s\n", "Roos");
//	ft_printf("%d\n", -35);
//	ft_printf("%lld\n", -35);

/*
**	Width
*/
//	printf("(printf)\n%hh-5d\n", -35);
//	ft_printf("%hh-5d\n", -35);
//	printf("(printf)\n%hh5d\n", -35);
//	ft_printf("%hh5d\n", -35);
//	printf("(printf)\n%hh05d\n", -35);
//	ft_printf("%hh05d\n", -35);

/*
**	Asterisk (doesn't work the same)
*/
//	int een = -4;
//	int	twee = 67;
//	int drie = -97;
//	int vier = 7;
//	printf("Dit is een: %d\nDit is twee: %d\nDit is drie: %0*d\n", een, twee, drie, vier);
//	ft_printf("Dit is een: %d\nDit is twee: %d\nDit is drie: %0*d\n", een, twee, drie, vier);

/*
**	Precision
**	The minimum number of digits to be printed, leading zeros will be added to make
**	up the field with.
*/
	ft_printf("*\t**PRECISION**\t*\n");
//	printf("\n(printf %%.7d)\n%.7d\n", -6790);
//	ft_printf("%.7d\n", -6790);
	printf("\n(printf)\n%.*d\n", 7, 14);
	ft_printf("%.*d\n", 7, 14);
//	printf("\n(printf %%.06d)\n%.06d\n", 7);
//	ft_printf("%.06d\n", 7);

//SPACE SPACE SPACE NOT FINISHED YET
//	printf("-\t--comparison with width (onzichtbare plus teken telt mee bij width)--\t-\n");
//	printf("(printf %%06 d)\n%06 d\n", 7);
//	ft_printf("%06 d\n", 7);

//	printf("\n(printf %%.6 d)\n%.6 d\n", 7);
//	ft_printf("%.6 d\n", 7);
//	printf("\n(printf %%.6-d)\n%.6-d\n", 7);
//	ft_printf("%.6-d\n", 7);
//	printf("\n(printf %%.6+d)\n%.6+d\n", 7);
//	ft_printf("%.6+d\n", 7);

//	printf("\n(printf %%.7d)\n%.7d\n", -6790);
//	ft_printf("%.7d\n", -6790);
	printf("\n(printf %%.*d)\n%.*d\n", 7, 14);
	ft_printf("%.*d\n", 7, 14);
//	printf("\n(printf %%.06d)\n%.06d\n", 7);
//	ft_printf("%.06d\n", 7);
//	printf("\n(printf %%.6 d)\n%.6 d\n", 7);
//	ft_printf("%.6 d\n", 7);
//	printf("\n(printf %%.6-d)\n%.6-d\n", 7);
//	ft_printf("%.6-d\n", 7);
//	printf("\n(printf %%.6+d)\n%.6+d\n", 7);
//	ft_printf("%.6+d\n", 7);
	return (0);
}