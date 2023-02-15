/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rute_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:04:16 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/15 18:54:26 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

/**
 * It checks if the col is around a box, and if so, it changes the box to a 'P' (col)
 * 
 * @param game the game struct
 * @param x the x coordinate of the col
 * @param y the y coordinate of the col
 */
void	aroundcollect(t_game *game, int x, int y)
{
	if (game->maps.mapcopy2[x][y] == 'E' || game->maps.mapcopy2[x][y] == '0')
		game->maps.mapcopy2[x][y] = 'P';
}

/**
 * It checks if the player can reach the collectible
 * 
 * @param game The game struct.
 * 
 * @return the value of the last expression evaluated.
 */
int	reach_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if ((game->maps.mapcopy2[x][y] == 'C' && game->maps.mapcopy2[x][y + 1] == 'P')
			|| (game->maps.mapcopy2[x][y] == 'C' && game->maps.mapcopy2[x][y - 1] == 'P')
			|| (game->maps.mapcopy2[x][y] == 'C' && game->maps.mapcopy2[x - 1][y] == 'P')
			|| (game->maps.mapcopy2[x][y] == 'C' && game->maps.mapcopy2[x + 1][y] == 'P'))
				return (1);
			y++;
		}
		x++;
	}
	return (error_message("No llega al coleccionable\n"), 0);
}

/**
 * It checks if the player is
 * surrounded by enemies
 * 
 * @param game the game structure
 * @param x the x coordinate of the player
 * @param y the y coordinate of the player
 * 
 * @return 1 if the conditions are met, otherwise it returns 0.
 */
int	checkcollect(t_game *game, int x, int y)
{
	if (game->maps.mapcopy2[x][y] == 'P' &&
	(game->maps.mapcopy2[x][y + 1] == '0'
	|| game->maps.mapcopy2[x - 1][y] == 'E'
	|| game->maps.mapcopy2[x - 1][y] == '0'
	|| game->maps.mapcopy2[x][y - 1] == 'E'
	|| game->maps.mapcopy2[x][y - 1] == '0'
	|| game->maps.mapcopy2[x + 1][y] == 'E'
	|| game->maps.mapcopy2[x + 1][y] == '0'))
		return (1);
	return (0);
}
/**
 * It allocates memory for a copy of the map, and then copies the map into the
 * allocated memory
 * 
 * @param game the game struct
 * 
 * @return a boolean value.
 */
int	copymap2(t_game *game)
{
	int	x;
	int	y;

	game->maps.mapcopy2 = (char**)ft_calloc(game->maps.rows, (sizeof(char *)));
	if (!game->maps.mapcopy2)
		return (0);
	x = 0;
	while (x < game->maps.rows)
	{
		game->maps.mapcopy2[x] = (char *)ft_calloc(game->maps.cols, sizeof(char));
		if (!game->maps.mapcopy2)
			return (0);
		y = 0;
		while (y < game->maps.cols)
		{
			game->maps.mapcopy2[x][y] = game->maps.coord[x][y];
			//printf("%c", game->maps.mapcopy2[x][y]);
			//ft_putstr_fd("\n", 1);
			//printf("%c", game->maps.coord[x][y]);
			y++;
		}
		x++;
	}
	//game->maps.mapcopy2[x] = 0;
	return (TRUE);
}

/**
 * It checks if the col can reach the exit
 * 
 * @param game the game struct
 * 
 * @return a boolean value.
 */
int	valid_path_collect(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->maps.rows)
	{
		y = 0;
		while (y < game->maps.cols)
		{
			if (checkcollect(game, x, y))
			{
				aroundcollect(game, x + 1, y);
				aroundcollect(game, x - 1, y);
				aroundcollect(game, x, y + 1);
				aroundcollect(game, x, y - 1);
				x = 0;
			}
			//printf("%c", game->maps.mapcopy2[x][y]);
			y++;
		}
		x++;
	}
	//printf("%s\n", game->maps.mapcopy2[x]);
	if (reach_collect(game))
		return (1);
	return (FALSE);
}