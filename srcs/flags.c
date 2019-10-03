/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 11:48:34 by rsteigen       #+#    #+#                */
/*   Updated: 2019/09/25 15:59:40 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

/*
**	These four functions check which flags should be toggled
**	on.
**	In the case of an illigal option, the function will return (-1)
*/

/*
**	Asterisk: if the asterisk is present, the width function will
**	be toggled on as well. The width value is computed from the next
**	arg and must be an int. This value will not be used for other
**	things.
*/

static int	flags_part_four(char *s, t_info *flag, int x)
{
	if (s[x] == 'h' && s[x - 1] != 'h')
	{
		(*flag).hh = 0;
		(*flag).h = 1;
		x++;
	}
	else if (s[x] == 'h' && s[x - 1] == 'h')
	{
		(*flag).h = 0;
		(*flag).hh = 1;
		x++;
	}
	else if (s[x] == 'L')
	{
		(*flag).l_cap = 1;
		x++;
	}
	else if (s[x] == 'd' || s[x] == 'i' || s[x] == 'f' || s[x] == 'c'\
	|| s[x] == 's' || s[x] == '%' || s[x] == 'e' || s[x] == 'E'\
	|| s[x] == 'g' || s[x] == 'n' || s[x] == 'o' || s[x] == 'p'\
	|| s[x] == 'u' || s[x] == 'x')
	{
		return (x);
	}
	else
	{
		printf("Error flags.c (flags_part_three)\n");
		return (-1);
	}
	return (x);
}

static int	flags_part_three(char *s, t_info *flag, int x)
{
	if (s[x] == '*' && s[x - 1] != '.' && (*flag).asterisk == 0)
	{
		(*flag).asterisk = 1;
		(*flag).width = 1;
		x++;
	}
	else if (s[x] == '.' && (*flag).precision == 0)
	{
		x = check_precision(s, flag, x);
	}
	else if (s[x] == 'l' && s[x - 1] != 'l')
	{
		(*flag).ll = 0;
		(*flag).l = 1;
		x++;
	}
	else if (s[x] == 'l' && s[x - 1] == 'l')
	{
		(*flag).l = 0;
		(*flag).ll = 1;
		x++;
	}
	else
		x = flags_part_four(s, flag, x);
	return (x);
}

static int	flags_part_two(char *s, t_info *flag, int x)
{
	int		i;
	char	*width;

	if (s[x] == ' ' && (*flag).space == 0)
	{
		(*flag).space = 1;
		x++;
	}
	else if (s[x] == '#' && (*flag).hash == 0)
	{
		(*flag).hash = 1;
		x++;
	}
	else if ((s[x] > 48 && s[x] <= 57) && s[x - 1] != '.')
	{
		i = x;
		while (s[x] >= 48 && s[x] <= 57)
			x++;
		width = ft_strsub(s, i, x - i);
		(*flag).width = ft_atoi(width);
	}
	else
		x = flags_part_three(s, flag, x);
	return (x);
}

static int	flags_part_one(char *s, t_info *flag, int x)
{
	if (s[x] == '-' && (*flag).minus == 0)
	{
		(*flag).minus = 1;
		x++;
	}
	else if (s[x] == '0' && (*flag).zero == 0)
	{
		(*flag).zero = 1;
		x++;
	}
	else if (s[x] == '+' && (*flag).plus == 0)
	{
		(*flag).plus = 1;
		x++;
	}
	else
		x = flags_part_two(s, flag, x);
	return (x);
}

int			save_flags(char *s, t_info *flag, int x)
{
	int		i;

	while (s[x] && (s[x] == '-' || s[x] == '0' || s[x] == '+' ||\
	(s[x] > '0' && s[x] <= '9') || s[x] == ' ' || s[x] == '#' ||\
	s[x] == '*' || s[x] == '.' || s[x] == 'l' || s[x] == 'h' ||\
	s[x] == 'L'))
	{
		i = x;
		x = flags_part_one(s, flag, i);
		if (x == -1)
		{
			printf("Error flags.c (flags_part_one)\n");
			return (-1);
		}
	}
	return (x);
}
