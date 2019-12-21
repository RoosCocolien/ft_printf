/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_o.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/07 15:48:33 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 23:08:10 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_o(char *s, va_list args, t_info *flag, int x)
{
	unsigned long long	i;
	int					length;
	int					fill;
	char				*oct_str;

	fill = 0;
	get_prec_width(args, flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	oct_str = ft_itoa_base_ll(i, 8, 0);
	length = ft_strlen(oct_str);
	fill = fill_width_prec(flag, length);
	if (s[x] == 'o' && (*flag).hash == 1 && (*flag).zero == 0 && i != 0)
		fill--;
	if ((*flag).width > 0 && (*flag).minus == 0 && fill > 0)
		put_padding(flag, fill);
	print_zero(flag, i, oct_str);
	ft_putstr_fd(oct_str, (*flag).fd);
	(*flag).count += length;
	if ((*flag).width > 0 && (*flag).minus == 1 && fill > 0)
		put_padding(flag, fill);
	if (oct_str)
		free(oct_str);
	return (x + 1);
}
