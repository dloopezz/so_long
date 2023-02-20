/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:46:50 by dlopez-s          #+#    #+#             */
/*   Updated: 2023/02/18 15:00:13 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define ARROW_UP		126
# define ARROW_DOWN		125
# define ARROW_LEFT		123
# define ARROW_RIGHT	124

# define DESTROY_NOTIFY	7
# define XPM_ROUTE		"./xpm/"


//STRUCTS USED IN THE GAME
typedef struct s_player
{
	int		steps;
	int		steps_flag;
	int		pos;
	void	*player_front;
	void	*player_front1;
	void	*player_back;
	void	*player_back1;
	void	*player_right;
	void	*player_right1;
	void	*player_left;
	void	*player_left1;
	void	*human_front;
	void	*human_front1;
	void	*human_back;
	void	*human_back1;
	void	*human_right;
	void	*human_right1;
	void	*human_left;
	void	*human_left1;
}				t_player;

typedef struct s_map
{
	char	*line;
	char	**mtx;
	char	**cpy;
	int		height;
	int		width;
	void	*cell;
	void	*box;
	void	*metalbox;
	void	*potion;
	void	*portal;
	void	*spike;
	void	*footprints;
	int		all_potion;
	int		n_potion;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			frames;
	int			img_height;
	int			img_width;
	t_player	player;
	t_map		map;
}				t_game;

void	*init_xpm(t_game *game, char *str);
void	all_xpm(t_game *game);
void	put_img(t_game *game, void *img_ptr, int j, int i);
void	read_map(t_game *game, char *file);
void	check_map(t_game *game);
int		valid_path(t_game *game);
int		key_hooks(int keycode, t_game *game);
int		red_cross(t_game *game);
void	write_map(t_game *game, char c);
void	put_player(t_game *game, int i, int j, char c);
void	print_steps(t_game *game);
void	win_game(t_game *game);
void	lose_game(t_game *game);
void	error_found(char *str);

//===SETTINGS 	COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif