/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:42 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/24 12:50:05 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	total_potion(t_game *game)
{
	int	i;

	game->map.all_potion = 0;
	i = 0;
	while (game->map.line[i])
	{
		if (game->map.line[i] == 'C')
			game->map.all_potion++;
		i++;
	}
}

static void	copy_map(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	game->map.cpy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.cpy)
		return ;
	while (i < game->map.height)
	{
		game->map.cpy[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.cpy[i])
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.cpy[i][j++] = game->map.line[k++];
		i++;
	}
}

static void	map_to_2d(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	game->map.mtx = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.mtx)
		return ;
	while (i < game->map.height)
	{
		game->map.mtx[i] = ft_calloc(game->map.width + 1, sizeof(char));
		if (!game->map.mtx[i])
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.mtx[i][j++] = game->map.line[k++];
		i++;
	}
}

static void	check_ext(char *file, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(file) - ft_strlen(ext);
	j = 0;
	while (file[i + j] && ext[j])
	{
		if (file[i + j] == ext[j])
			j++;
		else
			error_found("Map file extension is not '.ber'");
	}
}

void	read_map(t_game *game, char *file)
{
	int		fd;
	char	*line;

	check_ext(file, ".ber");
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		error_found("Failed to open file");
	line = get_next_line(fd);
	if (!line)
		error_found("Unable to read map");
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = (ft_strdup_no_nl(line));
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_no_nl(game->map.line, line);
		game->map.height++;
	}
	close(fd);
	map_to_2d(game);
	copy_map(game);
	total_potion(game);
	check_map(game);
}
