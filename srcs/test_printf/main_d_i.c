/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_d_i.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/14 12:33:50 by rsteigen       #+#    #+#                */
/*   Updated: 2019/06/24 12:00:51 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/printf.h"

/*
**	'-' && '0' can't be combined
**	Important: also check 'i'
**	'#' not important
**
*/

int		main(void)
{
	int		pos;
	int		neg;
	int		random_nb;
	int		biggest_neg;
	int		biggest_pos;

	pos = 532;
	neg = -356;
	random_nb = 4879;
	biggest_neg = -2147483648;
	biggest_pos = 2147483647;

/*
**	Simple test
*/
	printf("normal: %d, %d, %d, %d\n", pos, neg, biggest_neg,\
	biggest_pos);
	ft_printf("normal: %d, %d, %d, %d\n", pos, neg, biggest_neg,\
	biggest_pos);


/*
**	Padding (width option)
*/
	printf("\nWidth option\n");
	printf("Padding (width(7)) default: %7d\n", neg);
//	ft_printf("Padding (width(7)) default: %7d\n", neg);
	printf("Padding (width(7)) 0 fill: %07d\n", random_nb);
//	ft_printf("Padding (width(7)) 0 fill: %07d\n", random_nb);
	printf("Padding (width(7)) no fill, left aligned: %-7d\n", random_nb);
//	ft_printf("Padding (width(7)) no fill, left aligned: %-7d\n", random_nb);
	printf("Padding (width(7)) 0 fill, left aligned: %-7d\n", random_nb);
//	ft_printf("Padding (width(7)) 0 fill, left aligned: %-7d\n", random_nb);

/*
**	Requestion a plus sign (+) in case of positive numbers
*/
	printf("\nPlus option\n");
	printf("Request plus sign in case of pos (width(5)): %+5d\n", pos);
//	ft_printf("Request plus sign in case of pos (width(5)): %+5d\n", pos);
	printf("Zero is considered positive: %+5d\n", 0);
//	ft_printf("Zero is considered positive: %+5d\n", 0);
	printf("Request plus sign in case of neg doesn't do anything: %+5d\n", neg);
//	ft_printf("Request plus sign in case of neg doesn't do anything: %+5d\n", neg);
	printf("Visible plus sign, align left, pos nb: %+-d\n", pos);
//	ft_printf("Visible plus sign, align left, pos nb: %+-d\n", pos);
	printf("Visible plus sign, align left, neg nb: %+-d\n", neg);
//	ft_printf("Visible plus sign, align left, neg nb: %+-d\n", neg);
	printf("Invisible plus sign, align left, pos nb: % -d\n", pos);
//	ft_printf("Invisible plus sign, align left, pos nb: % -d\n", pos);
	printf("Invisible plus sign, align left, neg nb: % -d\n", neg);
//	ft_printf("Invisible plus sign, align left, neg nb: % -d\n", neg);

/*
**	Combination of plus, space, zero
*/
	printf("\nCombination of plus, space, zero\n");
	printf("Invisible plus sign, fill 0, width 5: % 05d\n", 0);
//	ft_printf("Invisible plus sign, fill 0, width 5: % 05d", 0);
	printf("Invisible plus sign, fill 0, width 5: % 05d\n", neg);
//	ft_printf("Invisible plus sign, fill 0, width 5: % 05d", neg);
	printf("Visible plus sign, fill 0, width 5: %+05d\n", 0);
//	ft_printf("Visible plus sign, fill 0, width 5: %+05d", 0);
	printf("Visible plus sign, fill 0, width 5: %+05d\n", pos);
//	ft_printf("Visible plus sign, fill 0, width 5: %+05d", pos);

/*
**	Precision
**	The minimum number of digits to be printed. Leading zeros will be added to
**	make up the field with.
**	No errors:
**	Combi with (pos value) --> '-', '0' are ignored
**	Combi with (pos value) --> '+' adds a plus sign
**	Combi with (pos value) --> ' ' provides invisible plus sign
**	Combi with (neg value) --> '-', '0', '+', ' ' are ignored
**	Neg value: min 7 digits, excluding '-'
*/
	printf("\nPrecision\n");
	printf("Value: 354, min digits: 7: %.7d\n", 354);
//	ft_printf("Value: 354, min digits: 7: %.7d\n", 354);
	printf("Value: 354, min digits: 7, minus: %-.7d\n", 354);
//	ft_printf("Value: 354, min digits: 7, minus: %-.7d\n", 354);
	printf("Value: 354, min digits: 7, zero: %0.7d\n", 354);
//	ft_printf("Value: 354, min digits: 7, zero: %0.7d\n", 354);
	printf("Value: 354, min digits: 7, plus: %+.7d\n", 354);
//	ft_printf("Value: 354, min digits: 7, plus: %+.7d\n", 354);
	printf("Value: 354, min digits: 7, space: % .7d\n", 354);
//	ft_printf("Value: 354, min digits: 7, space: % .7d\n", 354);
	printf("Neg value: -7354, min digits: 7: %.7d\n", -7354);
//	ft_printf("Neg value: -7354, min digits: 7: %.7d\n", -7354);
	printf("Neg value: -7354, min digits: 7, minus: %-.7d\n", -7354);
//	ft_printf("Neg value: -7354, min digits: 7, minus: %-.7d\n", -7354);
	printf("Neg value: -7354, min digits: 7, zero: %0.7d\n", -7354);
//	ft_printf("Neg value: -7354, min digits: 7, zero: %0.7d\n", -7354);
	printf("Neg value: -7354, min digits: 7, plus: %+.7d\n", -7354);
//	ft_printf("Neg value: -7354, min digits: 7, plus: %+.7d\n", -7354);
	printf("Neg value: -7354, min digits: 7, space: % .7d\n", -7354);
//	ft_printf("Neg value: -7354, min digits: 7, space: % .7d\n", -7354);

/*
**	Range check, if it is outside the range of the hh, h, l, ll flag
**	then it will not get printed.
**	flag l and flag ll work the same
*/
	printf("\nRange check: hh, h, l, ll\n");
	char		hh_char_pos = 97;
	char		hh_char_neg = -97;
	short		h_short_pos = 18000;
	short		h_short_neg = -18000;
	long		l_long_pos = 5248976532849578978;
	long		l_long_neg = -5248976532849578978;
	long long	ll_longlong_pos = 999999999999999999;
	long long	ll_longlong_neg = -999999999999999999;
	printf("hh pos, char (-128 tm 127): %hhi\n", hh_char_pos);
	printf("hh neg, char (-128 tm 127): %hhi\n", hh_char_neg);
//	printf("hh warning, char (-128 tm 127): %hhi\n", -130);
	//-130 OUTPUT: 126 (pos)
	printf("h pos, short (-32768 tm 32767): %hd\n", h_short_pos);
	printf("h neg, short (-32768 tm 32767): %hd\n", h_short_neg);
//	printf("h warning, short (-32768 tm 32767): %hd\n", -33000);
	//-33000 OUTPUT: 32536	
	printf("l pos, long (-2147483648 tm 2147483647): %ld\n", l_long_pos);
	printf("l neg, long (-2147483648 tm 2147483647): %ld\n", l_long_neg);
//	printf("l warning, long (-2147483648 tm 2147483647): %ld\n", 9223372036854775808);
	// 9223372036854775808 OUTPUT: -9223372036854775808 (long long)
	printf("ll pos, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", ll_longlong_pos);
	printf("ll neg, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", ll_longlong_neg);
//	printf("ll warning, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", 9923372036854775808);
	// 9223372036854775808 OUTPUT: -9223372036854775808 (long long) same
	// 9923372036854775808 OUTPUT: -8523372036854775808

//	ft_printf("hh pos, char (-128 tm 127): %hhi\n", hh_char_pos);
//	ft_printf("hh neg, char (-128 tm 127): %hhi\n", hh_char_neg);
//	ft_ft_printf("hh error, char (-128 tm 127): %hhi\n", -130);
//	ft_printf("h pos, short (-32768 tm 32767): %hd\n", h_short_pos);
//	ft_printf("h neg, short (-32768 tm 32767): %hd\n", h_short_neg);
//	ft_printf("h error, short (-32768 tm 32767): %hd\n", -3300);
//	ft_printf("l pos, long (-2147483648 tm 2147483647): %ld\n", l_long_pos);
//	ft_printf("l neg, long (-2147483648 tm 2147483647): %ld\n", l_long_neg);
//	ft_printf("l error, long (-2147483648 tm 2147483647): %ld\n", 999999999999999999999);
//	ft_printf("ll pos, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", ll_longlong_pos);
//	ft_printf("ll neg, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", ll_longlong_neg);
//	ft_printf("ll error, longlong (-9223372036854775807 tm 9223372036854775807): %lld\n", 999999999999999999999);

	//ERROR check, most of it will be ignored!! Check combinations
//	printf("error too big: %d\n", 2147483648);
	ft_printf("error too big: %d\n", 2147483648);
//	check range
	printf("No digit after '.' %.d\n", 35);
	
//	automatic error, when arg_list will be finished	
//	printf("Asterisk: %*d", 456);

//	printf("Most flags(error, ' ' is ignored when '+' is present): %-0+ 6.5d\n", 678);
//	printf("l_cap ignored %Ld\n (undefined behavior, 'L' is ignored?)\n", 678);
//	printf("hash %#d, %#+05d\n (flag '0' is ignored when flag '-' is present)\n", 786, 345);
	return (0);
}
