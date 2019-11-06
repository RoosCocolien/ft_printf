/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:58 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/06 11:32:06 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a decimal unsigned int and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
*/

//hoe werken negatieve getallen??

int		spec_u(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	int					length;
	int					fill;

	fill = 0;
	(*flag).plus = 0;
	//vanaf hier
	if ((*flag).precision == 2)
		(*flag).width = va_arg(args, int);
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);	
	//tm hier is hetzelfde als spec_d_i
	i = len_mod_check_u(args, flag, s[x]);
	length = ft_intlength(i);
	//vanaf hier
	// if ((*flag).precision != 0)
	// {
	// 	if ((*flag).precision == 1)
	// 		(*flag).width = (*flag).prec_value;
	// 	(*flag).zero = 1;
	// 	(*flag).minus = 0;
	// }
	// if ((*flag).width > 0)
	// 	fill = (*flag).width - length;
	fill = fill_width_prec(flag, length);
	//tm hier is hetzelfde als spec_d_i en spec_o

	//neg overslaan
	//plus sign kan wel geprint worden? en invisible plus sign? NEE
/*	if ((*flag).plus == 1)
	{
//		print plus sign on positive numbers
		fill = check_flag_plus(flag, fill, (*flag).minus);
	}
	if ((*flag).space == 1)
	{
//		invisible plus sign
		fill = check_flag_space(flag, fill, (*flag).minus);
	}
*/
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	print_digit(flag, i);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	return (x + 1);
}
