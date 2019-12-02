/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_x_2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:37:53 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/02 18:14:41 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char	*fill_str_with_zeros(intmax_t i, t_info *flag, int len, char spec)
{
	int		fill;
	char	*zeros;
	int		x;

	x = 0;
	fill = (*flag).prec_value - len;
	zeros = (char*)malloc(sizeof(char) * (fill + 1));
	printf("%d (fill_str_with_zeros)\n", fill);
	while (fill > 0)
	{
		if (x == 1 && ((spec == 'p' || ((*flag).hash == 1 && i != 0))/*&& (*flag).zero != 0*/))
		{
			printf("CHECK\n");
			if (spec == 'X')
				zeros[x] = 'X';
			else
				zeros[x] = 'x';
		}
		else
			zeros[x] = '0';
		fill--;
		x++;
	}
	zeros[x] = '\0';
	return (zeros);
}

static char	*get_hex_str(intmax_t i, t_info *flag, char spec)
{
	char	*hex;
	int		length;
	char	*hex_str;
	char	*zeros;

	if (spec == 'x' || spec == 'p')
		hex = ft_itoa_base_ll(i, 16, 0);
	else
		hex = ft_itoa_base_ll(i, 16, 1);
	length = ft_strlen(hex);
	if ((*flag).hash == 1 && (*flag).prec_value <= length + 1)
	{
		if ((*flag).prec_value == length + 1)
			(*flag).prec_value += 1;
		else
			(*flag).prec_value += 2;
	}
	if ((*flag).prec_value <= length && (*flag).hash == 0)
		hex_str = ft_strdup(hex);
	else
	{
		zeros = fill_str_with_zeros(i, flag, length, spec);
		hex_str = ft_strjoin(zeros, hex);
		free(zeros);
	}
	free(hex);
	return (hex_str);
}

int			spec_x2(char *s, va_list args, t_info *flag, int x)
{
	intmax_t		i;
	int				length;
//	int				fill_p; (don't need it, I put it in the string)
	int				fill_w;
	char			*hex_str;

	// fill_p = 0;
	fill_w = 0;
	prec_and_zero_check(args, flag, s[x]);
	i = len_mod_check_u(args, flag, s[x]);
	hex_str = get_hex_str(i, flag, s[x]);
	length = ft_strlen(hex_str);
	//X) calculate fill_p (add 0's to string on left side)
	//1) calculate fill_w
	fill_w = (*flag).width - length;
	//2) if (fill_w && right aligned), put padding width ' ' beginning of string
	if (fill_w > 0 && (*flag).minus == 0)
		put_padding(flag, fill_w);
	//X) put 0x if spec == p || #
	//X) if (fill_p) put padding precision, add '0's
	//3) put string
	print_address(flag, hex_str);
	//4) if (fill_w && left aligned) put padding width ' ' end of string
	if (fill_w > 0 && (*flag).minus != 0)
		put_padding(flag, fill_w);
	free(hex_str);
	return (x + 1);
}
