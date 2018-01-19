# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/19 14:05:06 by vferreir          #+#    #+#              #
#    Updated: 2018/01/19 14:05:07 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem_in

SRCS	=	main.c				\
				read.c				\
				display.c			\
				./get_next_line/get_next_line.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc -g3 -fsanitize=address

CFLAGS	=	-I ./libft/includes -I ./get_next_line

LIB_PATH	=	./libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME)
	@$(RM) $(OBJS)
	@echo "\033[32mCHECKER COMPILATING DONE\033[0m"

clean	:
	$(RM) $(OBJS)

fclean	:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mCHECKER CLEANING DONE\033[0m"

re	:	fclean all

.PHONY	:	all clean fclean re
