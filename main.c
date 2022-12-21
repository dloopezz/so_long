#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define PLAYER			80


typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
	int		player_pos_x;
	int		player_pos_y;
}				t_vars;

typedef struct i_param
{
	int		img_width;
	int		img_height;
	void	*map_img;
	void	*player_img;

}				i_param;

int		move_player(int keycode, t_vars *mlx)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}

	i_param img;

	img.map_img = mlx_xpm_file_to_image(mlx->mlx, "./xpm/mapa.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(mlx->mlx, mlx->win, img.map_img, 1, 1);

	img.player_img = mlx_xpm_file_to_image(mlx->mlx, "./xpm/player.xpm", &img.img_width, &img.img_height);
	//mlx_put_image_to_window(mlx->mlx, mlx->win, img.player_img, 450, 337);
	if (keycode == KEY_W)
	{
		// mlx_put_image_to_window(mlx->mlx, mlx->win, img.map_img, mlx->player_pos_x, mlx->player_pos_y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.player_img, mlx->player_pos_x, mlx->player_pos_y - PLAYER);
		mlx->player_pos_y -= PLAYER;
	}
	if (keycode == KEY_A)
	{
		// mlx_put_image_to_window(mlx->mlx, mlx->win, img.map_img, mlx->player_pos_x, mlx->player_pos_y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.player_img, mlx->player_pos_x  - PLAYER, mlx->player_pos_y);
		mlx->player_pos_x -= PLAYER;
	}
	if (keycode == KEY_S)
	{
		// mlx_put_image_to_window(mlx->mlx, mlx->win, img.map_img, mlx->player_pos_x, mlx->player_pos_y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.player_img, mlx->player_pos_x, mlx->player_pos_y + PLAYER);
		mlx->player_pos_y += PLAYER;
	}
	if (keycode == KEY_D)
	{
		// mlx_put_image_to_window(mlx->mlx, mlx->win, img.map_img, mlx->player_pos_x, mlx->player_pos_y);
		mlx_put_image_to_window(mlx->mlx, mlx->win, img.player_img, mlx->player_pos_x + PLAYER, mlx->player_pos_y);
		mlx->player_pos_x += PLAYER;
	}
	return (0);
}

int	main(void)
{
	t_vars	mlx;
	i_param img;
	mlx.player_pos_x  = 1;
	mlx.player_pos_y  = 1;

	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 800, 640, "so_long");

	img.map_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/mapa.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.map_img, 0, 0);

	/* img.player_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/player.xpm", &mlx.player_pos_x, &mlx.player_pos_y);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, 450, 337); */

	mlx_key_hook(mlx.win, move_player, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
