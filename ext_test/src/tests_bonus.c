/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tests_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: thugo <marvin@42.fr>                         +#+                     */
/*                                                   +#+                      */
/*   Created: 2017/01/26 23:34:44 by thugo          #+#    #+#                */
/*   Updated: 2019/11/12 10:55:51 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "../includes/macros.h"

void	tests_wildcard(void)
{
	ADD_PRINTF_TEST("%*d", 5, 50)
	ADD_PRINTF_TEST("%*d", 0, 50)
	ADD_PRINTF_TEST("%*d", -5, 50)
	ADD_PRINTF_TEST("%.*d", 5, 50)
	ADD_PRINTF_TEST("%.*d", 0, 50)
	ADD_PRINTF_TEST("%.*d", -15, 50)
}

void	tests_n(void)
{
	ADD_PRINTF_TEST("%n", 0)
}

void	bonus_tests(void)
{	
	INIT_TESTS()
	printf("\033[34m=============== Bonus tests ===============\033[0m\n");
	tests_wildcard();
	// tests_n();

	PRINT_TESTS_RESULT("Bonus tests")
}
