/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:48:34 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 18:41:46 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

static void	reset_precision_values(t_info *flag)
{
	(*flag).prec_value = 0;
	(*flag).precision = 1;
	(*flag).prec_no_val = 1;
}

static int	flags_part_three(char *s, t_info *flag, int x)
{
	if (s[x] == '#')
	{
		(*flag).hash = 1;
		x++;
	}
	else if (s[x] == '.')
	{
		if ((s[x + 1] >= '0' && s[x + 1] <= '9') || s[x + 1] == '*')
			x = check_precision(s, flag, x);
		else
		{
			reset_precision_values(flag);
			x++;
		}
	}
	else if (s[x] == 'l' && s[x - 1] != 'l')
	{
		(*flag).ll = 0;
		(*flag).l = 1;
		x++;
	}
	else
		x = flags_part_four(s, flag, x);
	return (x);
}

static int	flags_part_two(char *s, t_info *flag, int x)
{
	if ((s[x] > 48 && s[x] <= 57) && s[x - 1] != '.')
		x = save_prec_width(s, flag, x);
	else if (s[x] == '*' && s[x - 1] != '.' && (*flag).asterisk == 0)
	{
		if (s[x + 1] > 48 && s[x + 1] <= 57)
		{
			x = save_prec_width(s, flag, x + 1);
			(*flag).precision = -1;
		}
		else
		{
			(*flag).width = -1;
			if ((*flag).sequence == 0)
				(*flag).sequence--;
			else
				(*flag).sequence++;
			x++;
		}
		(*flag).asterisk = 1;
	}
	else
		x = flags_part_three(s, flag, x);
	return (x);
}

static int	flags_part_one(char *s, t_info *flag, int x)
{
	if (s[x] == '-')
	{
		(*flag).minus = 1;
		x++;
	}
	else if (s[x] == '0')
	{
		(*flag).zero = 1;
		x++;
	}
	else if (s[x] == '+')
	{
		(*flag).plus = 1;
		x++;
	}
	else if (s[x] == ' ')
	{
		(*flag).space = 1;
		x++;
	}
	else
		x = flags_part_two(s, flag, x);
	return (x);
}

int			save_flags(char *s, t_info *flag, int x)
{
	int		i;

	set_zero_flags(flag);
	while (s[x] && (s[x] == '-' || s[x] == '0' || s[x] == '+' ||\
	(s[x] > '0' && s[x] <= '9') || s[x] == ' ' || s[x] == '#' ||\
	s[x] == '*' || s[x] == '.' || s[x] == 'l' || s[x] == 'h' ||\
	s[x] == 'L'))
	{
		i = x;
		x = flags_part_one(s, flag, i);
		if (x == -1)
			return (-1);
	}
	return (x);
}
