#include "mlx/mlx.h"

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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i = 0;
	int		j = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2560, 1440, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	while(i<400)
		i++;
	while(i<500)
	{
		my_mlx_pixel_put(&img, i, 0, 0x0000FF);
		i++;
	}
	while(j < 100)
	{
		my_mlx_pixel_put(&img, i, j, 0xffff00);
		i++;
		j++;
	}
	while(j < 200)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j++;
	}
	while(j < 300)
	{
		my_mlx_pixel_put(&img, i, j, 0x800080);
		j++;
		i--;
	}
	while(i > 400)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF);
		i--;
	}
	while(j > 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xffff00);
		i--;
		j--;
	}
	while(j > 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j--;
	}
	while(j > -1)
	{
		my_mlx_pixel_put(&img, i, j, 0x800080);
		j--;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
} */


/*
 	square:

	while(i<100)
	{
		my_mlx_pixel_put(&img, i, 0, 0x00FF0000);
		i++;
		j++;
	}
	i = 0;
	while(i<100)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF);
		i++;
	}
	i = 0;
	j = 0;
	while(j<100)
	{
		my_mlx_pixel_put(&img, 0, j, 0x0800080);
		i++;
		j++;
	}
	j = 0;
	while(j<100)
	{
		my_mlx_pixel_put(&img, i, j, 0xffff00);
		j++;
	} */


/* 	
	triangle

	while(i<100)
	{
		my_mlx_pixel_put(&img, i, 0, 0x00FF0000);
		i++;
	}
	while(j<100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i--;
		j++;
	}
	while(j!=-1)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j--;
	} */


	/* 
	octogone

	while(i<400)
		i++;
	while(i<500)
	{
		my_mlx_pixel_put(&img, i, 0, 0x0000FF);
		i++;
	}
	while(j < 100)
	{
		my_mlx_pixel_put(&img, i, j, 0xffff00);
		i++;
		j++;
	}
	while(j < 200)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j++;
	}
	while(j < 300)
	{
		my_mlx_pixel_put(&img, i, j, 0x800080);
		j++;
		i--;
	}
	while(i > 400)
	{
		my_mlx_pixel_put(&img, i, j, 0x0000FF);
		i--;
	}
	while(j > 200)
	{
		my_mlx_pixel_put(&img, i, j, 0xffff00);
		i--;
		j--;
	}
	while(j > 100)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j--;
	}
	while(j > -1)
	{
		my_mlx_pixel_put(&img, i, j, 0x800080);
		j--;
		i++;
	} */