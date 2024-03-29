/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:00:48 by lopezz            #+#    #+#             */
/*   Updated: 2023/02/21 14:43:39 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_morty1(t_game *game, int i, int j, char c)
{
	if (c == 'w')
		put_img(game, game->player.human_back, j * 110, i * 110);
	else if (c == 'a')
		put_img(game, game->player.human_left, j * 110, i * 110);
	else if (c == 's')
		put_img(game, game->player.human_front, j * 110, i * 110);
	else if (c == 'd')
		put_img(game, game->player.human_right, j * 110, i * 110);
}

static void	put_skeleton1(t_game *game, int i, int j, char c)
{
	if (c == 'w')
		put_img(game, game->player.player_back, j * 110, i * 110);
	else if (c == 'a')
		put_img(game, game->player.player_left, j * 110, i * 110);
	else if (c == 's')
		put_img(game, game->player.player_front, j * 110, i * 110);
	else if (c == 'd')
		put_img(game, game->player.player_right, j * 110, i * 110);
}

void	put_player(t_game *game, int i, int j, char c)
{
	if (game->map.n_potion == game->map.all_potion)
		put_morty1(game, i, j, c);
	else
		put_skeleton1(game, i, j, c);
}
