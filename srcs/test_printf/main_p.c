/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_p.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/10 15:24:21 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/10 15:44:19 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
** indien spec == 'p', change settings of the flags
*/

static void		simple_p(void)
{
	char *str1;

	str1 = "Roos";
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
}

static void		flags_p(void)
{
	char	*str1;

	str1 = "Roos";
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);
	printf("%%p (printf)\n%p\n", str1);
	ft_printf("%p\n", str1);

}

static void		precision_p(void)
{

}

static void		padding_p(void)
{

}

int		main(void)
{
//	simple_p();
//	flags_p();
//	precision_p();
//	padding_p();
    return (0);
}