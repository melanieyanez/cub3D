/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 11:13:53 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	array_filler(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(vars->map.path, O_RDONLY);
	vars->file_array = (char **) malloc(sizeof(char *) * (get_file_dimensions(vars) + 1));
	vars->trimmed_file_array = (char **) malloc(sizeof(char *) * (get_file_dimensions(vars) + 1));
	line = get_next_line(fd);
	while (line)
	{
		vars->file_array[i] = ft_strdup(line);
		vars->trimmed_file_array[i] = ft_strdup(ft_strtrim(line, WHITESPACE));
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

//on veut trim les whitespaces au debut et a la fin de chaque ligne
//si c'est un chemin, on veut aussi trim les whitespaces internes sauf si precedés d'un '\'
//pour les chemins, on ignore les whitespace et on copie jusqu'a un autre backslash ou fin de ligne
//pour les couleurs, faire un checker pour la valeur du nombre, compter les virgules (il en faut 2), et gerer les espaces

void	line_cleaner(char **line)
{
	int		i;
	int		j;
	char	*clean_path = NULL;

	i = 0;
	j = 0;
	while ((*line)[i])
	{
		if ((*line)[i] == '\'' && ft_iswhitespace((*line)[i + 1]))
			i += 2;
		clean_path[j] = (*line)[i];
		i ++;
		j ++;
	}
	(*line)[j] = '\0';
}

void	map_parser(t_vars *vars)
{
	int	i;

	get_map_dimensions(vars);
	vars->map_array = (char **)malloc(sizeof(char *) * vars->map.map_y);
	i = vars->map.start;
	while (vars->file_array[i])
	{
		vars->map_array[i - vars->map.start] = ft_strdup(vars->file_array[i]);
		printf("%s", vars->map_array[i - vars->map.start]);
		i++;
	}
}

// fonction qui doit permettre de selectionner une texture ou interpreter la couleur RGB

void	copy_color(t_vars *vars, char *color)
{
	(void)vars;
	(void)color;
	return ;
}

//clean_path à initialiser et allouer
//clean_path doit aussi eliminer les espaces dedans
void	copy_path(t_vars *vars)
{
	int		i;
	char	*clean_path;

	i = 0;
	while (vars->file_array[i])
	{
		if (ft_strncmp(vars->file_array[i], "NO", 2) == 0)
			vars->north_texture.addr = ft_strdup(clean_path);
		else if (ft_strncmp(vars->file_array[i], "SO", 2) == 0)
			vars->south_texture.addr = ft_strdup(clean_path);
		else if (ft_strncmp(vars->file_array[i], "WE", 2) == 0)
			vars->west_texture.addr = ft_strdup(clean_path);
		else if (ft_strncmp(vars->file_array[i], "EA", 2) == 0)
			vars->east_texture.addr = ft_strdup(clean_path);
		i ++;
	}
}
/*
void	data_parser(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->file_array[i])
	{
		vars->file_array[i] = ft_strtrim(vars->file_array[i], WHITESPACE);
		if (ft_strncmp(vars->file_array[i], "NO", 2) == 0
			|| ft_strncmp(vars->file_array[i], "SO", 2) == 0
			|| ft_strncmp(vars->file_array[i], "WE", 2) == 0
			|| ft_strncmp(vars->file_array[i], "EA", 2) == 0)
			copy_path(vars, vars->file_array[i]);
		else if (ft_strncmp(vars->file_array[i], "F", 1) == 0
			|| ft_strncmp(vars->file_array[i], "C", 1) == 0)
			copy_color(vars, vars->file_array[i]);
		i ++;
	}
}
*/

//on recupere la map d'abord comme ca elle n'est pas influencée par le trim

void	parsing_process(t_vars *vars)
{
	int		fd;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Error opening map.\n");
	array_filler(vars);
	map_parser(vars);
	//data_parser(vars); // pour recuperer les chemins des textures
}
