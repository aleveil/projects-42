# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 15:22:35 by aleveil           #+#    #+#              #
#    Updated: 2022/11/29 18:28:44 by aleveil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			pipex
LIB				=			libft/libft.a
HEADER			=			/includes/pipex.h \
							/libft/libft.h

CFLAGS			= 			-Wall -Werror -Wextra
CC				= 			gcc
LFT 			= 			-L libft -lft

SRCS 			=			src/pipex.c \
							src/utils.c


OBJS			=			$(patsubst %.c, %.o, $(SRCS))

all : lib $(NAME)

$(NAME): ${OBJS} ${INCLUDES} ${LIB} Makefile
		$(CC) $(LFT) $(OBJS) -I includes -o $(NAME)

lib:
		make -C ./libft

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft

fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re