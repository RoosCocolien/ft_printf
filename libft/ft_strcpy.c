/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:45:18 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/11 13:45:21 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int cx;

	cx = 0;
	while (src[cx] != '\0')
	{
		dst[cx] = src[cx];
		cx++;
	}
	dst[cx] = '\0';
	return (dst);
}
