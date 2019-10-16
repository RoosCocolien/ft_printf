/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   spec_g_zero.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 16:44:00 by rooscocolie    #+#    #+#                */
/*   Updated: 2019/10/16 10:50:30 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char	*fill_after_g(char *after, int len, int zeros)
{
	char	*after_g;
	int		i;

	i = 1;  //sla de '.' over
	after_g = (char*)malloc(sizeof(char) * (len - zeros + 2));
	after_g[len - zeros + 2] = '\0';
	after_g[0] = '.';
	while (i < len - zeros)
	{
		after_g[i] = after[i];
		i++;
	}
	return (after_g);
}

char		*erase_zeros_for_spec_g(char *after, t_info *flag)
{
	int		len;
	int		zeros;
	char	*after_g;
	int		i;

	zeros = 0;
	len = ft_strlen(after);
	i = len - 1;
	while (after[i] == '0')
	{
		zeros++;
		i--;
	}
	if (zeros == 0)
	{
		after_g = ft_strsub(after, 0, ft_strlen(after));
		return (after_g);
	}
	else if (zeros == ft_strlen(after) - 1)
		return (NULL);
	else
		after_g = fill_after_g(after, len, zeros);
	if (zeros == len - 1 && (*flag).hash != 1)
		(*flag).dot = 0;
	return (after_g);
}
