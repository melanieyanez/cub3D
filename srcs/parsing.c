/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:52:45 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/15 10:30:09 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// attention le array n'a pas été alloué

// ajouter un file pour les dimensions du fichier et de la map et pour l'indice

/*----------------------------------------------*/
/* Parse the map file to determine its dimensions 
   and stores the map into an array. */

void	array_filler(t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(vars->map.path, O_RDONLY);
	vars->file_array = (char **) malloc(sizeof(char *) * (get_file_dimensions(vars) + 1));
	line = get_next_line(fd);
	while (line)
	{
		map_counter(vars, line);
		vars->file_array[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

// pour les chemins, on ignore les whitespace et on copie jusqu'a un autre backspace
// skip les whitespaces avant et apres
// attention aussi si il y a un whitespace, il peut il y avoir un \ avant qui l'annule
// pour les couleurs faire un checker pour la valeur du nombre
// pour les couleurs compter les virgules, il en faut 2

void	map_parser(t_vars *vars)
{
	(void)vars;
	return ;
}

// ajouter controle d'espace au milieu du chemin précédé par un \ dans data parser
// ajouter controle d'espace au milieu des couleurs et controle de , dans data parser

void	copy_color(t_vars *vars, char *color)
{
	(void)vars;
	(void)color;
	return ;
}

int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

//clean_path à initialiser et allouer
//creer ft_is_whitespace dans ma libft
void	copy_path(t_vars *vars, char *path)
{
	int		i;
	int		j;
	char	*clean_path;

	i = 0;
	j = 0;
	while (path[i])
	{
		if (path[i] == '\'' && ft_is_whitespace(path[i + 1]))
			i += 2;
		clean_path[j] = path[i];
		i ++;
		j ++;
	}
	clean_path[j] = '\0';
	if (ft_strncmp(vars->file_array[i], "NO", 2) == 0)
		vars->north_texture.addr = ft_strdup(clean_path);
	else if (ft_strncmp(vars->file_array[i], "SO", 2) == 0)
		vars->south_texture.addr = ft_strdup(clean_path);
	else if (ft_strncmp(vars->file_array[i], "WE", 2) == 0)
		vars->west_texture.addr = ft_strdup(clean_path);
	else if (ft_strncmp(vars->file_array[i], "EA", 2) == 0)
		vars->east_texture.addr = ft_strdup(clean_path);
}

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

//skiper les lignes vides

void	parsing_process(t_vars *vars)
{
	int		fd;

	fd = open(vars->map.path, O_RDONLY);
	if (fd < 0)
		map_error("Error opening map.\n");
	array_filler(vars);
	data_parser(vars); // pour recuperer les chemins des structures
	map_parser(vars); // pour recuperer les lignes de la map
}

// ajouter une fonction qui controle qu'on a bien chaque texture, et chaque texture est bien qu'une fois

/*----------------------------------------------*/
/* Count map elements and calculate line length. */

void	map_counter(t_vars *vars, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			map_error("Unknown character encountered.\n");
		else if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			vars->utils.start_found ++;
		i ++;
	}
}
