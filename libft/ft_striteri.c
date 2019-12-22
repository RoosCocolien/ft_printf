/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 11:39:53 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 11:39:54 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int cx;

	cx = 0;
	if (!s || !*s || !f || !*f)
		return ;
	while (s[cx] != '\0')
	{
		f(cx, (&s[cx]));
		cx++;
	}
}
