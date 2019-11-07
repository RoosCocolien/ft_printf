# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/11/07 15:24:33 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf
SRCS 	= srcs/ft_printf.c srcs/flags.c srcs/spec.c srcs/spec_c.c\
			srcs/spec_d_i.c srcs/spec_s.c srcs/spec_perc.c srcs/spec_f.c\
			srcs/spec_e.c srcs/spec_o.c srcs/ft_itoa_ll.c\
			srcs/flags2.c srcs/spec_x.c srcs/spec_u.c\
			srcs/spec_p.c srcs/spec_n.c srcs/ft_roundup.c srcs/ft_deci_count.c\
			srcs/print.c srcs/padding.c srcs/len_mod_di2.c srcs/ft_zero_count.c\
			srcs/len_mod_di.c srcs/len_mod_u.c srcs/len_mod_u2.c\
			srcs/ft_itoa_base_ll.c srcs/precision.c srcs/len_mod_ef.c\
			srcs/make_str_e.c srcs/colors.c srcs/make_str_f.c\
			srcs/roundup.c srcs/ft_digit_count.c

FLAG 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc srcs/main_simple.c libft/libft.a $(SRCS)

lib:
	@gcc -c -I includes/*.h libft/includes/*.h $(SRCS) $(SRCSLIBFT)
	@ar rc ext_test/libftprintf.a *.o
	@ranlib ext_test/libftprintf.a
	@rm -rf *.o

test:
	@make lib
	@cd ext_test && make test
	@cd ext_test && ./ft_printf_test  > ../test_results.txt && ./ft_printf_test

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

b:
	@gcc srcs/test_printf/main_b.c libft/libft.a $(SRCS)

zero:
	@gcc srcs/test_printf/main_zero.c libft/libft.a $(SRCS)

p:
	@gcc srcs/test_printf/main_p.c libft/libft.a $(SRCS)

clean:
	@rm -rf *.o

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
