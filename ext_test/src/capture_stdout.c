/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   capture_stdout.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: thugo <marvin@42.fr>                         +#+                     */
/*                                                   +#+                      */
/*   Created: 2017/01/26 16:55:28 by thugo          #+#    #+#                */
/*   Updated: 2019/10/16 11:48:57 by rsteigen      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "capture_stdout.h"

extern int	errno;
static int	dup_stdout = -1;
static int	dup_pipe_write;
static int	pipefd[2];

static void	disable_block_fd(int fd)
{
	int	flags;

	flags = fcntl(fd, F_GETFL);
	fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}

void	capture_start()
{
	if (dup_stdout != -1)
	{
		fprintf(stderr, "Err: Capture already started.\n");
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) != 0)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	dup_stdout = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	dup_pipe_write = dup(pipefd[PIPE_WRITE]);
	disable_block_fd(pipefd[PIPE_READ]);
}

char	*capture_getbuffer(size_t *size)
{
	char	*fullbuffer;
	char	*newbuffer;
	char	buffer[BUFF_SIZE];
	long	sread;

	*size = 0;
	newbuffer = NULL;
	fullbuffer = NULL;
	while ((sread = read(pipefd[PIPE_READ], buffer, BUFF_SIZE)) > 0)
	{
		if ((newbuffer = (char *)malloc(sizeof(char) * (sread + *size))) == NULL)
			exit(EXIT_FAILURE);
		if (*size > 0)
			memcpy(newbuffer, fullbuffer, *size);
		memcpy(newbuffer + *size, buffer, sread);
		if (*size > 0)
			free(fullbuffer);
		fullbuffer = newbuffer;
		*size += sread;
	}
	return (fullbuffer);
}

void	capture_end()
{
	if (dup_stdout == -1)
	{
		fprintf(stderr, "Err: Capture already stopped.\n");
		exit(EXIT_FAILURE);
	}
	close(pipefd[PIPE_READ]);
	close(pipefd[PIPE_WRITE]);
	close(dup_pipe_write);
	dup(dup_stdout);
	close(dup_stdout);
	dup_stdout = -1;
}
