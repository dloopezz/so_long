/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:23 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/14 18:57:53 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	win_game(t_game *game)
{
	ft_putstr_fd(GREEN"\n--------------\n¡¡Has Ganado!!\n--------------\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

static void	lose_game(t_game *game)
{
	ft_putstr_fd(RED"\n--------------\n¡¡Has Perdido!!\n--------------\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

//CLOSE GAME WITH THE RED CROSS
int	red_cross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit (0);
	return (0);
}

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
	if (game->map.line[i - game->map.width] == 'E' && game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i - game->map.width] == 'S')
		lose_game(game);
	if (game->map.line[i - game->map.width] != '1' && game->map.line[i - game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map_w(game);
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
	if (game->map.line[i + game->map.width] == 'E' && game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i + game->map.width] == 'S')
		lose_game(game);
	if (game->map.line[i + game->map.width] != '1' && game->map.line[i + game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map_s(game);
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
	if (game->map.line[i - 1] == 'E' && game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i - 1] == 'S')
		lose_game(game);
	if (game->map.line[i - 1] != '1' && game->map.line[i - 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map_a(game);
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
	if (game->map.line[i + 1] == 'E' && game->map.n_potion == game->map.all_potion)
		win_game(game);
	if (game->map.line[i + 1] == 'S')
		lose_game(game);
		//lose_game(game);
	if (game->map.line[i + 1] != '1' && game->map.line[i + 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + 1] = 'P';
		game->player.steps++;
		game->player.steps_flag = 1;
		write_map_d(game);
	}
}

int	key_hooks(int keycode, t_game *game)
{
	game->frames = -1;
	
	//CLOSE GAME USING ESC
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(EXIT_SUCCESS);
	}
	//MOVE PLAYER
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
	mlx_put_image_to_window(game->mlx, game->win, game->map.footprints, 10, 10); //PARA QUE LAS HUELLAS NO SE BORREN AL SOBREESCRIBIR EL MAPA
	return (0);
}
