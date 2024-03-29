/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:42 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/28 17:23:43 by dlopez-s         ###   ########.fr       */
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
	int	len;

	i = 0;
	k = 0;
	game->map.cpy = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!game->map.cpy)
		return ;
	while (i < game->map.height)
	{
		len = ft_strlen(game->map.cpy[i]) + 1;
		game->map.cpy[i] = ft_calloc(len, sizeof(char));
		if (!game->map.cpy[i])
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.cpy[i][j++] = game->map.line[k++];
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

static void	check_rect(t_game *game)
{
	if (ft_strlen(game->map.line) % game->map.width != 0)
		error_found("Map is not rectangular");
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
		error_found("Empty map");
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = (ft_strdup_no_nl(line));
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_no_nl(game->map.line, line);
		check_rect(game);
		game->map.height++;
	}
	close(fd);
	copy_map(game);
	total_potion(game);
	check_map(game);
}
