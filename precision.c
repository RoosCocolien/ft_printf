/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 17:48:28 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/25 16:54:05 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			fill_width_prec(t_info *flag, int length)
{
	int		fill;

	// printf("test fill_width_prec\n");
	// printf("(*flag).width: %d\n", (*flag).width);
	fill = 0;
	if ((*flag).width > 0 && (*flag).precision == 1 && (*flag).prec_value == 0)
	{
		(*flag).precision = 0;
		(*flag).prec_value = 0;
		(*flag).zero = 0;
	}
	//onderstaand heb ik opgevangen dmv een fill_p en een fill_w voor diou
	if ((*flag).precision != 0 && ((*flag).prec_value != 0\
	|| (*flag).width != 0))
	{
//		if ((*flag).precision == 1)
//			(*flag).width = (*flag).prec_value;
		(*flag).zero = 1;
		(*flag).minus = 0;
	}
	// printf("(*flag).width: %d\n", (*flag).width);
	if ((*flag).width > 0)
		fill = (*flag).prec_value - length;
		// fill = (*flag).width - length;
	return (fill);
}

void		pres_width_s(va_list args, t_info *flag)
{
	if ((*flag).asterisk == 1)
	{
		(*flag).prec_value = va_arg(args,int);
		(*flag).zero = 0;
//		(*flag).minus = 0;
		if ((*flag).prec_value < 0)
		{
			(*flag).minus = 1;
			(*flag).prec_value = -(*flag).prec_value;
		}
		if ((*flag).width == -1)
		(*flag).width = (*flag).prec_value;
	}
	
	// if ((*flag).asterisk == 1)
	// 	(*flag).precision = 2;
	// if ((*flag).precision != 0)
	// {
	// 	if ((*flag).precision == 2)
	// 	{
	// 		printf("test pres width_s\n");
	// 		(*flag).prec_value = va_arg(args, int);
	// 		printf("prec_val: %d\n", (*flag).prec_value);
	// 		if ((*flag).prec_value < 0)
	// 		{
	// 			(*flag).minus = 1;
	// 			(*flag).prec_value = -(*flag).prec_value;
	// 		}
	// 	}
	// 	(*flag).zero = 0;
	// 	(*flag).minus = 0;
	// }
	if ((*flag).prec_no_val == 1)
	{
		(*flag).precision = 1;
		(*flag).prec_value = 0;
	}
}

//eerste if/else statement hoeft er helemaal niet in te staan
void		get_prec_width(va_list args, t_info *flag, char spec)
{
	if (((*flag).precision == 2 || (*flag).asterisk == 1) && (*flag).prec_value == 0)
	{
		if (spec == 'p' || spec == 'x' || spec == 'd' || spec == 'i'\
		|| spec == 'u' || spec == 'o' || spec == 'X')
		{
			(*flag).prec_value = va_arg(args, int);
			// if ((*flag).prec_value < 0)
			// 	(*flag).prec_value = 0;
		}
		else
		{
			(*flag).prec_value = va_arg(args, int);
			// if ((*flag).prec_value < 0)
			// 	(*flag).prec_value = 6;
		}
	}
//	if ((*flag).width == -1 && (*flag).asterisk == 1 && (*flag).precision == 0)
//		(*flag).width = va_arg(args, int);
	if ((*flag).prec_value < 0)
	{
		// printf("prec_val: %d\n", (*flag).prec_value);
		if (spec == 'f' && (*flag).asterisk == 0)
			(*flag).prec_value = 6;
		else if ((*flag).asterisk == 0)
		{
			(*flag).prec_value = 0;
			(*flag).precision = 0;
		}
		else
		{
			(*flag).prec_value = -(*flag).prec_value;
			(*flag).minus = 1;
		}
		// (*flag).prec_value = -(*flag).prec_value;
	}
}

void		prec_and_zero_check(va_list args, t_info *flag, char spec)
{
	// printf("\n*1prec val: %d\n", (*flag).prec_value);
	// printf("*1width: %d\n", (*flag).width);
	// printf("*1zero: %d\n", (*flag).zero);
	// printf("*1prec: %d\n", (*flag).precision);
	(*flag).dot = 1;
	get_prec_width(args, flag, spec);
	// printf("\n*2prec val: %d\n", (*flag).prec_value);
	// printf("*2width: %d\n", (*flag).width);
	// printf("*2zero: %d\n", (*flag).zero);
	// printf("*2prec: %d\n", (*flag).precision);
	if ((*flag).prec_value == 0 && spec != 'p' && spec != 'd' && spec != 'i'\
	&& spec != 'u' && spec != 'x' && spec != 'X')
	{
		if ((*flag).precision != 0)
		{
			(*flag).no_decimals = 1;
			if ((*flag).hash != 1)
				(*flag).dot = 0;
		}
		else
			(*flag).prec_value = 6;
	}
// 	if ((*flag).prec_value < 0)		DIT STAAT AL BIJ GET PREC WIDTH
// 	{
// //		if (spec == 'd' || spec == 'i')
// 			(*flag).prec_value = 0;
// //		else
// //			(*flag).prec_value = -(*flag).prec_value;	
// 		(*flag).minus = 1;
// 	}
	if ((*flag).minus == 1)
		(*flag).zero = 0;	//uitbreiden naar andere spec's?
	if (spec == 'x' || spec == 'X')
		(*flag).plus = 0;
	// printf("\n*3prec val: %d\n", (*flag).prec_value);
	// printf("*3width: %d\n", (*flag).width);
	// printf("*3zero: %d\n", (*flag).zero);
	// printf("*3prec: %d\n", (*flag).precision);
	check_asterisk(flag, spec);
	// printf("\n*4prec val: %d\n", (*flag).prec_value);
	// printf("*4width: %d\n", (*flag).width);
	// printf("*4zero: %d\n", (*flag).zero);
	// printf("*4prec: %d\n", (*flag).precision);
}
