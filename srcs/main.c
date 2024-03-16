/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:52:36 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 06:00:26 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//pour avoir un main plus clean créér une fonction qui initialise toute la mlx

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		map_error("Please enter only one map path.\n");
	initialization(&vars, argv[1]);
	//vars.mlx = mlx_init();
	//vars.wdw = mlx_new_window(vars.mlx, vars.map.map_x * SIZE, \
		//vars.map.map_y * SIZE + SIZE, "Forest Quest");
	//mlx_hook(vars.wdw, 2, 0, key_press_actions, &vars);
	//mlx_hook(vars.wdw, 3, 0, key_release_actions, &vars);
	//mlx_hook(vars.wdw, 17, 0, close_window, &vars);
	//img_loading(&vars);
	//mlx_loop_hook(vars.mlx, render, &vars);
	//mlx_loop(vars.mlx);
	//free_array(&vars);
	return (0);
}
