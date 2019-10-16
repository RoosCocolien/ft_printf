/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   capture_stdout.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: thugo <marvin@42.fr>                         +#+                     */
/*                                                   +#+                      */
/*   Created: 2017/01/26 16:55:44 by thugo          #+#    #+#                */
/*   Updated: 2019/10/16 11:47:39 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPTURE_STDOUT_H
# define CAPTURE_STDOUT_H

# define BUFF_SIZE 2048

# define PIPE_READ 0
# define PIPE_WRITE 1

void	capture_start(void);
char	*capture_getbuffer(size_t *size);
void	capture_end(void);

#endif
