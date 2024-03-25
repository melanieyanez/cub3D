/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:17:43 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/25 13:54:39 by myanez-p         ###   ########.fr       */
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

void	get_map_dimensions(t_vars *vars)
{
	int	i;
	int	end_map;

	i = get_file_dimensions(vars);
	while (i > 0 && (vars->trimmed_file_array[i] == NULL
			|| vars->trimmed_file_array[i][0] == '\n'))
		i--;
	vars->map.bottom_limit = i;
	end_map = i;
	while (i > 0 && vars->trimmed_file_array[i] - 1 != NULL
		&& vars->trimmed_file_array[i - 1][0] != '\n'
		&& !(ft_strncmp(vars->trimmed_file_array[i - 1], "NO ", 3) == 0
			|| ft_strncmp(vars->trimmed_file_array[i - 1], "SO ", 3) == 0
			|| ft_strncmp(vars->trimmed_file_array[i - 1], "EA ", 3) == 0
			|| ft_strncmp(vars->trimmed_file_array[i - 1], "WE ", 3) == 0
			|| ft_strncmp(vars->trimmed_file_array[i - 1], "F ", 2) == 0
			|| ft_strncmp(vars->trimmed_file_array[i - 1], "C ", 2) == 0))
		i --;
	vars->map.top_limit = i;
	vars->map.size = vars->map.bottom_limit - vars->map.top_limit + 1;
	if (i == 0 || vars->map.size < 3)
		map_error("Map size is not valid.\n");
}
