/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 13:25:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/02 17:15:01 by rsteigen      ########   odam.nl         */
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

typedef struct		s_info
{
	int				minus;
	int				zero;
	int				plus;
	int				space;
	int				hash;
	int				width;
	int				asterisk;
	int				precision;
	int				prec_value;
	int				prec_no_val;
	int				l;
	int				ll;
	int				h;
	int				hh;
	int				l_cap;
	int				neg;
	int				count;
	int				power;
	char			power_not;
	int				no_decimals;
	int				dot;
	int				leftover;
}					t_info;

/*
**	ft_printf.c
*/

int					ft_printf(const char *restrict format, ...);
int					loop_format_args(char *s, va_list args);

/*
**	conversion specifiers functions
*/

int					find_spec(char *s, va_list args, t_info *flag, int x);
int					find_spec_2(char *s, va_list args, t_info *flag, int x);
int					spec_d_i(char *s, va_list args, t_info *flag, int x);
int					spec_f(char *s, va_list args, t_info *flag, int x);
int					spec_s(char *s, va_list args, t_info *flag, int x);
int					spec_c(char *s, va_list args, t_info *flag, int x);
int					spec_perc(char *s, va_list args, t_info *flag, int x);
int					spec_e(char *s, va_list args, t_info *flag, int x);
int					spec_o(char *s, va_list args, t_info *flag, int x);
int					spec_x(char *s, va_list args, t_info *flag, int x);
int					spec_x2(char *s, va_list args, t_info *flag, int x);
int					spec_u(char *s, va_list args, t_info *flag, int x);
int					spec_p(char *s, va_list args, t_info *flag, int x);

/*
**	print functions
*/

void				print_digit(t_info *flag, unsigned long long nb);
void				print_address(t_info *flag, char *s);
void				print_string(t_info *flag, char *s, int fill);
void				print_neg(t_info *flag);
void				print_zero(t_info *flag, long long i, char *oct_str,\
int fill);

/*
**	length modifier functions
*/

unsigned long long	len_mod_check_di(va_list args, t_info *flag);
unsigned long long	check_int(va_list args, t_info *flag);
long double			len_mod_check_efg(va_list args, t_info *flag);
intmax_t			len_mod_check_u(va_list args, t_info *flag,\
char conv_spec);
unsigned long long	check_u(va_list args, t_info *flag, char conv_spec);

/*
**	make string functions
*/

char				*make_str_e(long double i, t_info *flag, char e_not);
long double			find_power(long double i, t_info *flag);
char				*make_str_f(long double i, t_info *flag);

/*
**	save flags functions
*/

int					save_flags(char *s, t_info *flag, int x);
int					check_precision(char *s, t_info *flag, int x);
void				set_zero_flags(t_info *flag);
int					check_flag_plus(t_info *flag, int fill, int left_align);
int					check_flag_space(t_info *flag, int fill, int left_align);
int					save_prec_width(char *s, t_info *flag, int x);

/*
**	colors.c
*/

int					color_setter(char *str, int x);

/*
**	precision
*/

void				prec_and_zero_check(va_list args, t_info *flag, char spec);
int					fill_width_prec(t_info *flag, int length);
void				pres_width_s(va_list args, t_info *flag);
void				get_prec_width(va_list args, t_info *flag, char spec);

/*
**	roundup
*/

unsigned long long	ten_to_the_power_of(int power);
long double			roundup_e(long double i, t_info *flag, int prec);
long double			roundup_f(long double i, int prec);

/*
**	padding.c
*/

int					put_0x_spec_f(int count, char spec);
int					change_fill(t_info *flag, int fill, int length);
void				put_padding(t_info *flag, int fill);
void				put_padding_w(t_info *flag, int fill_w);

#endif
