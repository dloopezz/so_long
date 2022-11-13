#include "mlx/mlx.h"
#include <stdio.h> 

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	key_hook(int keycode)
{
    printf("Keycode: %i\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 900, 600, "so_long");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}