#include "mlx/mlx.h"
#include <unistd.h>

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	mlx;
	int		img_width;
	int		img_height;
    void	*map_img;
	void	*player_img;

	mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 900, 674, "so_long");
	map_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/mapa.xpm", &img_width, &img_height);
	player_img = mlx_xpm_file_to_image(mlx.mlx, "./xpm/player.xpm", &img_width, &img_height);
    mlx_put_image_to_window(mlx.mlx, mlx.win, map_img, 1, 1);
    mlx_put_image_to_window(mlx.mlx, mlx.win, player_img, 450, 337);
	mlx_loop(mlx.mlx);
	return (0);
}
