# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/15 20:36:42 by dlopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
MAIN = so_long.c
SRC = 	controls.c \
		init_xpm.c \
		count_steps.c \
		read_map.c \
		errors.c \
		write_map.c \
		valid_path.c \
		valid_collect.c \
		map_copies.c

OBJS = $(SRC:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(DEBUG) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MAIN) -o $(NAME)

#%.o: %.c $(HEADER) $(LIBFT) $(MLX)
#	@$(CC) $(CFLAGS) $< -c

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all 

.PHONY: all clean fclean re bonus