# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vferreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 15:20:58 by vferreir          #+#    #+#              #
#    Updated: 2017/11/21 16:47:02 by vferreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

RM		=	rm -rf

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

SRC		= ft_atoi.c			\
		  ft_bzero.c		\
		  ft_isascii.c		\
		  ft_isalnum.c		\
		  ft_isalpha.c		\
		  ft_isdigit.c		\
		  ft_isprint.c		\
		  ft_memccpy.c		\
		  ft_memmove.c		\
		  ft_memset.c		\
		  ft_memcpy.c		\
		  ft_putchar.c		\
		  ft_putstr.c		\
		  ft_strcat.c		\
		  ft_strchr.c		\
		  ft_strcmp.c		\
		  ft_strcpy.c		\
		  ft_strdup.c		\
		  ft_strlen.c		\
		  ft_strncat.c		\
		  ft_strncmp.c		\
		  ft_strncpy.c		\
		  ft_strnstr.c		\
		  ft_strrchr.c		\
		  ft_strstr.c		\
		  ft_tolower.c		\
		  ft_toupper.c		\
		  ft_memchr.c		\
		  ft_memcmp.c		\
		  ft_strlcat.c		\
		  ft_memalloc.c		\
		  ft_memdel.c		\
		  ft_strnew.c		\
		  ft_strdel.c		\
		  ft_strclr.c		\
		  ft_striter.c		\
		  ft_itoa.c			\
		  ft_puissancedix.c	\
		  ft_putendl.c		\
		  ft_putnbr.c		\
		  ft_putchar_fd.c	\
		  ft_putstr_fd.c	\
		  ft_putnbr_fd.c	\
		  ft_putendl_fd.c	\
		  ft_striteri.c		\
		  ft_strmap.c		\
		  ft_strmapi.c		\
		  ft_strequ.c		\
		  ft_strnequ.c		\
		  ft_strsub.c		\
		  ft_strjoin.c		\
			ft_strjoindel.c	\
		  ft_strtrim.c		\
		  ft_strsplit.c		\
		  ft_lstdelone.c	\
		  ft_lstdel.c		\
		  ft_lstadd.c		\
		  ft_lstiter.c		\
		  ft_lstmap.c		\
		  ft_lstnew.c		\
			ft_strisminimalize.c \
			ft_putwstr.c	\
			ft_putwchar.c	\
			ft_strwlen.c	\
			ft_not_putwchar.c	\
			ft_itoabase.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME)	:
	@$(CC) $(CFLAGS) -c $(SRC) -I includes/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32mLIBFT COMPILATING DONE"


clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mLIBFT CLEANING DONE"

re: fclean all

.PHONY: all clean fclean re
