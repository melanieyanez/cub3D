/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melanieyanez <melanieyanez@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:53:14 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/16 06:21:41 by melanieyane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//fonction pour verifier qu'on a toutes les textures et chacune qu'une fois
//que les chemins fonctionnent, que le fichier existe
//que l'extension est correcte

void	extension_checker(t_vars *vars)
{
	const char	*extension;

	extension = ".cub";
	if (ft_strlen(vars->map.path) >= ft_strlen(extension)
		&& ft_strncmp(vars->map.path + ft_strlen(vars->map.path) \
		- ft_strlen(extension), extension, ft_strlen(extension)) != 0)
		map_error("Invalid file extension.\n");
}