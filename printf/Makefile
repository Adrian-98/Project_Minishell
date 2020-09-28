# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 17:26:05 by amunoz-p          #+#    #+#              #
#    Updated: 2020/09/24 19:49:32 by amunoz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	printf.a

SRCS		= ft_count_digitspoint_bonus.c    ft_itoa_unsigned_bonus.c        ft_print_hexa_bonus.c           ft_print_pointer_bonus.c        ft_read_special_bonus.c         ft_while_bonus.c \
ft_atoi_bonus.c                 ft_hexad_low_bonus.c            ft_or_case_bonus.c              ft_print_hexa_null_bonus.c      ft_print_pointer_null_bonus.c   ft_reset_struct_bonus.c   ft_cast_bonus.c \
ft_hexad_upper_bonus.c          ft_pointer_bonus.c              ft_print_n_bonus.c              ft_print_unsigned_bonus.c       ft_set_zero_bonus.c ft_strchr_bonus.c \
ft_count_digits_bonus.c         ft_isdigit_bonus.c              ft_print_array_bonus.c          ft_print_nb_bonus.c             ft_printf_bonus.c \
ft_count_digitshexa_bonus.c     ft_itoa_bonus.c                 ft_print_char_bonus.c           ft_print_null_case_char_bonus.c ft_putchar_bonus.c  ft_strlen_bonus.c \

GCC			=	@gcc -Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)


INCLUDES	=	./

all: $(NAME)

$(NAME):	$(SRCS) printf_bonus.h
		$(GCC) -I$(INCLUDES) -c $(SRCS)
		-@ar rc $(NAME) $(OBJS)
		-@ranlib $(NAME)
clean:
			-@$(RM) $(OBJS)
fclean:     clean
			-@$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean