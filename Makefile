# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/06/27 16:19:44 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf
SRCS 	= srcs/ft_printf.c srcs/flags.c srcs/spec.c srcs/spec_c.c\
			srcs/spec_d_i.c srcs/spec_s.c srcs/spec_perc.c srcs/spec_f.c\
			srcs/spec_eE.c srcs/spec_g.c srcs/spec_o.c srcs/ft_itoa_ll.c\
			srcs/flags2.c srcs/spec_x.c srcs/spec_b.c srcs/spec_u.c\
			srcs/spec_p.c srcs/spec_n.c srcs/ft_roundup.c srcs/ft_deci_count.c\
			srcs/print.c srcs/padding.c srcs/len_mod2.c

FLAG 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc srcs/main_simple.c libft/libft.a $(SRCS)
   
clean:
	@rm -rf $(SRCS:.c=.o)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

