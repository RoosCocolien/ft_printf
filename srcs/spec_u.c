/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_u.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:58 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/10 13:31:11 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print a decimal unsigned int and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

//hoe werken negatieve getallen??

int		spec_u(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	int					length;
	int					fill;

	fill = 0;

	//vanaf hier
	if ((*flag).precision == 2)
		(*flag).width = va_arg(args, int);
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);	
	//tm hier is hetzelfde als spec_d_i

	i = len_mod_check_uoxX(args, flag, s[x]);

	//vanaf hier
	length = ft_intlength(i);
	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	//tm hier is hetzelfde als spec_d_i

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
		put_padding(flag, (*flag).zero, fill, 0);
	print_digit(flag, i);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, (*flag).zero, fill, (*flag).neg);
	return (x + 1);
}
