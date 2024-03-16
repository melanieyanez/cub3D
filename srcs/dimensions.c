/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:17:43 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 12:08:49 by melanieyane      ###   ########.fr       */
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

//segfault quand il y a des lignes en bas

void	get_map_start(t_vars *vars)
{
	int	i;
	int	end_map;

	i = get_file_dimensions(vars);
	printf("%d\n", i);
	while (vars->trimmed_file_array[i] == NULL || ft_strncmp(vars->file_array[i], "\n", 1))
		i--;
	printf("%d\n", i);
	end_map = i;
	while (i > 0 && vars->trimmed_file_array[i] != NULL
		&& ft_strncmp(vars->trimmed_file_array[i], "\n", 1)
		&& ft_strncmp(vars->trimmed_file_array[i], "NO ", 3)
		&& ft_strncmp(vars->trimmed_file_array[i], "SO ", 3)
		&& ft_strncmp(vars->trimmed_file_array[i], "EA ", 3)
		&& ft_strncmp(vars->trimmed_file_array[i], "WE ", 3)
		&& ft_strncmp(vars->trimmed_file_array[i], "F ", 3)
		&& ft_strncmp(vars->trimmed_file_array[i], "C ", 3))
		i --;
	printf("%d\n", i);
	printf("%d\n", end_map - i);
	if (i == 0 || (end_map - i) < 3)
		map_error("Map size is not valid.\n");
	vars->map.start = i + 1;
}

//verifier x et y

void	get_map_dimensions(t_vars *vars)
{
	int	i;

	get_map_start(vars);
	i = vars->map.start;
	while (vars->file_array[i] != NULL)
	{
		if (vars->map.map_y < (int)ft_strlen(vars->file_array[i])
			|| vars->map.map_y == -1)
			vars->map.map_y = ft_strlen(vars->file_array[i]);
		i ++;
	}
	vars->map.map_x = i - vars->map.start;
}
