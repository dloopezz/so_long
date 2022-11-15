#include <mlx.h>
#include <stdlib.h>

/* int	render_next_frame(void *YourStruct);

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_loop(mlx);
} */

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void color_screen(t_data img)
{
	int i = 0, j = 0;
	while (j < 600)
	{
		i = 0;
		while (i < 900)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			i++;
		}
		j++;
	}
	sleep(3);
	while (j < 600)
	{
		i = 0;
		while (i < 900)
		{
			my_mlx_pixel_put(&img, i, j, 0x000000FF);
			i++;
		}
		j++;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 600, "so_long");
	img.img = mlx_new_image(mlx, 900, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	color_screen(img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}