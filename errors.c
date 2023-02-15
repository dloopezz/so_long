/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:36 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/15 20:30:59 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_elems(char *line)
{
	int i;
	int e;
	int c;
	int p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			e = 1;
		if (line[i] == 'C')
			c = 1;
		if (line[i] == 'P')
			p = 1;
		i++;
	}
	if (e != 1 || c != 1 || p != 1 )
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"Map must contain at least\n"RESET, 1);
		ft_putstr_fd(RED"-Exit\n-Starting point\n-Collectible\n"RESET, 1);
		exit(EXIT_ERROR);
	}
}

static void check_unrecognized(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (line[i] != 'E' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != '0' && line[i] != '1' && line[i] != 'S')
		{
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"Unrecognized elements found in map\n"RESET, 1);
			exit(EXIT_ERROR);
		}
		i++;
	}
}

static void check_format(char *line, t_game *game)
{
	if (game->map.width * game->map.height != ft_strlen(line))
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"Map is not rectangular\n"RESET, 1);
		exit(EXIT_ERROR);
	}
}

static void check_walls(char *line, t_game *game)
{
	int i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (i < game->map.width && line[i] != '1')
		{
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"Map is not surrounded by walls\n"RESET, 1);
			exit(EXIT_ERROR);
		}
		//no termino de entender la segunda condición
		else if ((i % game->map.width == 0 || i % game->map.width == game->map.width - 1) && line[i] != '1')
		{
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"Map is not surrounded by walls\n"RESET, 1);
			exit(EXIT_ERROR);
		}
		else if (i > (ft_strlen(line) - game->map.width) && line[i] != '1')
		{
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"Map is not surrounded by walls\n"RESET, 1);
			exit(EXIT_ERROR);
		}
		i++;
	}
}

void check_map(t_game *game)
{
	check_elems(game->map.line);
	check_unrecognized(game->map.line);
	check_format(game->map.line, game);
	check_walls(game->map.line, game);
	valid_path(game);
	valid_collect(game);
}
