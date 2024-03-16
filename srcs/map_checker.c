/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:53:01 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 05:59:04 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//map_counter un seul joueur, pas de char inconnu, map fermée

void	map_error(char *error_message)
{
	ft_printf("Error!\n");
	ft_printf("%s", error_message);
	exit(1);
}

void	map_checker(t_vars *vars)
{
	if (vars->utils.start_found > 1)
		map_error("Multiple starts found.\n");
	else if (vars->utils.start_found < 1)
		map_error("No start position found.\n");
}

void	wall_checker(t_vars *vars)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map.map_x)
	{
		if (vars->map_array[0][i] != '1' ||
			vars->map_array[vars->map.map_y - 1][i] != '1')
			map_error("Map not enclosed into walls.\n");
		i ++;
	}
	while (j < vars->map.map_y)
	{
		if (vars->map_array[j][0] != '1' ||
			vars->map_array[j][vars->map.map_x - 1] != '1')
			map_error("Map not enclosed into walls.\n");
		j ++;
	}
}
