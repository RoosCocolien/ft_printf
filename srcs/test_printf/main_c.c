/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 18:03:42 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/12 16:56:00 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		main(void)
{
	printf("\nFlags spec conv 'c'\n");
	printf("\n%%-5c (printf)\n");
	printf("%-5c\n", 'k');
	ft_printf("%-5c\n", 'k');

	printf("\n%%5c (printf)\n");
	printf("%5c\n", 'k');
	ft_printf("%5c\n", 'k');

	//dit doet niks	
	printf("\n%%.7c (printf)\n");
	printf("%.7c\n", 'k');
	ft_printf("%.7c\n", 'k');

	printf("\n%%05c (printf)\n");
	printf("%05c\n", 'k');
	ft_printf("%05c\n", 'k');

	//if I use the '-' && the width '5', then the '0' will do nothing
	printf("\n%%-05c (printf)\n");
	printf("%-05c\n", 'k');
	ft_printf("%-05c\n", 'k');

	printf("\n%%05-c (printf)\n");
	printf("%05+c\n", 'k');
	ft_printf("%05+c\n", 'k');

	printf("Test # flag\n");
	printf("printf %%#c\n");
	printf("%#c\n", 'a');
	ft_printf("%#c\n", 'a');
	printf("printf %%#-5c\n");
	printf("%#-5c\n", 'b');
	ft_printf("%#-5c\n", 'b');
	printf("printf %%#05c\n");
	printf("%#05c\n", 'c');
	ft_printf("%#05c\n", 'c');
	return (0);
}
