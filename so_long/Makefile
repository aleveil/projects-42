# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveil <aleveil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 16:11:55 by aleveil           #+#    #+#              #
#    Updated: 2023/01/10 17:16:10 by aleveil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			so_long
NAME_BONUS		=			so_long_bonus

LIBFILE			=			libft/libft.a

HEADER			=			includes/so_long.h \
							libft/libft.h

CFLAGS			= 			-Iincludes -Wall -Werror -Wextra
CC				= 			gcc
LIBFT_FLAGS		= 			-Llibft -lft

DEBUG_FLAGS		=			#-fsanitize=address -g

SRCS 			=			srcs/main.c \
							srcs/get_next_line.c \
							srcs/parsing.c \
							srcs/parsing_utils.c \
							srcs/map_checker.c \
							srcs/map_checker_utils.c \
							srcs/pathfinding.c \
							srcs/pathfinding_utils.c \
							srcs/xpm.c \
							srcs/rendering.c \
							srcs/controls.c \
							srcs/utils.c

SRCS_BONUS 			=		srcs_bonus/main.c \
							srcs_bonus/get_next_line.c \
							srcs_bonus/parsing.c \
							srcs_bonus/parsing_utils.c \
							srcs_bonus/map_checker.c \
							srcs_bonus/map_checker_utils.c \
							srcs_bonus/pathfinding.c \
							srcs_bonus/pathfinding_utils.c \
							srcs_bonus/xpm.c \
							srcs_bonus/rendering.c \
							srcs_bonus/controls.c \
							srcs_bonus/utils.c

OBJS			=			$(patsubst %.c, %.o, $(SRCS))

OBJS_BONUS		=			$(patsubst %.c, %.o, $(SRCS_BONUS))

all : lib $(NAME)

$(NAME) : $(OBJS) $(HEADER) Makefile
		$(CC) $(OBJS) $(CFLAGS) $(DEBUG_FLAGS) $(LIBFT_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : lib $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(HEADER) Makefile
		$(CC) $(OBJS_BONUS) $(CFLAGS) $(DEBUG_FLAGS) $(LIBFT_FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
lib :
		make -C ./libft
		make -C ./mlx

%.o : %.c $(HEADER)
		$(CC) $(CFLAGS) $(DEBUG_FLAGS) -Imlx -c $< -o $@

clean :
		rm -f $(OBJS) $(OBJS_BONUS)
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx

fclean : clean
		rm -f $(NAME) $(NAME_BONUS)
		$(MAKE) fclean -C ./libft

re : fclean all

.PHONY : all lib clean fclean re