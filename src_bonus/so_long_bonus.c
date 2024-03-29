/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:44 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/27 15:45:57 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	red_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
}

static int	loop_hook(t_game *game)
{
	print_steps(game);
	return (0);
}

static void	init_game(t_game *game, char *file)
{
	game->player.pos = 2;
	game->player.steps = 0;
	game->map.n_potion = 0;
	read_map(game, file);
	game->mlx = mlx_init();
	if (!(game->mlx))
		error_found("Failed to load MLX");
	game->win = mlx_new_window(game->mlx, game->map.width * 110,
			game->map.height * 110, "Save Morty!");
	if (!(game->win))
		error_found("Failed to load window");
	all_xpm(game);
	write_map(game, 's');
	put_img(game, game->map.footprints, 10, 10);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		init_game(&game, argv[1]);
		mlx_hook(game.win, DESTROY_NOTIFY, 0, red_cross, &game);
		mlx_key_hook(game.win, key_hooks, &game);
		mlx_loop_hook(game.mlx, &loop_hook, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
