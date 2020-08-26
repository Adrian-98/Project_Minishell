# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amunoz-p <amunoz-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 17:54:32 by amunoz-p          #+#    #+#              #
#    Updated: 2020/08/26 17:54:55 by amunoz-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

all:			$(NAME)

$(NAME):		 $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				@$(MAKE) -C 
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re