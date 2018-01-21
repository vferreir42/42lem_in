# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:20:58 by vferreir          #+#    #+#              #
#    Updated: 2017/12/13 15:59:04 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_INC = ./libft/includes/

CC	=	gcc

RM	=	/bin/rm -f

SRC	=	ft_printf.c	\
			conversion_specifier.c \
			conversion_char.c \
			conversion_str.c \
			conversion_number.c \
			conversion_pointer.c \
			flag_characters.c	\
			counting_field_and_precision.c	\
			length_modifier.c	\
			fonction.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -Wall -Werror -Wextra

LIB = libft/libft.a

NAME	=	libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)
	@echo "\033[33;32m=== Compilation\t\t\tDONE===\033[0m"

clean:
	make -C libft/ clean
	$(RM) $(OBJ)
	@echo "\033[33;31m=== Object\t\t\tDELETED===\033[0m"

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)
	@echo "\033[33;31m=== Binary\t\t\tDELETED===\033[0m"

re: fclean all

.PHONY: all clean fclean re lib
