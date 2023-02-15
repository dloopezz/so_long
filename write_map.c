/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:47:04 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/13 21:28:36 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    write_map_w(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.line[k] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			else if (game->map.line[k] == 'P')
			{
				if (game->map.n_potion == game->map.all_potion)
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_back1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_back, j * 110, i * 110);	
				}
				else
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_back1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_back, j * 110, i * 110);
				}
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				if (game->map.n_potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.portal, j * 110, i * 110);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'S')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.spike, j * 110, i * 110);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
			k++;
			j++;
		}
		i++;
	}
}

void    write_map_a(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.line[k] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			else if (game->map.line[k] == 'P')
			{
				if (game->map.n_potion == game->map.all_potion)
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_left1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_left, j * 110, i * 110);	
				}
				else
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_left1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_left, j * 110, i * 110);
				}
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				if (game->map.n_potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.portal, j * 110, i * 110);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'S')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.spike, j * 110, i * 110);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
			k++;
			j++;
		}
		i++;
	}
}

void    write_map_s(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.line[k] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			else if (game->map.line[k] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				if (game->map.n_potion == game->map.all_potion)
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_front1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_front, j * 110, i * 110);	
				}
				else
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_front1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_front, j * 110, i * 110);
				}
			}
			else if (game->map.line[k] == 'E')
			{ 
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				if (game->map.n_potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.portal, j * 110, i * 110);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'S')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.spike, j * 110, i * 110);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
			k++;
			j++;
		}
		i++;
	}
}

void    write_map_d(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(i < game->map.height)
	{
		j = 0;
		while(j < game->map.width)
		{
			if (game->map.line[k] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			else if (game->map.line[k] == 'P')
			{
				if (game->map.n_potion == game->map.all_potion)
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_right1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.human_right, j * 110, i * 110);	
				}
				else
				{
					if (game->player.pos == 1)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_right1, j * 110, i * 110);
					if (game->player.pos == 2)
						mlx_put_image_to_window(game->mlx, game->win, game->player.player_right, j * 110, i * 110);
				}
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				if (game->map.n_potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.portal, j * 110, i * 110);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.box, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion, j * 110, i * 110);
			}
			else if (game->map.line[k] == 'S')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
				mlx_put_image_to_window(game->mlx, game->win, game->map.spike, j * 110, i * 110);
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 110, i * 110);
			k++;
			j++;
		}
		i++;
	}
}
