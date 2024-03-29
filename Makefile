# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:54:32 by amunoz-p          #+#    #+#              #
#    Updated: 2020/10/12 17:57:33 by amunoz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= main.c ft_path.c ft_cases.c ft_exit.c ft_echo.c ft_quote.c \
				ft_bash.c ft_cd.c ft_quote_extra.c ft_export.c ft_unset.c\
				ft_signal_handler.c ft_redirection.c ft_env.c ft_exit2.c\
				ft_redii2.c ft_dollar.c ft_get_user_path.c\

GCC			=	@gcc -Wall -Wextra -Werror -g

OBJS		=	$(SRCS:.c=.o)

LIBFT		= libft/libft.a

PRINTF		= printf/printf.a

INCLUDES	=	./

all: $(NAME)

$(NAME):	$(OBJS)
		@$(MAKE) -C libft
		@$(MAKE) -C printf
		@$(GCC) -I$(INCLUDES) $(LIBFT) $(PRINTF) $(OBJS) -o $(NAME)
		
clean:  
			-@$(RM) $(OBJS)	
			@$(MAKE) -C libft clean
			@$(MAKE) -C printf clean

fclean:     clean
			-@$(RM) $(NAME) $(LIBFT) $(PRINTF)
re:			fclean all

.PHONY:		all clean fclean re bonus
