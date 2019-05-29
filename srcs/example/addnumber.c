/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addnumber.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 14:49:50 by rsteigen       #+#    #+#                */
/*   Updated: 2019/05/27 14:57:08 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	add_nbs(int amount, ...)
{
	int		sum;
	int		i;
	va_list	int_arg_ptr;
	va_start(int_arg_ptr, amount);

	sum = 0;
	i = 0;
	while (i < amount)
	{
		sum = sum + va_arg(int_arg_ptr, int);
		i++;
	}
	va_end(int_arg_ptr);
	return (sum);
}

int	main(void)
{
	printf("\n*\nVariadic functions:\n*\n");
	printf("10 + 20 = %d\n", add_nbs(2, 10, 20));
	printf("10 + 20 + 30 = %d\n", add_nbs(3, 10, 20, 30));
	printf("10 + 20 + 30 + 40 = %d\n", add_nbs(4, 10, 20, 30, 40));
	printf("\n");
	return (0);
}