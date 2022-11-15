#include "mlx/mlx.h"
#include <stdio.h> 

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

/* int key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == KEY_W)
		mlx_string_put(vars->mlx, vars->win, 12, 12, 16711680, "Hello world");
	return (0);
} */

int mouse_in(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 15, 15, 16711680, "Hello");
	return (0);
}

int mouse_out(t_vars *vars)
{
	mlx_string_put(vars->mlx, vars->win, 30, 30, 16711680, "Hello");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 600, "so_long");
	mlx_hook(vars.win, 9, 1L<<4, mouse_in, &vars);
	mlx_hook(vars.win, 10, 1L<<5, mouse_out, &vars);
	mlx_loop(vars.mlx);
}
