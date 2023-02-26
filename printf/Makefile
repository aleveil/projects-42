# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 12:45:27 by aleveil           #+#    #+#              #
#    Updated: 2021/12/04 01:07:15 by aleveil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRC		= ft_printf.c \
		  ft_putbase.c \
		  ft_putbaselong.c \
		  ft_strlen.c \
		  ft_putstr.c \
		  ft_putchar.c \
		  ft_putnbr.c \
		  ft_putunbr.c \
		  ft_puthexadress.c

OBJ		= $(SRC:.c=.o)

HEADER		= libftprintf.h

FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
