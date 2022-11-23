#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_param
{
	int x;
	int y;
}				t_param;

void	init_params(t_param *param)
{
	param->x = 0;
	param->y = 0;
}

int key_hook(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param -> y++;
	if (keycode == KEY_A)
		param -> x--;
	if (keycode == KEY_S)
		param -> y--;
	if (keycode == KEY_D)
		param -> x++;
	if (keycode == KEY_ESC)
		exit(0);
	printf("Posición de X: %d\nPosición de Y:%d\n-------------------\n", param -> x, param -> y);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	t_param	param;

	init_params(&param);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 900, 600, "so_long");
	mlx_key_hook(win, key_hook, &param);
	mlx_loop(mlx);
}