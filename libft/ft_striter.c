/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bvan-de- <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 10:20:20 by bvan-de-      #+#    #+#                 */
/*   Updated: 2019/01/18 10:21:41 by bvan-de-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int cx;

	cx = 0;
	if (!s || !*s || !f || !*f)
		return ;
	while (s[cx] != '\0')
	{
		(*f)(&s[cx]);
		cx++;
	}
}
