/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_str_o.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 12:15:11 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/30 21:15:06 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	change_settings_hash_o(char *oct, t_info *flag, t_padding *padding)
{
	int		len;

	len = ft_strlen(oct);
	if ((*padding).fill_p > 0)
		(*flag).hash = 0;
	else
	{
		if ((*flag).width - len > 0 && (*flag).zero == 1 && (*flag).minus != 1)
		{
			(*flag).hash = 0;
		}
	}
}

char		*fill_oct_with_zeros(t_info *flag, t_padding *padding)
{
	char	*zeros;
	int		malloc_size;
	int		x;

	x = 0;
	if ((*flag).hash == 0)
		malloc_size = (*padding).fill_p;
	else
		malloc_size = (*flag).hash;
	zeros = (char*)malloc(sizeof(char) * (malloc_size + 1));
	while (malloc_size > 0)
	{
		zeros[x] = '0';
		x++;
		malloc_size--;
	}
	zeros[x] = '\0';
	return (zeros);
}

char		*make_oct_str(unsigned long long i, t_info *flag,
			t_padding *padding)
{
	char	*oct;
	char	*zeros;
	char	*oct_str;

	zeros = NULL;
	oct = ft_itoa_base_ll(i, 8, 0);
	(*padding).length = check_length_zero(i, oct, flag);
	(*padding).fill_p = fill_precision(flag, (*padding).length);
	if ((*padding).fill_p > 0)
		(*flag).zero = 0;
	change_settings_hash_o(oct, flag, padding);
	if ((*flag).hash == 1 && (i != 0 || (i == 0 && (*padding).length == 0)))
		(*padding).length++;
	if ((*padding).fill_p < 1 && ((*flag).hash == 0 || i == 0))
		oct_str = ft_strdup(oct);
	else
	{
		zeros = fill_oct_with_zeros(flag, padding);
		oct_str = ft_strjoin(zeros, oct);
		free(zeros);
	}
	free(oct);
	return (oct_str);
}
