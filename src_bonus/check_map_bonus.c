/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:36 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/24 15:26:21 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_elems(char *line)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (line[i++])
	{
		if (line[i] == 'E')
			e++;
		if (line[i] == 'C')
			c = 1;
		if (line[i] == 'P')
			p++;
	}
	if (e != 1 || c != 1 || p != 1)
		error_found("Invalid elements\n");
}

static void	check_unrecognized(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'E' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != '0' && line[i] != '1' && line[i] != 'S')
			error_found("Found unrecognized elements\n");
		i++;
	}
}

static void	check_format(char *line, t_game *game)
{
	if (game->map.width * game->map.height != ft_strlen(line))
		error_found("Map is not rectangular\n");
}

static void	check_walls(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (i < game->map.width && line[i] != '1')
			error_found("Map is not surrounded by walls\n");
		else if ((i % game->map.width == 0 || i % game->map.width
				== game->map.width - 1) && line[i] != '1')
			error_found("Map is not surrounded by walls\n");
		else if (i > (ft_strlen(line) - game->map.width) && line[i] != '1')
			error_found("Map is not surrounded by walls\n");
		i++;
	}
}

void	check_map(t_game *game)
{
	check_elems(game->map.line);
	check_unrecognized(game->map.line);
	check_format(game->map.line, game);
	check_walls(game->map.line, game);
	valid_path(game);
}
