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

NAME	=	lem-in

SRCS	=	./srcs/main.c									\
					./srcs/read.c								\
						./srcs/extract_name.c			\
						./srcs/extract_connexion.c	\
					./srcs/parsing.c							\
					./srcs/created_graph.c				\
					./srcs/position_salle.c			\
					./srcs/number_way.c					\
					./srcs/shortest_way.c				\
					./srcs/all_the_way.c					\
					./srcs/send_ant_in_way.c			\
					./srcs/display_way.c					\
				./get_next_line/get_next_line.c

OBJS	=	$(SRCS:.c=.o)

CC	=	@gcc -Wall -Werror -Wextra

CFLAGS	=	-I ./libft/includes -I ./get_next_line -I ./includes

LIB_PATH	=	./libft/libft.a

RM	=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJS)
	@make -C libft/
	@$(CC) $(OBJS) $(LIB_PATH) -o $(NAME)
	@echo "\033[32mLEM_IN COMPILATING DONE\033[0m"

clean	:
	@make clean -C libft/
	@$(RM) $(OBJS)

fclean	:
	@make fclean -C libft/
	@$(RM) $(OBJS)
	@$(RM) $(NAME)
	@echo "\033[31mLEM_IN CLEANING DONE\033[0m"

re	:	fclean all

.PHONY	:	all clean fclean re
