/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 18:03:42 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/05 15:50:43 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static void		simple(void)
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
}

void		hash(void)
{
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
}

int		main(void)
{
	simple();
	hash();
	return (0);
}
