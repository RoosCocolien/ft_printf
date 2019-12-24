/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_f.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/24 18:15:44 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/24 10:40:50 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	print_nan_f(t_info *flag)
{
	if ((*flag).f_nan == 1)
	{
		(*flag).count += 3;
		ft_putstr_fd("nan", (*flag).fd);
	}
	if ((*flag).f_inf == 1)
	{
		(*flag).count += 3;
		ft_putstr_fd("inf", (*flag).fd);
	}
	if ((*flag).f_inf == -1)
	{
		(*flag).count += 4;
		ft_putstr_fd("-inf", (*flag).fd);
		(*flag).neg = 1;
	}
}

static int	check_length_f(t_info *flag, char *str_spec_f)
{
	int				length;

	length = 0;
	if ((*flag).f_nan == 1 || (*flag).f_inf == 1)
		length = 3;
	else if ((*flag).f_inf == -1)
		length = 4;
	else
		length = ft_strlen(str_spec_f);
	return (length);
}

static int	check_nan_inf(long double i, t_info *flag)
{
	if (i != i)
	{
		(*flag).f_nan = 1;
		return (0.0);
	}
	else if (i > 1.797e308)
	{
		(*flag).f_inf = 1;
		return (0.0);
	}
	else
	{
		(*flag).f_nan = 1;
		return (0.0);
	}
}

int			spec_f(char *s, va_list args, t_info *flag, int x)
{
	long double		i;
	char			*str_spec_f;
	int				length;
	int				fill;

	fill = 0;
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_efg(args, flag);
	if (i != i || i > (1.797e308) || i < (-1.797e308))
		i = check_nan_inf(i, flag);
	str_spec_f = make_str_f(i, flag);
	length = check_length_f(flag, str_spec_f);
	fill = change_fill(flag, fill, length);
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	print_neg(flag, length, s[x]);
	print_string(flag, str_spec_f);
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	free(str_spec_f);
	return (x + 1);
}
