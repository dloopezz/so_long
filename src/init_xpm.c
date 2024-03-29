/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:39 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/21 14:33:59 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*init_xpm(t_game *game, char *str)
{
	char	*route;
	void	*img;

	route = ft_strjoin(XPM_ROUTE, str);
	img = mlx_xpm_file_to_image(game->mlx, route,
			&game->img_width, &game->img_height);
	if (!img)
		error_found("Failed to load XPM files");
	free(route);
	return (img);
}

static void	player_xpm(t_game *game)
{
	game->player.player_front = init_xpm(game, "morty_front.xpm");
	game->player.player_back = init_xpm(game, "morty_back.xpm");
	game->player.player_right = init_xpm(game, "morty_right.xpm");
	game->player.player_left = init_xpm(game, "morty_left.xpm");
	game->player.human_front = init_xpm(game, "human_front.xpm");
	game->player.human_back = init_xpm(game, "human_back.xpm");
	game->player.human_right = init_xpm(game, "human_right.xpm");
	game->player.human_left = init_xpm(game, "human_left.xpm");
}

static void	map_xpm(t_game *game)
{
	game->map.cell = init_xpm(game, "cell.xpm");
	game->map.footprints = init_xpm(game, "footprints.xpm");
	game->map.box = init_xpm(game, "box.xpm");
	game->map.potion = init_xpm(game, "potion.xpm");
	game->map.portal = init_xpm(game, "portal.xpm");
}

void	all_xpm(t_game *game)
{
	player_xpm(game);
	map_xpm(game);
}

void	put_img(t_game *game, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, j, i);
}
