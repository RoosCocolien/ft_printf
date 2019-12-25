/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/25 13:53:24 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	fill_precision(t_info *flag, int length)
{
	int fill;

	fill = 0;
	// printf("length: %d\n", length);
	// printf("prec_v: %d\n", (*flag).prec_value);
	if ((*flag).precision != 0)
		fill = (*flag).prec_value - length;
	// printf("fill: %d\n", fill);
	if (fill < 0)
		fill = 0;
	return (fill);
}

int		fill_width(t_info *flag, int length)
{
	int fill;

	fill = 0;
	if ((*flag).width != 0)
		fill = (*flag).width - length;
	if (fill < 0)
		fill = 0;
	return (fill);
}

void		put_neg(t_info *flag)
{
	ft_putchar_fd('-', (*flag).fd);
	(*flag).count++;
	(*flag).neg = -1;
}

void		check_print_neg(t_info *flag, int fill_w, int fill_p, int nb)
{
	if (nb == 1)
	{
		// printf("1fill_p: %d\n", fill_p);
		// printf("1fill_w: %d\n", fill_w);
		if ((*flag).neg == 1 && (fill_w <= 0 || (fill_w > 0 &&\
		(*flag).zero == 1)))
		{
			// printf("neg1\n");
			put_neg(flag);
		}
	}
	if (nb == 2)
	{
		// printf("2fill_p: %d\n", fill_p);
		if ((*flag).neg == 1 && fill_p > 0)
		{
			// printf("neg2\n");
			put_neg(flag);
		}
	}
	if (nb == 3)
	{
		// printf("3fill_p: %d\n", fill_p);
		if ((*flag).neg == 1)
		{
			// printf("neg3\n");
			put_neg(flag);
		}
	}
}

void		put_padding_w(t_info *flag, int fill_w)
{
	char					char_fill;

	if ((*flag).zero == 1 && (*flag).prec_no_val == 0)
		char_fill = '0';
	else
		char_fill = ' ';
	while (fill_w > 0)
	{
		ft_putchar_fd(char_fill, (*flag).fd);
		(*flag).count++;
		fill_w--;
	}
}

void		put_padding_p(t_info *flag, int fill_p)
{
	char				char_fill;

	char_fill = '0';
	while (fill_p > 0)
	{
		ft_putchar_fd(char_fill, (*flag).fd);
		(*flag).count++;
		fill_p--;
	}
}

int			spec_d_i(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long		i;
	int						length_original;
	int						fill_w;
	int						fill_p;
	int						length_new;

	prec_and_zero_check(args, flag, s[x]);
	// if ((*flag).zero == 1 && (*flag).minus == 1)
		// (*flag).zero = 0; //dit staat in de prec_and_zero_check
	i = len_mod_check_di(args, flag);
	length_original = check_length_zero_int(i, flag);
	fill_p = fill_precision(flag, length_original);
	length_new = length_original + fill_p + (*flag).neg;
	fill_w = fill_width(flag, length_new);
	if ((*flag).plus == 1)
		fill_w = check_flag_plus(flag, fill_w, (*flag).minus);
	if ((*flag).space == 1 && (*flag).plus == 0)
		fill_w = check_flag_space(flag, fill_w, (*flag).minus);
	check_print_neg(flag, fill_w, fill_p, 1);
	if ((*flag).minus == 0 && fill_w > 0)
		put_padding_w(flag, fill_w);
	check_print_neg(flag, fill_w, fill_p, 2);
	put_padding_p(flag, fill_p);
	check_print_neg(flag, fill_w, fill_p, 3);
	print_digit(flag, i, length_original);
	if ((*flag).minus == 1 && fill_w > 0)
		put_padding_w(flag, fill_w);
	x++;
	return (x);
}

// int		spec_d_i2(char *s, va_list args, t_info *flag, int x)
// {
// 	unsigned long long		i;
// 	int						length;
// 	int						fill_w;
// 	int						fill_p;

// 	fill_w = 0;
// 	fill_p = 0;
// 	prec_and_zero_check(args, flag, s[x]);
// 	if ((*flag).zero == 1 && (*flag).minus == 1)
// 		(*flag).zero = 0;
// 	i = len_mod_check_di(args, flag);
// 	length = check_length_zero_int(i, flag);
// 	fill_p = fill_width_prec(flag, length);
// 	if ((*flag).neg == 1 && (*flag).precision == 0)
// 		fill_p--;
// 	if ((*flag).plus == 1)
// 		fill_p = check_flag_plus(flag, fill_p, (*flag).minus);
// 	if ((*flag).space == 1 && (*flag).plus == 0)
// 		fill_p = check_flag_space(flag, fill_p, (*flag).minus);
// 	if (/*(*flag).width > 0 && */(*flag).minus == 0 && fill_p > 0)
// 		put_padding(flag, fill_p);
// 	fill_w = (*flag).width - (length + fill_p);
// 	if (fill_w > 0 && (*flag).minus == 0)
// 		put_padding(flag, fill_w);
// 	print_neg(flag, length, s[x]);
// 	print_digit(flag, i);
// 	if (/*(*flag).width > 0 && */(*flag).minus == 1 && fill_p > 0)
// 		put_padding(flag, fill_p);
// 	if (fill_w > 0 && (*flag).minus == 1)
// 		put_padding(flag, fill_w);
// //	printf("width: %d\n", (*flag).width);
// 	x++;
// 	return (x);
// }
