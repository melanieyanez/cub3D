/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myanez-p <myanez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:18:31 by melanieyane       #+#    #+#             */
/*   Updated: 2024/03/04 16:21:48 by myanez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*----------------------------------------------*/
/*  Respond to key presses and releases 
	to control player movement and exit the game. */

void	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->wdw);
	exit(0);
}

/*----------------------------------------------*/

int	key_press_actions(int key, t_vars *vars)
{
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->wdw);
		exit(0);
	}
	else if (key == KEY_LEFT)
	{
		//la camera doit tourner vers la gauche
	}
	else if (key == KEY_RIGHT)
	{
		//la camera doit tourner vers la droite
	}
	else if (key == KEY_W)
	{
		//le joueur doit se deplacer en avant
	}
	else if (key == KEY_A)
	{
		//le joueur doit se deplacer a gauche
	}
	else if (key == KEY_S)
	{
		//le joueur doit se deplacer en arriere
	}
	else if (key == KEY_D)
	{
		//le joueur doit se deplacer a droite
	}
	return (0);
}
