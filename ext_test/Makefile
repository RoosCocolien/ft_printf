# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: thugo <marvin@42.fr>                         +#+                      #
#                                                    +#+                       #
#    Created: 2017/01/19 23:08:09 by thugo          #+#    #+#                 #
#    Updated: 2019/10/16 11:46:04 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf_test
SRC = src/main.c src/tests_normal.c src/capture_stdout.c src/tests_bonus.c
INCLUDE_DIR = ./includes
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -I $(INCLUDE_DIR) -o $(NAME) $(OBJ) -L. -lftprintf

%.o: %.c
	gcc -Wno-format -I $(INCLUDE_DIR) -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean $(NAME)

run: $(NAME)
	./$(NAME)
