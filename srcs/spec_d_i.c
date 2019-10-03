/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:44:31 by rsteigen       #+#    #+#                */
/*   Updated: 2019/10/02 17:26:47 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
** This function will print an integer and consider
** the used flags.
** print: 					OK
** consideration of flags:	OK
**
**	int	fill -> difference between flag.width && length
**	(taking other flags like precision in consideration)
**
** DOESN'T WORK WITH:
** -long int	
** 
*/

int		spec_d_i(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long		i;
	int						length;
	int						fill;

	fill = 0;
	if ((*flag).precision == 2)
		(*flag).width = va_arg(args, int);
	if ((*flag).width == 1 && (*flag).asterisk == 1 && (*flag).precision == 0)
		(*flag).width = va_arg(args, int);
/* flag '0' is ignored when flag '-' is used, same everywhere? */
	if ((*flag).zero == 1 && (*flag).minus == 1)
		(*flag).zero = 0;
	i = len_mod_check_di(args, flag);
	length = ft_intlength(i);
	if ((*flag).precision != 0)
	{
		if ((*flag).precision == 1)
			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	//BEGIN FILL
	if ((*flag).width > 0)
		fill = (*flag).width - length;
	if ((*flag).neg == 1 && (*flag).precision == 0)
		fill--;
	if ((*flag).plus == 1)
	{
//		print plus sign on positive numbers
		fill = check_flag_plus(flag, fill, (*flag).minus);
	}
	if ((*flag).space == 1)
	{
//		invisible plus sign
		fill = check_flag_space(flag, fill, (*flag).minus);
	}
	//END FILL
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	if ((*flag).neg == 1 && (*flag).zero != 1)
	{
		ft_putchar('-');
		(*flag).count++;
	}
	//is dit onderstaande niet dubbel op? Want ik heb toch al een check_flag_plus
	//niet dubbelop, want dit is nodig om daadwerkelijk een plus te zetten
	//verplaatst naar print_digit in print.c
	// if ((*flag).neg == 0 && (*flag).plus == 1 && (*flag).minus == 0 &&\
	// (*flag).precision == 0 && (*flag).zero == 0)
	// {
	// 	ft_putchar('+');
	// 	(*flag).count++;
	// }
	print_digit(flag, i);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	x++;
	return (x);
}
