#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_param
{
	int x;
	int y;
}				t_param;

typedef struct i_param
{
	int		img_width;
	int		img_height;
	void	*map_img;
	void	*player_img;
}				i_param;

void	init_params(t_param *param)
{
	param->x = 450;
	param->y = 337;
}

int		move_player(int keycode, t_vars mlx, t_param *param, i_param img)  //puta mierda
{
	if (keycode == KEY_W)
	{
		mlx_destroy_image(mlx.mlx, &img.player_img);
		param -> y++;
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, param -> x, param -> y);
	}
	if (keycode == KEY_A)
	{
		mlx_destroy_image(mlx.mlx, &img.player_img);
		param -> x--;
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, param -> x, param -> y);
	}
	if (keycode == KEY_S)
	{
		mlx_destroy_image(mlx.mlx, &img.player_img);
		param -> y--;
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, param -> x, param -> y);
	}
	if (keycode == KEY_D)
	{
		mlx_destroy_image(mlx.mlx, &img.player_img);
		param -> x++;
		mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, param -> x, param -> y);
	}
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(mlx.mlx, &img.player_img);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	mlx;
	t_param	param;
	i_param img;

	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 900, 674, "so_long");
	img.map_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/mapa.xpm", &img.img_width, &img.img_height);
    mlx_put_image_to_window(mlx.mlx, mlx.win, img.map_img, 1, 1);
	img.player_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/player.xpm", &img.img_width, &img.img_height);
	//init_params(&param);
	//mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, param.x, param.y);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.player_img, 450, 337);
	mlx_key_hook(mlx.win, move_player, &param);
	mlx_loop(mlx.mlx);
	return (0);
}
