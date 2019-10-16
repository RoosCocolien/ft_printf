/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: thugo <marvin@42.fr>                         +#+                     */
/*                                                   +#+                      */
/*   Created: 2017/01/25 21:29:13 by thugo          #+#    #+#                */
/*   Updated: 2019/10/16 13:25:32 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "../includes/ft_printf_test.h"

static void	printf_header()
{
	printf("\033[34m=============== PRINTF CHECKER ================\033[0m\n");
	printf("\033[34m===============================================\033[0m\n\n");
}

int	main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	setlocale(LC_ALL, "");

	if (argc <= 1)
	{
		normal_tests();
		bonus_tests();
	}
	else if (argc >= 2)
	{
		if (strcmp(argv[1], "1") == 0)
			normal_tests();
		else if (strcmp(argv[1], "2") == 0)
			bonus_tests();
		else
			printf("Usage: %s [1|2] (1: normal, 2: bonus)\n", argv[0]);
	}
	return (0);
}
