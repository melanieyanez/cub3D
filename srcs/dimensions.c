/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:17:43 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/15 11:28:00 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//gerer qqpart erreur fd

int	get_file_dimensions(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(vars->map.path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (i);
}

//enlever les whitespaces AVANT de chercher le start

void	get_map_start(t_vars *vars)
{
	int	i;
	int	end_map;

	i = get_file_dimensions(vars);
	while (vars->file_array[i] == NULL)
		i--;
	end_map = i;
	while (i > 0 && vars->file_array[i] != NULL
		&& ft_strncmp(vars->file_array[i], "NO ", 3)
		&& ft_strncmp(vars->file_array[i], "SO ", 3)
		&& ft_strncmp(vars->file_array[i], "EA ", 3)
		&& ft_strncmp(vars->file_array[i], "WE ", 3)
		&& ft_strncmp(vars->file_array[i], "F ", 3)
		&& ft_strncmp(vars->file_array[i], "C ", 3))
		i --;
	if (i == 0 || (end_map - i) < 3)
		map_error("Map size is not valid.\n");
	vars->map.start = i;
}

//bien appeler get_map_start avant
//verifier que mapx et mapy sont bien definis à -1

void	get_map_dimensions(t_vars *vars)
{
	int	i;

	i = vars->map.start;
	while (vars->file_array[i] != NULL)
	{
		if (vars->map.map_y < ft_strlen(vars->file_array[i])
			|| vars->map.map_y == -1)
			vars->map.map_y = ft_strlen(vars->file_array[i]);
		i ++;
	}
	vars->map.map_x = i - vars->map.start;
}
