/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/25 16:53:56 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

/*----------------------------------------------*/
/* Sets up initial values for various game variables and data structures. */

void	initialization(t_vars *vars, char *file)
{
	vars->map.path = ft_strdup(file);
	vars->north_texture.addr = NULL;
	vars->south_texture.addr = NULL;
	vars->west_texture.addr = NULL;
	vars->east_texture.addr = NULL;
	vars->floor_texture.addr = NULL;
	vars->floor_color[0] = -1;
	vars->floor_color[1] = -1;
	vars->floor_color[2] = -1;
	vars->ceiling_texture.addr = NULL;
	vars->ceiling_color[0] = -1;
	vars->ceiling_color[1] = -1;
	vars->ceiling_color[2] = -1;
	parsing_process(vars);
	//vars->player.pos_x = -1;
	//vars->player.pos_y = -1;
	//vars->player.start_pos_x = 0;
	//vars->player.start_pos_y = 0;
}
