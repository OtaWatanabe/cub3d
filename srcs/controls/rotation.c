/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:11:56 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:11:58 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_left(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->player.dir_x;
	vars->player.dir_x = vars->player.dir_x * cos(ROT_SPEED)
		- vars->player.dir_y * sin(ROT_SPEED);
	vars->player.dir_y = old_dir_x * sin(ROT_SPEED) + vars->player.dir_y
		* cos(ROT_SPEED);
	old_plane_x = vars->player.plane_x;
	vars->player.plane_x = vars->player.plane_x * cos(ROT_SPEED)
		- vars->player.plane_y * sin(ROT_SPEED);
	vars->player.plane_y = old_plane_x * sin(ROT_SPEED) + vars->player.plane_y
		* cos(ROT_SPEED);
}

void	rotate_right(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->player.dir_x;
	vars->player.dir_x = vars->player.dir_x * cos(-ROT_SPEED)
		- vars->player.dir_y * sin(-ROT_SPEED);
	vars->player.dir_y = old_dir_x * sin(-ROT_SPEED) + vars->player.dir_y
		* cos(-ROT_SPEED);
	old_plane_x = vars->player.plane_x;
	vars->player.plane_x = vars->player.plane_x * cos(-ROT_SPEED)
		- vars->player.plane_y * sin(-ROT_SPEED);
	vars->player.plane_y = old_plane_x * sin(-ROT_SPEED) + vars->player.plane_y
		* cos(-ROT_SPEED);
}
