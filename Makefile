# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:54:32 by amunoz-p          #+#    #+#              #
#    Updated: 2020/09/23 18:08:24 by amunoz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= main.c ft_path.c ft_cases.c ft_exit.c ft_echo.c ft_quote.c \
				ft_bash.c ft_cd.c ft_quote_extra.c ft_export.c\

GCC			=	@gcc -Wall -Wextra -Werror -g3

OBJS		=	$(SRCS:.c=.o)

LIBFT		= libft/libft.a

INCLUDES	=	./

all: $(NAME)

$(NAME):	$(OBJS)
		@$(MAKE) -C libft
		@$(GCC) -I$(INCLUDES) $(LIBFT) $(OBJS) -o $(NAME)
		
clean:  
			-@$(RM) $(OBJS)	
			@$(MAKE) -C libft clean

fclean:     clean
			-@$(RM) $(NAME) $(LIBFT)
re:			fclean all

.PHONY:		all clean fclean re bonus
