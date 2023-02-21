/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:49:13 by lopezz            #+#    #+#             */
/*   Updated: 2023/02/21 15:31:43 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_found(char *str)
{
	ft_putstr_fd(RED "ERROR:\n" RESET, 2);
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit (EXIT_FAILURE);
}

void	win_game(t_game *game)
{
	ft_putstr_fd(GREEN"\n-------------------", 1);
	ft_putstr_fd("\n¡¡You saved Morty!!\n", 1);
	ft_putstr_fd("-------------------\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}

void	lose_game(t_game *game)
{
	ft_putstr_fd(YELLOW"\n-----------------------", 1);
	ft_putstr_fd("\n¡¡You died, try again!!\n", 1);
	ft_putstr_fd("-----------------------\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(EXIT_SUCCESS);
}
