/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:42 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/15 23:31:15 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    read_map(t_game *game, char *file)
{
	int fd;
	char *line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
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
	//ft_putstr_fd(game->map.line, 1);
	map_to_2d(game);
	check_map(game);
}
