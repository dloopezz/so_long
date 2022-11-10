#include "mlx/mlx.h"
#include <stdio.h> 

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

/* int	print(t_vars *vars)
{
    mlx_string_put(vars->mlx, vars->win, 1, 1, 16711680, "Hello world");
	return (0);
} */

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 600, "so_long");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
