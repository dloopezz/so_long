/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:30 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/21 15:31:36 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	terminal_steps(t_game *game)
{
	ft_putstr_fd("Steps: ", 1);
	ft_putnbr_fd(game->player.steps, 1);
	ft_putchar_fd('\n', 1);
	game->player.steps_flag = 0;
}

static void	screen_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 33, 23, 0xFFFFFF, str);
	free (str);
}

void	print_steps(t_game *game)
{
	if (game->player.steps_flag)
		terminal_steps(game);
	screen_steps(game);
}
