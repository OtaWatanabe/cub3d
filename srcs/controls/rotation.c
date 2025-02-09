#include "../../includes/cub3d.h"

void	rotate_left(t_vars *vars)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = vars->player.dirX;
	vars->player.dirX = vars->player.dirX * cos(ROT_SPEED) - vars->player.dirY
		* sin(ROT_SPEED);
	vars->player.dirY = old_dir_x * sin(ROT_SPEED) + vars->player.dirY
		* cos(ROT_SPEED);
	old_plane_x = vars->player.planeX;
	vars->player.planeX = vars->player.planeX * cos(ROT_SPEED)
		- vars->player.planeY * sin(ROT_SPEED);
	vars->player.planeY = old_plane_x * sin(ROT_SPEED) + vars->player.planeY
		* cos(ROT_SPEED);
}

void	rotate_right(t_vars *vars)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = vars->player.dirX;
	vars->player.dirX = vars->player.dirX * cos(-ROT_SPEED) - vars->player.dirY
		* sin(-ROT_SPEED);
	vars->player.dirY = old_dir_x * sin(-ROT_SPEED) + vars->player.dirY
		* cos(-ROT_SPEED);
	old_plane_x = vars->player.planeX;
	vars->player.planeX = vars->player.planeX * cos(-ROT_SPEED)
		- vars->player.planeY * sin(-ROT_SPEED);
	vars->player.planeY = old_plane_x * sin(-ROT_SPEED) + vars->player.planeY
		* cos(-ROT_SPEED);
}