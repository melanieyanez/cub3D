/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/25 15:49:38 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//ajouter toutes les protections de malloc

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
		//printf("%s", vars->trimmed_file_array[i]);
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
/*
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
*/

void	map_parser(t_vars *vars)
{
	int	i;

	get_map_dimensions(vars);
	vars->map_array = (char **)malloc(sizeof(char *) * vars->map.size);
	i = vars->map.top_limit;
	while (i <= vars->map.bottom_limit)
	{
		vars->map_array[i - vars->map.top_limit] = ft_strdup(vars->file_array[i]);
		//printf("%s", vars->map_array[i - vars->map.top_limit]);
		i++;
	}
}

// fonction qui doit permettre de selectionner une texture ou interpreter la couleur RGB
// on doit clean la ligne avant, comme pour copy path
// puis verifier si les deux premier char, sont ./ dans ce cas on envoie dans copy path
// sinon on stocke les valeurs des couleurs
// en verifiant bien que ce sont des valeurs valides, et qu'il y a bien 2 virgules

void	copy_color(t_vars *vars, char *color)
{
	if (ft_strncmp(color, "F ", 2) == 0 && vars->floor_texture.addr == NULL
		&& vars->floor_color[0] == -1 && vars->floor_color[1] == -1
		&& vars->floor_color[2] == -1)
	{
		if ()
		{

		}
		else
			copy_path(vars, color);
	}
	else if (ft_strncmp(color, "C ", 2) == 0
		&& vars->ceiling_texture.addr == NULL && vars->ceiling_color[0] == -1
		&& vars->ceiling_color[1] == -1 && vars->ceiling_color[2] == -1)
	{
		if ()
		{
			
		}
		else
			copy_path(vars, color);	
	}
}

//ajouter la partie pour clean le path des whitespaces
//clean_path à initialiser et allouer
//clean_path doit aussi eliminer les espaces dedans

void	copy_path(t_vars *vars, char *path)
{
	if (ft_strncmp(path, "NO", 2) == 0 && vars->north_texture.addr == NULL)
		vars->north_texture.addr = ft_strdup(path + 3);
	else if (ft_strncmp(path, "SO", 2) == 0 && vars->south_texture.addr == NULL)
		vars->south_texture.addr = ft_strdup(path + 3);
	else if (ft_strncmp(path, "WE", 2) == 0 && vars->west_texture.addr == NULL)
		vars->west_texture.addr = ft_strdup(path + 3);
	else if (ft_strncmp(path, "EA", 2) == 0 && vars->east_texture.addr == NULL)
		vars->east_texture.addr = ft_strdup(path + 3);
	else if (ft_strncmp(path, "F", 1) == 0 && vars->floor_texture.addr == NULL)
		vars->floor_texture.addr = ft_strdup(path + 2);
	else if (ft_strncmp(path, "C", 1) == 0
		&& vars->ceiling_texture.addr == NULL)
		vars->ceiling_texture.addr = ft_strdup(path + 2);
	else
		map_error("The texture path has been defined too many times.\n");
}

void	data_parser(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->trimmed_file_array[i])
	{
		if (ft_strncmp(vars->trimmed_file_array[i], "NO", 2) == 0
			|| ft_strncmp(vars->trimmed_file_array[i], "SO", 2) == 0
			|| ft_strncmp(vars->trimmed_file_array[i], "WE", 2) == 0
			|| ft_strncmp(vars->trimmed_file_array[i], "EA", 2) == 0)
			copy_path(vars, vars->trimmed_file_array[i]);
		else if (ft_strncmp(vars->file_array[i], "F", 1) == 0
			|| ft_strncmp(vars->file_array[i], "C", 1) == 0)
			copy_color(vars, vars->file_array[i]);
		i ++;
	}
}

void	parsing_process(t_vars *vars)
{
	int		fd;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Error opening map.\n");
	array_filler(vars);
	map_parser(vars);
	data_parser(vars);
}
