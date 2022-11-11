NAME = so_long

HEADER = so_long.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
MAIN = main.c
SRC = 

OBJS = $(SRC:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(MAIN) $(OBJS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MAIN) -o $(NAME)

%.o: %.c $(HEADER) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $< -c

bonus: all

clean:
	rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all 

.PHONY: all clean fclean re bonus