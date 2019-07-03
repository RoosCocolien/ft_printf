/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:26:16 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 15:26:17 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int cx;
	int	div;

	cx = 0;
	while (s1[cx] == s2[cx])
	{
		if (s1[cx] == '\0' || s2[cx] == '\0')
			return (s1[cx] - s2[cx]);
		cx++;
	}
	div = (unsigned char)s1[cx] - (unsigned char)s2[cx];
	return (div);
}
