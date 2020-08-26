# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:54:32 by amunoz-p          #+#    #+#              #
#    Updated: 2020/08/26 19:39:34 by amunoz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

SRCS		= main.c

GCC			=	@gcc -Wall -Wextra -Werror

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