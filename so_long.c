/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:44 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/15 20:26:35 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void total_potion(t_game *game)
{
	int i;

	game->map.all_potion = 0;
	i = 0;
	while(game->map.line[i])
	{
		if (game->map.line[i] == 'C')
			game->map.all_potion++;
		i++;
	}
	//ft_putnbr_fd(game->map.all_potion, 1);
}

static void init_window(t_game *game, char *file)
{   
	read_map(game, file);
	total_potion(game);
	game->mlx = mlx_init();
	if (!(game->mlx))
		exit(EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, game->map.width * 110, game->map.height * 110, "Save Morty!");
}

static void init_map(t_game *game)
{
	game->player.pos = 2; //aqui para que salga jugador al principio
	map_xpm(game);
	player_xpm(game); //esta en init map para que en primer write ponga a player
	write_map_s(game);
}

static void init_player(t_game *game)
{
	//PARA INICIALIZAR LAS VARIABLES
	game->player.steps = 0;
	game->map.n_potion = 0; //inicializamos para poder hacer ++
	//player.steps_flag = 1;

	// player_xpm(game); //antes estaba aqui por lo de init_pos
	mlx_put_image_to_window(game->mlx, game->win, game->map.footprints, 10, 10); //SALE IMAGEN DE LOS PASOS AL PRINCIPIO
}

static void    init_game(t_game *game, char *file)
{
	init_window(game, file);
	init_map(game);
	init_player(game);
}

static int loop_hook(t_game *game)
{
	print_steps(game);
	return (0);
}

/* void    ft_leaks()
{
	system("leaks so_long");
} */

int main(int argc, char **argv)
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
