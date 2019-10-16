# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: thugo <marvin@42.fr>                         +#+                      #
#                                                    +#+                       #
#    Created: 2017/01/19 23:08:09 by thugo          #+#    #+#                 #
#    Updated: 2019/10/16 14:28:21 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf_test
SRC = src/main.c src/tests_normal.c src/capture_stdout.c src/tests_bonus.c
INCLUDE_DIR = ./includes
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -I -o $(INCLUDE_DIR) $(NAME) $(OBJ) -L. -lftprintf ../libft/libft.a

%.o: %.c
	gcc -Wno-format -I $(INCLUDE_DIR) -c $^ -o $@

test:
	gcc -o $(NAME) src/*.c -L. -lftprintf ../libft/libft.a $(SRCS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)

run: $(NAME)
	./$(NAME)
