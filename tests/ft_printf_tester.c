/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_tester.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 12:32:53 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/05/25 12:36:24 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int		random_number(int lower, int upper)
{
	int		i;
	int		num;
	int		count;

	srand(time(1));
	i = 0;
	count = 1;
	while (i < count)
	{
		num = (rand() % (upper - lower + 1)) + lower;
		i++;
	}
	return (num);
}

char	*random_string(void)
{
	int 	str_length;
	char 	*str;
	int 	i;

	str_length = random_number(0, 1000);
	str = (char *)malloc(sizeof(char) * str_length + 1);
	i = 0;
	while (i < str_length)
	{
		str[i] = random_number(33, 126);
		i++;
	}
	return(str);
}

int main(void)
{
	printf("random str = %s\n", random_string());
	return (1);
}