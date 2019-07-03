/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/01 18:22:56 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an integer and consider
** the used flags.
** print: 					OK
** consideration of flags:	NO
*/

int		spec_d_i(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long int	i;
	int						length;	//dit blijft lengte van int
	int						fill;	//dit wordt verschil tussen flag.width en length

	fill = 0;
	//RANGE CHECK && check if neg
	i = len_mod_check(args, flag);
	//CHECK FLAGS
	//-padding (make a separate function, before and after printing)
		//- fill with spaces
		//- fill with 0's
	//-check other flags

	//check length
	length = ft_intlength(i);
	//if (flag.neg == 1) --> length++
	//onderstaande hoeft misschien niet
	if ((*flag).neg == 1 && (*flag).precision == 0)
		length++;
	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
		//don't forget the asterisk
		//ignore minus, zero and space (so else if) of zet alles op '0'????
		//of check gewoon op flag.precision == 0
	}
	if ((*flag).width > 0)		//kan aangepast worden naar twee losse if statements
	{
		if ((*flag).asterisk == 1 && (*flag).precision == 0)
			(*flag).width = va_arg(args, int);
		fill = (*flag).width - length;
	}
	if ((*flag).plus == 1)
	{
//		fill will be drecemented with 1, if precision == 0 && width != 0
		fill = check_flag_plus(flag, fill, (*flag).minus);
	}
	if ((*flag).space == 1)
	{
//		fill will be drecemented with 1, if precision == 0 && width != 0
		fill = check_flag_space(flag, fill, flag.minus);
	}
	//check precision (i believe that the other flags will be ignored, only minus and zero)
	//put padding
	//don't forget the asterisk!!!
	if ((*flag).width > 0 && (*flag).minus == 0 && /*flag.precision == 0 &&*/ fill > 0)
		put_padding((*flag).zero, fill, (*flag).neg);
	if ((*flag).neg == 1 && (*flag).zero != 1)
		ft_putchar('-');
	if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	(*flag).precision == 0 && (*flag).zero == 0)
		ft_putchar('+');
	ft_putnbr(i);
	//align left
	//put padding
	//don't forget the asterisk!!
	if ((*flag).width > 0 && (*flag).minus == 1 && /* (*flag).precision == 0 &&*/ fill > 0)
		put_padding((*flag).zero, fill, (*flag).neg);
	x++;
	return (x);
}
