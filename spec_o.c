/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/26 14:29:17 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

//heb je bij spec_o ook die + en de ' '??
int		spec_o(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	int					length;
	int					fill_w;
	int					fill_p;
	char				*oct_str;

	(*flag).plus = 0;
	get_prec_width(args, flag, s[x]);
	// printf("2width: %d\n", (*flag).width);
	// printf("2prec_val: %d\n", (*flag).prec_value);
	// printf("2minus: %d\n", (*flag).minus);
	check_asterisk(flag, s[x]);
	// printf("3width: %d\n", (*flag).width);
	// printf("3prec_val: %d\n", (*flag).prec_value);
	i = len_mod_check_u(args, flag, s[x]);
	oct_str = ft_itoa_base_ll(i, 8, 0);
	length = check_length_zero(i, oct_str, flag);
	if (s[x] == 'o' && (*flag).hash == 1 && (*flag).zero == 0 && i != 0)
	{
		// printf("SURPRISE (spec_o)\n");
		length++;
	}
	// printf("4width: %d\n", (*flag).width);
	// printf("4prec_val: %d\n", (*flag).prec_value);
	fill_p = fill_precision(flag, length);
	fill_w = fill_width(flag, s[x], length + fill_p + (*flag).neg);
	// printf("fill_p: %d, fill_w: %d\n", fill_p, fill_w);
	// printf("oct_str: [%s]\n", oct_str);
	if ((*flag).minus == 0 && fill_w > 0)
	{
		// printf("check padding w1\n");
		put_padding_w(flag, fill_w);
	}
	put_padding_p(flag, fill_p);
	// printf("...");
	print_zero(flag, i, oct_str);
	print_string(flag, oct_str);
	if ((*flag).minus == 1 && fill_w > 0)
		put_padding_w(flag, fill_w);
	if (oct_str)
		free (oct_str);
	return (x + 1);
}

// int		spec_o(char *s, va_list args, t_info *flag, int x)
// {
// 	unsigned long long	i;
// 	int					length;
// 	int					fill;
// 	char				*oct_str;

// 	fill = 0;
// 	get_prec_width(args, flag, s[x]);
// 	i = len_mod_check_u(args, flag, s[x]);
// 	oct_str = ft_itoa_base_ll(i, 8, 0);
// 	length = ft_strlen(oct_str);
// 	fill = fill_width_prec(flag, length);
// //wat is onderstaande?
// 	if (s[x] == 'o' && (*flag).hash == 1 && (*flag).zero == 0 && i != 0)
// 	{
// 		printf("SURPRISE (spec_o)\n");
// 		fill--;
// 	}
// 	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
// 		put_padding(flag, fill);
// 	print_zero(flag, i, oct_str);
// 	print_string(flag, oct_str);
// 	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
// 		put_padding(flag, fill);
// 	if (oct_str)
// 		free(oct_str);
// 	return (x + 1);
// }
