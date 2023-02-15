#include "so_long.h"

int copy_1(t_game *game)
{
	int i;
    int j;
	int k;

	i = 0;
	k = 0;
    game->map.mtx_cpy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.mtx_cpy)
		return (0);
	while (i < game->map.height)
	{
		game->map.mtx_cpy[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.mtx_cpy[i])
			return (0);
		j = 0;
		while(j < game->map.width)
		{
			game->map.mtx_cpy[i][j++] = game->map.line[k++];
		}
		// printf("%s", game->map.mtx[i]);
		i++;
	}
	return (1);
}

int copy_2(t_game *game)
{
	int i;
    int j;
	int k;

	i = 0;
	k = 0;
    game->map.mtx_cpy2 = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.mtx_cpy2)
		return (0);
	while (i < game->map.height)
	{
		game->map.mtx_cpy2[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.mtx_cpy2[i])
			return (0);
		j = 0;
		while(j < game->map.width)
		{
			game->map.mtx_cpy2[i][j++] = game->map.line[k++];
		}
		// printf("%s", game->map.mtx[i]);
		i++;
	}
	return (1);
}

int map_to_2d(t_game *game)
{
    int i;
    int j;
	int k;

	i = 0;
	k = 0;
    game->map.mtx = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.mtx)
		return (0);
	while (i < game->map.height)
	{
		game->map.mtx[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.mtx[i])
			return (0);
		j = 0;
		while(j < game->map.width)
		{
			game->map.mtx[i][j++] = game->map.line[k++];
		}
		// printf("%s", game->map.mtx[i]);
		i++;
	}
	copy_1(game);
	copy_2(game);
	return (1);
}
