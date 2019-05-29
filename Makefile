# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/03/27 16:27:20 by bvan-de-      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf
SRCS 	= srcs\*.c\

FLAG 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRCS)
	@gcc $(FLAG) $(SRCS:.c=.o) -o $(NAME) libft/libft.a
   
clean:
	@rm -rf $(SRCS:.c=.o)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

