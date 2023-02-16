/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:47:04 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/16 17:23:09 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_elems(t_game *game, int i, int j, int k)
{
	put_img(game, game->map.cell, j * 110, i * 110);
	if (game->map.line[k] == '1')
		put_img(game, game->map.box, j * 110, i * 110);
	else if (game->map.line[k] == 'E')
	{
		if (game->map.n_potion == game->map.all_potion)
			put_img(game, game->map.portal, j * 110, i * 110);
		else
			put_img(game, game->map.box, j * 110, i * 110);
	}
	else if (game->map.line[k] == 'C')
		put_img(game, game->map.potion, j * 110, i * 110);
	else if (game->map.line[k] == 'S')
		put_img(game, game->map.spike, j * 110, i * 110);
	else
		put_img(game, game->map.cell, j * 110, i * 110);
}

void	write_map(t_game *game, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
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
