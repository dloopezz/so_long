/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:07:51 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/21 15:31:58 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_cur(t_game *game, int i, int j)
{
	if (game->map.cpy[i][j] == 'P' &&
	(game->map.cpy[i + 1][j] == 'C'
	|| game->map.cpy[i + 1][j] == '0'
	|| game->map.cpy[i - 1][j] == 'C'
	|| game->map.cpy[i - 1][j] == '0'
	|| game->map.cpy[i][j + 1] == 'C'
	|| game->map.cpy[i][j + 1] == '0'
	|| game->map.cpy[i][j - 1] == 'C'
	|| game->map.cpy[i][j - 1] == '0'))
		return (1);
	return (0);
}

static void	fill(t_game *game, int i, int j)
{
	if (game->map.cpy[i][j] == '0' || game->map.cpy[i][j] == 'C')
		game->map.cpy[i][j] = 'P';
}

static int	complete_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if ((game->map.cpy[i][j] == 'E' && game->map.cpy[i + 1][j] == 'P')
			|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i - 1][j] == 'P')
			|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i][j + 1] == 'P')
			|| (game->map.cpy[i][j] == 'E' && game->map.cpy[i][j - 1] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	error_found("Unable to find a valid path");
	return (0);
}

static int	check_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.cpy[i][j] == 'C')
				error_found("Unable to reach all collectibles");
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (check_cur(game, i, j))
			{
				fill(game, i + 1, j);
				fill(game, i - 1, j);
				fill(game, i, j + 1);
				fill(game, i, j - 1);
				i = 0;
			}
			j++;
		}
		i++;
	}
	if (check_collect(game) && complete_path(game))
		return (1);
	return (0);
}
