/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:44 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/17 15:01:12 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		exit(EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, game->map.width * 110,
			game->map.height * 110, "Save Morty!");
	all_xpm(game);
	write_map(game, 's');
	put_img(game, game->map.footprints, 10, 10);
}

/* void	ft_leaks()
{
	system("leaks so_long");
} */

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		// atexit(ft_leaks);
		init_game(&game, argv[1]);
		mlx_hook(game.win, DESTROY_NOTIFY, 0, red_cross, &game);
		mlx_key_hook(game.win, key_hooks, &game);
		mlx_loop_hook(game.mlx, &loop_hook, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
