/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:00:40 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 07:11:03 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/cub3D.h>

/*----------------------------------------------*/
/* Sets up initial values for various game variables and data structures. */

void	initialization(t_vars *vars, char *file)
{
	vars->map.path = ft_strdup(file);
	vars->map.map_x = -1;
	vars->map.map_y = -1;
	parsing_process(vars);
	//vars->map.res_x = vars->map.map_x * SIZE;
	//vars->map.res_y = vars->map.map_y * SIZE;
	//vars->map_array = malloc(sizeof(char *) * vars->map.map_y);
	//if (!vars->map_array)
		return ;
	//vars->player.pos_x = -1;
	//vars->player.pos_y = -1;
	//vars->player.start_pos_x = 0;
	//vars->player.start_pos_y = 0;
}
