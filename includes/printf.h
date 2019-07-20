/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/25 13:25:23 by rsteigen       #+#    #+#                */
/*   Updated: 2019/07/10 14:58:35 by rsteigen      ########   odam.nl         */
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
	int		hash;
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
}				t_info;


//Moeten naar libft
char					*ft_itoa_llu(unsigned long long n);
int						ft_intlength(unsigned long long y);
long long unsigned   	ft_roundup(unsigned long long d);
int     				ft_deci_count(double d);
int     				ft_zero_count(char *str);
char					*ft_itoa_base_ll(long long value, int base);

/*
**	print.c
*/
void					print_flags(t_info flag); //kan weg
void					print_digit(t_info *flag, unsigned long long nb);

/*
**	ft_printf.c
*/
int						ft_printf(const char * restrict format, ...);
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
**	len_mod_uoxX.c
*/
unsigned long long		len_mod_check_uoxX(va_list args, t_info *flag,\
char conv_spec);

/*
**	len_mod_uoxX2.c
*/
unsigned long long		check_uoxX(va_list args, t_info *flag, char conv_spec);

/*
**	flags.c
*/
int						save_flags(char *s, t_info *flag, int x);

/*
**	flags2.c
*/
int						check_precision(char *s, t_info *flag, int x);
void					set_zero_flags(t_info *flag, int start_count);
int						check_flag_plus(t_info *flag, int fill, int left_align);
int						check_flag_space(t_info *flag, int fill, int left_align);

/*
**	spec.c
*/
int						find_spec(char *s, va_list args, t_info *flag, int x);
int						find_spec_2(/*char *s, va_list args, t_info *flag, */int x);

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
void					ft_putdouble(long long unsigned int d);
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
**	spec_eE.c
*/
int						spec_eE(char *s, va_list args, t_info *flag, int x);

/*
**	spec_g.c
*/
int						spec_g(char *s, va_list args, t_info *flag, int x);


/*
**	spec_o.c
*/
int						spec_o(char *s, va_list args, t_info *flag, int x);



/*
**	spec_x.c
*/
int						spec_xX(char *s, va_list args, t_info *flag, int x);


/*
**	spec_b.c BONUS
*/
int						spec_b(char *s, va_list args, t_info *flag, int x);


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
void					put_padding(t_info *flag, int zero, int fill, int neg);

#endif