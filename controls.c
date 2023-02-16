/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:23 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/16 16:12:14 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	w_press(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i - game->map.width] == 'C')
		game->map.n_potion++;
	if (game->map.line[i - game->map.width] == 'E'
		&& game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i - game->map.width] == 'S')
		lose_game(game);
	if (game->map.line[i - game->map.width] != '1'
		&& game->map.line[i - game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map(game, 'w');
	}
}

static void	s_press(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i + game->map.width] == 'C')
		game->map.n_potion++;
	if (game->map.line[i + game->map.width] == 'E'
		&& game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i + game->map.width] == 'S')
		lose_game(game);
	if (game->map.line[i + game->map.width] != '1'
		&& game->map.line[i + game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map(game, 's');
	}
}

static void	a_press(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i - 1] == 'C')
		game->map.n_potion++;
	if (game->map.line[i - 1] == 'E'
		&& game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i - 1] == 'S')
		lose_game(game);
	if (game->map.line[i - 1] != '1' && game->map.line[i - 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map(game, 'a');
	}
}

static void	d_press(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i + 1] == 'C')
		game->map.n_potion++;
	if (game->map.line[i + 1] == 'E'
		&& game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i + 1] == 'S')
		lose_game(game);
	if (game->map.line[i + 1] != '1' && game->map.line[i + 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map(game, 'd');
	}
}

int	key_hooks(int keycode, t_game *game)
{
	game->frames = -1;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == KEY_W || keycode == ARROW_UP)
		w_press(game);
	if (keycode == KEY_A || keycode == ARROW_LEFT)
		a_press(game);
	if (keycode == KEY_S || keycode == ARROW_DOWN)
		s_press(game);
	if (keycode == KEY_D || keycode == ARROW_RIGHT)
		d_press(game);
	if (game->player.pos >= 2)
		game->player.pos = 0;
	game->player.pos++;
	mlx_put_image_to_window(game->mlx, game->win, game->map.footprints, 10, 10);
	return (0);
}
