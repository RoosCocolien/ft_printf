/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_fd.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rsteigen <rsteigen@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/21 17:37:10 by rsteigen       #+#    #+#                */
/*   Updated: 2019/12/21 22:58:49 by rooscocolie   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../includes/printf.h"

static void check_c_fd(void)
{
	dprintf(1, "%c\n", 'r');
	ft_dprintf(1, "%c\n", 'r');
	dprintf(0, "%c\n", 'r');
	ft_dprintf(0, "%c\n", 'r');
}

static void check_s_fd(void)
{
	int fd1;
	int ft_fd1;

	fd1 = open("file1.txt", O_RDWR);
	ft_fd1 = open("ft_file1.txt", O_RDWR);
	dprintf(1, "%s\n", "roos");
	ft_dprintf(1, "%s\n", "roos");
	dprintf(fd1, "%s\n", "roos");
	ft_dprintf(ft_fd1, "%s\n", "roos");
}

int		main(void)
{
	// check_c_fd();
	// check_di_fd();
	// check_e_fd();
	// check_f_fd();
	// check_o_fd();
	// check_p_fd();
	// check_perc_fd();
	check_s_fd();
	// check_u_fd();
	// check_x_fd();
	return (0);
}