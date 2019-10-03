/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_c.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/08 18:03:42 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/08 18:30:31 by rsteigen      ########   odam.nl         */
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
	return (0);
}
