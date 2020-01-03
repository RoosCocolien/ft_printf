#include <stdio.h>
#include "includes/ft_printf.h"
#include <fcntl.h>

int		main(void)
{
	int fd1;
	int fd2;

	fd1 = open("file1.txt", O_RDWR);
	fd2 = open("file2.txt", O_RDWR);
	ft_printf("{red}hallo %s{eoc} Roos\n", "goedemiddag");
	dprintf(fd1, "Dit is een float: %.2f\n", 0.35F);
	ft_dprintf(fd2, "Dit is een float: %.2f\n", 0.35F);
	printf("Dit is e: %e\n", 456F);
	ft_printf("Dit is e: %e\n", 456F);
	return (0);
}
