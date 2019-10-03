/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_g.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:19 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/27 15:22:30 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an general-format floating-point number and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

//fix roundup
//fix *.00000000
//Ekte printf =    8.00001
//Neppe printf =   8

// unsigned long long		ft_roundup_g(long double d)
// {
// 	long long int i;
// 	int len;
// 	int j;
// 	char *str;

// 	i = d * 1000000;
// 	len = ft_intlength(i);
// 	str = ft_itoa_llu(i);
// 	j = len;
// 	if (str[len - 12] >= '5')
// 	{
// 		str[len - 7] += 1;
// 		d += 1;
// 	}
// 	return (d);
// }

char	*ret_str_maker_g(int j, char plusmin, int min)
{
	char *ret_str;
	int i;

	ret_str = (char *)malloc(11 + min);
	ret_str[11] = '\0';
	if (min == 1)
		ret_str[0] = '-';
	i = 0 + min;
	while (ret_str[i] != '\0')
	{
		ret_str[i] = '0';
		i++;
	}
	ret_str[1 + min] = '.';
	ret_str[7 + min] = 'e';
	ret_str[8 + min] = plusmin;
	if (j >= 10)
	{
		ret_str[9 + min] = (j / 10) + 48;
		ret_str[10 + min] = (j % 10) + 48;
	}
	else
	{
		ret_str[9 + min] = '0';
		ret_str[10 + min] = j + 48;
	}
	return (ret_str);
}

char	*ret_str_filler_g(char *ret_str, char input, int i, int min)
{
		ret_str[i + min] = input;
		return (ret_str);
}

int		spec_gmin(char *s, long double d, t_info *flag, int x, int min)
{
	int j;
	int i;
	char *new_d_str;
	char *ret_str;
	long long int new_d_int;

	i = 0;
	j = 0;
	while (d < 1)
	{
		d = d * 10;
		j++;
	}
	ret_str = ret_str_maker_g(j, '-', min);
	new_d_int = d * 1000000;
	new_d_str = ft_itoa_llu(new_d_int);
	while (new_d_str[i] != '\0' && i <= 6)
	{
		if (i > 0)
			ret_str_filler_g(ret_str, new_d_str[i], i + 1, min);
		else
			ret_str_filler_g(ret_str, new_d_str[i], i, min);
		i++;
	}
	ft_putstr(ret_str);
	//check flags, put padding
	return (x + 1);
}

int	precision_zero_check(char *ret_str, int min)
{
	if (ret_str[0 + min] == '0' && ret_str[1 + min] == '.')
		return(1);
	return(0);
}

char	*precision_check(char *ret_str, int min)
{
	int i;
	int numb;

	if (precision_zero_check(ret_str, min) == 1)
		return (ret_str);
	i = 0;
	while (ret_str[i] != '\0')
	{
		if (ret_str[i] >= 48 && ret_str[i] <= 57)
			numb++;
		i++;
	}
	if (numb > 6) // 6 = precision
		ret_str = ft_strsub(ret_str, 0, 7 + min);
	if (ret_str[ft_strlen(ret_str) - 1] == '.')
		ret_str = ft_strsub(ret_str, 0, ft_strlen(ret_str) - 1);
	return (ret_str);
}


char	*ret_str_zero_check_double(char *ret_str)
{
	int len;

	len = ft_strlen(ret_str);
	while (ret_str[len - 1] == '0')
		len--;
	ret_str = ft_strsub(ret_str, 0, len);
	return(ret_str);
}

char	*ret_str_zero_check(char *ret_str)
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

static char			*ft_itoa_llu_g(unsigned long long n, int min, int dot)
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

char	*double_str_maker(long double d, int min)
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
	str = ft_itoa_llu_g((int)d, min, i);
	str = ft_strcat(ft_strcat(str, "."), str_remainder);
	str = ret_str_zero_check_double(str);
	str = precision_check(str, min);
	free(str_remainder);
	ft_putstr(str);
	return (str);
}

// char	*double_str_maker(long double d, int min)
// {
// 	int	i;
// 	int j;
// 	long double 	remainder;
// 	char *str;

// 	i = d;
// 	remainder = d - i;
// 	j = 0;
// 	printf("i = %d, d = %Lf, remainder = %Lf\n", i, d, remainder);
// 	while (i != 0)
// 	{
// 		printf("1)i = %d, d = %Lf, remainder = %Lf\n", i, d, remainder);
// 		remainder = remainder * 10;
// 		printf("2)i = %d, d = %Lf, remainder = %Lf\n", i, d, remainder);
// 		i = reaminder;
// 		printf("3)i = %d, d = %Lf, remainder = %Lf\n", i, d, remainder);
// 		// if (i == 0)
// 		// 	break;
// 		remainder = remainder - i;
// 		j++;
// 		printf("4)i = %d, d = %Lf, remainder = %Lf\n\n", i, d, remainder);
// 	}
// 	i = j;
// 	while (j >= 0)
// 	{
// 		d = d * 10;
// 		j--;
// 	}
// 	str = ft_itoa_llu_g((int)d, min, i);
// 	ft_putstr(str);
// 	return (str);
// }


int		spec_g(char *s, va_list args, t_info *flag, int x)
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
	if (d < (double)999999.50)
	{
		new_d_str = double_str_maker(d, min);
		return (x + 1);
	}
	if (d < 1 && d > 0)
	{
		x = spec_gmin(s, d, flag, x, min);
		return (x);
	}
	i = 0;
	j = 0;
	while (d >= 10 || d <= -10)
	{
		d = d / 10;
		j++;
	}
	ret_str = ret_str_maker_g(j, '+', min);
	new_d_int = d * 1000000;
	new_d_str = ft_itoa_llu(new_d_int);
	while (new_d_str[i] != '\0' && i <= 5)
	{
		if (i > 0)
			ret_str_filler_g(ret_str, new_d_str[i], i + 1, min);
		else
			ret_str_filler_g(ret_str, new_d_str[i], i, min);
		i++;
	}
	ret_str = ret_str_zero_check(ret_str);
	ft_putstr(ret_str);
	//check flags, put padding
	return (x + 1);
}
