/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_perc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 15:04:15 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/11 15:08:06 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

static void		make_test_perc(void)
{
	printf("return_pf:\t(%%%%)\t%d\n", printf("%%\n"));
	printf("return_fpf:\t(%%%%)\t%d\n", ft_printf("%%\n"));
	printf("return_pf:\t(%% %%)\t%d\n", printf("% %\n"));
	printf("return_fpf:\t(%% %%)\t%d\n", ft_printf("% %\n"));
	printf("return_pf:\t(%%10%%)\t%d\n", printf("%10%\n"));
	printf("return_fpf:\t(%%10%%)\t%d\n", ft_printf("%10%\n"));
	printf("return_pf:\t(%%-10%%)\t%d\n", printf("%-10%\n"));
	printf("return_fpf:\t(%%-10%%)\t%d\n", ft_printf("%-10%\n"));
}

int		main(void)
{
	make_test_perc();
	return (0);
}