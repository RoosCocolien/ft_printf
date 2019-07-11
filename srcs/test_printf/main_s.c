/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_s.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 15:20:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/09 15:32:00 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

int		main(void)
{
	printf("\nFlags spec conv 's'\n");
	printf("\n%%-15s (printf)\n");
	printf("%-15s\n", "roos");
	ft_printf("%-15s\n", "roos");

	printf("\n%%15s (printf)\n");
	printf("%15s\n", "roos");
	ft_printf("%15s\n", "roos");

	//dit doet niks	
	printf("\n%%.7s (printf)\n");
	printf("%.7s\n", "roos");
	ft_printf("%.7s\n", "roos");

	printf("\n%%015s (printf)\n");
	printf("%015s\n", "roos");
	ft_printf("%015s\n", "roos");

	//if I use the '-' && the width '5', then the '0' will do nothing
	printf("\n%%-015s (printf)\n");
	printf("%-015s\n", "roos");
	ft_printf("%-015s\n", "roos");

	printf("\n%%015-s (printf)\n");
	printf("%015+s\n", "roos");
	ft_printf("%015+s\n", "roos");	
	return (0);
}