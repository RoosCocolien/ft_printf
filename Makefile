# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/10/10 15:39:46 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf
SRCS 	= srcs/ft_printf.c srcs/flags.c srcs/spec.c srcs/spec_c.c\
			srcs/spec_d_i.c srcs/spec_s.c srcs/spec_perc.c srcs/spec_f.c\
			srcs/spec_e.c srcs/spec_g.c srcs/spec_o.c srcs/ft_itoa_ll.c\
			srcs/flags2.c srcs/spec_x.c srcs/spec_b1.c srcs/spec_u.c\
			srcs/spec_p.c srcs/spec_n.c srcs/ft_roundup.c srcs/ft_deci_count.c\
			srcs/print.c srcs/padding.c srcs/len_mod_di2.c srcs/ft_zero_count.c\
			srcs/len_mod_di.c srcs/len_mod_u.c srcs/len_mod_u2.c\
			srcs/ft_itoa_base_ll.c srcs/precision.c srcs/len_mod_efg.c\
			srcs/make_str_e.c srcs/colors.c srcs/spec_b2.c srcs/make_str_f.c\
			srcs/roundup.c srcs/make_str_g.c srcs/spec_g2.c\
			srcs/spec_g_zero.c

FLAG 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc srcs/main_simple.c libft/libft.a $(SRCS)

leaks:
	@gcc -g srcs/main_simple.c libft/libft.a $(SRCS)

c:
	@gcc srcs/test_printf/main_c.c libft/libft.a $(SRCS)

di:
	@gcc srcs/test_printf/main_d_i2.c libft/libft.a $(SRCS)

e:
	@gcc srcs/test_printf/main_e.c libft/libft.a $(SRCS)

o:
	@gcc srcs/test_printf/main_o.c libft/libft.a $(SRCS)

s:
	@gcc srcs/test_printf/main_s.c libft/libft.a $(SRCS)

u:
	@gcc srcs/test_printf/main_u.c libft/libft.a $(SRCS)

x:
	@gcc srcs/test_printf/main_x.c libft/libft.a $(SRCS)
   
f:
	@gcc srcs/test_printf/main_f.c libft/libft.a $(SRCS)

g:
	@gcc srcs/test_printf/main_g.c libft/libft.a $(SRCS)

b:
	@gcc srcs/test_printf/main_b.c libft/libft.a $(SRCS)

zero:
	@gcc srcs/test_printf/main_zero.c libft/libft.a $(SRCS)

p:
	@gcc srcs/test_printf/main_p.c libft/libft.a $(SRCS)

clean:
	@rm -rf $(SRCS:.c=.o)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

