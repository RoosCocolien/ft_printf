/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 13:25:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/11/07 15:47:49 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

/*
**	remove <stdio.h>
*/
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <unistd.h>

/*
**	I have to add the hh, h, l, ll and L flags...
**	And the precision specifier
*/
typedef struct s_info
{
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;		//WHAT DOES HASH DO????
	int		width;		//what's up with '*', does it do something?
	int		asterisk;	//width
	int		precision;	//0 == off, 1 == on (default), 2 == *
	int		prec_value;	//this will be the int after '.' in case of a '*', the value is computed from the next arg, must be an int
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		l_cap;
	int		neg;
	int		count;
	int		power;
	char	power_not;	//power notation (e or E)
	int		no_decimals;	//off or on ('.' or no '.') (floats, eE etc.)
	int		dot;		//for spec_g, spec_f and spec_e
	int		leftover;
}				t_info;

//Moeten naar libft
char					*ft_itoa_llu(unsigned long long n);	//deze gebruik ik, verplaatsen naar libft
int						ft_intlength(unsigned long long y);	//zelfde als digit count?
unsigned long long   	ft_roundup(unsigned long long d);	//
int     				ft_deci_count(double d);
int     				ft_zero_count(char *str);
char					*ft_itoa_base_ll(intmax_t value, int base, int cap);	//deze gebruik ik, verplaatsen naar libft
size_t					ft_digit_count(intmax_t value, int base);	//deze gebruik ik

/*
**	print.c
*/
void					print_digit(t_info *flag, unsigned long long nb);
void					print_address(t_info *flag, char *s);
void					print_string(t_info *flag, char *s, int fill);
void					print_neg(t_info *flag);

/*
**	ft_printf.c
*/
int						ft_printf(const char *restrict format, ...);
int						loop_format_args(char *s, va_list args);

/*
**	len_mod_di.c
*/
unsigned long long		len_mod_check_di(va_list args, t_info *flag);

/*
**	len_mod_di2.c
*/
unsigned long long		check_int(va_list args, t_info *flag);

/*
**	len_mod_ef.c
*/
long double				len_mod_check_efg(va_list args, t_info *flag);

/*
**	len_mod_u.c
*/
intmax_t				len_mod_check_u(va_list args, t_info *flag,\
char conv_spec);

/*
**	len_mod_u2.c
*/
unsigned long long		check_u(va_list args, t_info *flag, char conv_spec);

/*
**	make_str_e.c
*/
char					*make_str_e(long double i, t_info *flag, char e_not);
long double				find_power(long double i, t_info *flag);

/*
**	make_str_f.c
*/
char					*make_str_f(long double i, t_info *flag);

/*
**	flags.c
*/
int						save_flags(char *s, t_info *flag, int x);

/*
**	flags2.c
*/
int						check_precision(char *s, t_info *flag, int x);
void					set_zero_flags(t_info *flag);
int						check_flag_plus(t_info *flag, int fill, int left_align);
int						check_flag_space(t_info *flag, int fill, int left_align);
int						save_prec_width(char *s, t_info *flag, int x);

/*
**	colors.c
*/
int						color_setter(char *str, int x);

/*
**	precision.c
*/
void					prec_and_zero_check(va_list args, t_info *flag, char spec);
int						fill_width_prec(t_info *flag, int length);

/*
**	roundup.c
*/
unsigned long long		ten_to_the_power_of(int power);
long double				roundup_e(long double i, t_info *flag, int prec);
long double				roundup_f(long double i, int prec);

/*
**	spec.c
*/
int						find_spec(char *s, va_list args, t_info *flag, int x);
int						find_spec_2(char *s, va_list args, t_info *flag, int x);

/*
**	spec_d_i.c
*/
int						spec_d_i(char *s, va_list args, t_info *flag, int x);

/*
**	error_d_i.c
*/
int						error_d_i(t_info flag, long long int i);

/*
**	spec_f.c
*/
int						spec_f(char *s, va_list args, t_info *flag, int x);

/*
**	spec_s.c
*/
int						spec_s(char *s, va_list args, t_info *flag, int x);

/*
**	spec_c.c
*/
int						spec_c(char *s, va_list args, t_info *flag, int x);

/*
**	spec_perc.c
*/
int						spec_perc(char *s, va_list args, t_info *flag, int x);

/*
**	spec_e.c
*/
int						spec_e(char *s, va_list args, t_info *flag, int x);
int						spec_e(char *s, va_list args, t_info *flag, int x);

/*
**	spec_o.c
*/
int						spec_o(char *s, va_list args, t_info *flag, int x);

/*
**	spec_x.c
*/
int						spec_x(char *s, va_list args, t_info *flag, int x);

/*
**	spec_u.c
*/
int						spec_u(char *s, va_list args, t_info *flag, int x);

/*
**	spec_p.c
*/
int						spec_p(char *s, va_list args, t_info *flag, int x);

/*
**	spec_n.c
*/
int						spec_n(char *s, va_list args, t_info *flag, int x);

/*
**	padding.c
*/
int						put_0x_spec_f(int count, char spec);
int						change_fill(t_info *flag, int fill, int length);
void					put_padding(t_info *flag, int fill);

#endif