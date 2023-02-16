/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:47:04 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/16 15:14:50 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void put_elems(t_game *game, int i, int j, int k)
{
	mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
	if (game->map.line[k] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
	else if (game->map.line[k] == 'E')
	{
		if (game->map.n_potion == game->map.all_potion)
			mlx_put_image_to_window(game->mlx, game->win, game->map.portal, j * 110, i * 110);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
	}
	else if (game->map.line[k] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->map.potion, j * 110, i * 110);
	else if (game->map.line[k] == 'S')
		mlx_put_image_to_window(game->mlx, game->win, game->map.spike, j * 110, i * 110);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
}

void    write_map(t_game *game, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			put_elems(game, i, j, k);
			if (game->map.line[k] == 'P')
				put_player(game, i, j, c);
			k++;
			j++;
		}
		i++;
	}
}
