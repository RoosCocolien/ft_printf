/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:11 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/25 14:24:09 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an double and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		precision_zero_check_f(char *ret_str, int min)
{
	if (ret_str[0 + min] == '0' && ret_str[1 + min] == '.')
		return(1);
	return(0);
}

char	*precision_check_f(char *ret_str, int min)
{
	int i;
	int numb;

	if (precision_zero_check_f(ret_str, min) == 1)
		return (ret_str);
	i = 0;
	while (ret_str[i] != '\0')
	{
		if (ret_str[i] >= 48 && ret_str[i] <= 57)
			numb++;
		i++;
	}
	if (numb > 7) // 7 = precision
		ret_str = ft_strsub(ret_str, 0, 8 + min); // 8 = precision + 1
	if (ret_str[ft_strlen(ret_str) - 1] == '.')
		ret_str = ft_strsub(ret_str, 0, ft_strlen(ret_str) - 1);
	return (ret_str);
}


char	*ret_str_zero_check_double_f(char *ret_str)
{
	int len;

	len = ft_strlen(ret_str);
	while (ret_str[len - 1] == '0')
		len--;
	ret_str = ft_strsub(ret_str, 0, len);
	return(ret_str);
}

char	*ret_str_zero_check_f(char *ret_str)
{
	int i;
	int zero;
	int dot;
	int len;

	len = ft_strlen(ret_str);
	i = len - 5;
	zero = 0;
	dot = 0;
	while (ret_str[i] == '0')
	{
		zero = i;
		i--;
	}
	if (zero == 0)
		return (ret_str);
	else
	{
		if (ret_str[zero - 1] == '.')
			dot++;
		ret_str[zero - dot] = ret_str[len - 4];
		ret_str[zero + 1 - dot] = ret_str[len - 3];
		ret_str[zero + 2 - dot] = ret_str[len - 2];
		ret_str[zero + 3 - dot] = ret_str[len - 1];
		ret_str[zero + 4 - dot] = '\0';
		return (ret_str);
	}
}

static char			*ft_itoa_llu_f(unsigned long long n, int min, int dot)
{
	int		cx;
	int		intlen;
	int 	intlen_save;
	unsigned long long		y;
	char	*str;

	cx = 0;
	intlen = ft_intlength(n);
	if (min == 1)
		intlen++;
	str = (char*)malloc(intlen);
	// intlen--;
	intlen_save = intlen;
	while (intlen >= min)
	{
		y = n;
		while (n > 9)
			n = n % 10;
		str[intlen - 1] = n + 48;
		n = y / 10;
		intlen--;
	}
	str[5 + min + 1] = '\0'; //veranderen bij andere spec, dit geldt alleen voor spec_g
	if (min == 1)
		str[0] = '-';
	return (str);
}

char	*double_str_maker_f(long double d, int min)
{
	int	i;
	int j;
	long double 	remainder;
	char *str_remainder;
	char *str;

	i = d;
	remainder = (d - i) * 1000000; //precision
	str_remainder = ft_itoa(remainder);
	if (str_remainder[ft_strlen(str_remainder) - 1] == '9')
		str_remainder = ft_itoa(remainder + 1);
	str = ft_itoa_llu_f((int)d, min, i);
	str = ft_strcat(ft_strcat(str, "."), str_remainder);
	//str = ret_str_zero_check_double_f(str);
	str = precision_check_f(str, min);
	free(str_remainder);
	ft_putstr(str);
	return (str);
}

int		spec_f(char *s, va_list args, t_info *flag, int x)
{
	long double d;
	int j;
	int i;
	int min;
	char *new_d_str;
	char *ret_str;
	long long int new_d_int;

	d = va_arg(args, double); 
	min = 0;
	if (d < 0)
	{
		min = 1;
		d = d * -1;
	}
	new_d_str = double_str_maker_f(d, min);
	return (x + 1);
}




		
// void	ft_putdouble(unsigned long long d)
// {
// 	char	*dub;
// 	char	*tot;
// 	char	*dec;
// 	int j;
// 	double	len;

// 	dub = ft_itoa_llu(d / 1000000);
// 	ft_putstr(dub);
// 	ft_putchar('.');
// 	j = ft_deci_count(d);
// 	while (j < 4)
// 	{
// 		ft_putchar('0');
// 		j++;;
// 	}
// 	len = ft_strlen(dub);
// 	if ((int)d / 1000000 == 0)
// 		len -= 1;
// 	tot = ft_itoa_llu(d);
// 	dec = ft_strsub(tot, len, 6);
// 	//ft_putchar('\n');
// 	ft_putstr(dec);
// 	free(dec);
// }

// int		spec_f(char *s, va_list args, t_info *flag, int x)
// {
// 	double 					d;
// 	unsigned long long 		i;

// 	d = va_arg(args, double);
// 	if (d < 0)
// 	{
// 		d = -d;
// 		ft_putchar('-');
// 	}
// 	i = (unsigned long long)(1000000 * d);
// 	ft_putdouble(i);
// 	return (x + 1);
// }
