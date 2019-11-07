# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/11/07 18:40:53 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_memchr.c ft_strncpy.c ft_strstr.c ft_isdigit.c ft_memalloc.c\
            ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcpy.c\
            ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
            ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
            ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
            ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
			ft_striteri.c ft_strjoin.c ft_putendl.c ft_putnbr_fd.c ft_lstmap.c\
            ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
            ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c\
            ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
            ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
            ft_printtlist.c ft_printelem.c ft_strnlen.c ft_strcharfind.c\
            ft_strsldup.c ft_sqrt.c ft_lstpushback.c ft_itoa_base.c\
            ft_itoa_base_cap.c ft_intlength.c ft_digit_count.c\
            ft_itoa_base_ll.c ft_itoa_llu.c

LIBO = *.o
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c -I includes $(SRCS)
	@ar rc $(NAME) $(SRCS:.c=.o)
	@ranlib $(NAME)

compile: $(NAME)
	@gcc $(FLAG) main.c -L. -lft

clean:
	@rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
