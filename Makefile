# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/21 15:34:49 by dlopez-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
LIB = ./src/so_long.h
LIB_BONUS = ./src_bonus/so_long_bonus.h
SRC_PATH = ./src/
SRC_PATH_BONUS = ./src_bonus/

SRC =	so_long.c \
		controls.c \
		init_xpm.c \
		count_steps.c \
		read_map.c \
		check_map.c \
		write_map.c \
		valid_path.c \
		put_player.c \
		messages.c

SRC_BONUS =	so_long_bonus.c \
			controls_bonus.c \
			init_xpm_bonus.c \
			count_steps_bonus.c \
			read_map_bonus.c \
			check_map_bonus.c \
			write_map_bonus.c \
			valid_path_bonus.c \
			put_player_bonus.c \
			messages_bonus.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_PATH_BONUS), $(SRC_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft make_mlx $(NAME)

bonus: make_libft make_mlx $(NAME_BONUS)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIB_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus