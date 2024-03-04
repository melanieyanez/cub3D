/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 00:19:58 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/04 16:25:31 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# define WHITESPACE " \t\n\v\f\r"

# define SIZE 50

# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_W   	13
# define KEY_A		0
# define KEY_S   	1
# define KEY_D     	2
# define KEY_ESCAPE 53
# define CLOSE		17

/*_____________ Structures _______________________*/

typedef struct s_map
{
	char	*path;
	int		map_x;
	int		map_y;
	int		res_x;
	int		res_y;
}t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_player
{
	int		start_pos_x;
	int		start_pos_y;
	int		pos_x;
	int		pos_y;
	int		dir_x;
	int		dir_y;
}t_player;

typedef struct s_utils
{
	int			start_found;
}t_utils;

typedef struct s_vars
{
	void		*mlx;
	void		*wdw;
	t_map		map;
	char		**file_array;
	char		**map_array;
	t_img		north_texture;
	t_img		south_texture;
	t_img		west_texture;
	t_img		east_texture;
	t_img		floor_texture;
	t_img		ceiling_texture;
	t_player	player;
	t_utils		utils;
}t_vars;

/*_____________ Functions _______________________*/

//checker.c

void	map_error(char *error_message);
void	map_checker(t_vars *vars);
void	extension_checker(t_vars *vars);
void	wall_checker(t_vars *vars);

//events.c

void	close_window(t_vars *vars);
//void	player_pos(t_vars *vars, int pot_x, int pot_y);
int		key_press_actions(int key, t_vars *vars);

//initialization.c

void	initialization(t_vars *vars, char *file_path);
void	img_loading(t_vars *vars);
void	img_addr(t_vars *vars);
void	get_player_pos(t_vars *vars);

//main.c

int		main(int argc, char **argv);
int		render(t_vars *vars);

//parsing.c

void	array_filler(t_vars *vars);
void	map_parser(t_vars *vars);
void	copy_color(t_vars *vars, char *color);
void	copy_path(t_vars *vars, char *path);
void	data_parser(t_vars *vars);
void	parsing_process(t_vars *vars);
void	map_counter(t_vars *vars, char *line);

#endif