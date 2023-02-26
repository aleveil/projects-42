# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveil <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 18:34:31 by aleveil           #+#    #+#              #
#    Updated: 2023/01/27 16:38:21 by aleveil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			philo

HEADER			=			includes/philo.h

CFLAGS			= 			-Iincludes -Wall -Werror -Wextra

CC				= 			gcc

DEBUG_FLAGS		=			#-fsanitize=thread -g

SRCS 			=			srcs/main.c \
							srcs/init.c \
							srcs/routine.c \
							srcs/print.c \
							srcs/print_utils.c \
							srcs/utils.c \
							srcs/setget_mutex.c

OBJS			=			$(patsubst %.c, %.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER) Makefile
		$(CC) $(OBJS) $(CFLAGS) $(DEBUG_FLAGS) -o $(NAME)

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re