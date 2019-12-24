# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: bvan-de- <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/15 14:53:31 by bvan-de-       #+#    #+#                 #
#    Updated: 2019/12/23 21:39:38 by rsteigen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= libft
SRCS 	= ft_printf.c flags.c spec.c spec_c.c\
			spec_d_i.c spec_s.c spec_perc.c spec_f.c\
			spec_e.c spec_o.c flags2.c spec_x.c\
			spec_u.c spec_p.c print.c padding.c\
			len_mod_di2.c len_mod_di.c len_mod_u.c\
			len_mod_u2.c precision.c len_mod_ef.c\
			make_str_e.c colors.c make_str_f.c make_str_x.c\
			roundup.c print_content.c floats.c\
			ft_printf_loop_args.c asterisk.c zero_value.c
LIBFUNC	= libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c\
			libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c\
			libft/ft_strstr.c libft/ft_isdigit.c libft/ft_memalloc.c\
			libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strdup.c\
			libft/ft_strcpy.c libft/ft_strcpy.c libft/ft_strcat.c\
			libft/ft_strncat.c libft/ft_strlcat.c libft/ft_strchr.c\
			libft/ft_strrchr.c libft/ft_strnstr.c libft/ft_strcmp.c\
			libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c\
			libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c\
			libft/ft_toupper.c libft/ft_tolower.c libft/ft_memdel.c\
			libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c\
			libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c\
			libft/ft_putendl.c libft/ft_putnbr_fd.c libft/ft_lstmap.c\
			libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strequ.c\
			libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strtrim.c\
			libft/ft_strsplit.c libft/ft_itoa.c libft/ft_putchar.c\
			libft/ft_putstr.c libft/ft_putnbr.c libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_lstnew.c\
			libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c\
			libft/ft_lstiter.c libft/ft_printtlist.c libft/ft_printelem.c\
			libft/ft_strnlen.c libft/ft_strcharfind.c libft/ft_strsldup.c\
			libft/ft_sqrt.c libft/ft_lstpushback.c libft/ft_itoa_base.c\
			libft/ft_itoa_base_cap.c libft/ft_intlength.c\
			libft/ft_digit_count.c libft/ft_itoa_base_ll.c\
			libft/ft_itoa_llu.c libft/ft_strncpy.c
FLAG 	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make re -C $(LIBFT)
	@echo Succeeded making: $(LIBFT)
	@gcc $(FLAG) -c -I $(LIBFT) -I includes $(SRCS)
	@ar rc $(NAME) $(SRCS:.c=.o) $(LIBFUNC:.c=.o)
	@echo Succeeded making: $(NAME)
	@ranlib $(NAME)
	@rm -rf *.o

clean:
	@rm -rf *.o
	@make -C $(LIBFT) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all
	@make -C $(LIBFT) re
