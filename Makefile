# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstorey <lstorey@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 11:28:46 by lstorey           #+#    #+#              #
#    Updated: 2024/05/17 10:51:09 by lstorey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long

SRC         = so_long.c\
			so_long_utils.c\
			so_long_utils_2.c\
			map_printer.c\
			map_checker.c\
			struct_printer.c\
			init_elements.c\
			free_n_exit.c\
			flood_fill.c\
			img_init.c\
			img_init_utils.c\
			key_hooks.c\
			player_movement.c
			
OBJ         = $(SRC:.c=.o)

LIBFT       = libft/libft.a
GLFW		= /Users/lstorey/.brew/Cellar/glfw/3.4/lib
MLX42_DIR   = ./MLX42
MLX42_LIBS  = $(MLX42_DIR)/build/libmlx42.a
CC          = cc
RM          = rm -f
CFLAGS      = -Wall -Wextra -Werror -Wunreachable-code #-g -fsanitize=address
OPT_FLAGS   = -Ofast
HEADER		= MLX42/include/MLX42/MLX42.h

all				: $(NAME)

$(MLX42_LIBS)	: 
					@cd MLX42 && cmake -B build && cmake --build build -j4
					@echo "made MLX42"

$(NAME)			: $(OBJ) $(MLX42_LIBS)
					make -C ./libft
					$(CC) $(CFLAGS) $(OPT_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX42_LIBS) -lglfw -L$(GLFW) -ldl -pthread -lm -I $(HEADER)


clean			:
					make clean -C libft
					$(RM) $(OBJ)

fclean			: clean
					make fclean -C libft
					$(RM) $(NAME)
					$(RM) -r $(MLX42_DIR)/build

re				: fclean all
					@echo "re-made"
.PHONY: all clean fclean re 