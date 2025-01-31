#include "../../includes/cub3d.h"

void rotate_left(t_vars *vars)
{
    double oldDirX;
    double oldPlaneX;

    oldDirX = vars->player.dirX;
    vars->player.dirX = vars->player.dirX * cos(ROT_SPEED) - vars->player.dirY * sin(ROT_SPEED);
    vars->player.dirY = oldDirX * sin(ROT_SPEED) + vars->player.dirY * cos(ROT_SPEED);
    oldPlaneX = vars->player.planeX;
    vars->player.planeX = vars->player.planeX * cos(ROT_SPEED) - vars->player.planeY * sin(ROT_SPEED);
    vars->player.planeY = oldPlaneX * sin(ROT_SPEED) + vars->player.planeY * cos(ROT_SPEED);
}

void rotate_right(t_vars *vars)
{
    double oldDirX;
    double oldPlaneX;

    oldDirX = vars->player.dirX;
    vars->player.dirX = vars->player.dirX * cos(-ROT_SPEED) - vars->player.dirY * sin(-ROT_SPEED);
    vars->player.dirY = oldDirX * sin(-ROT_SPEED) + vars->player.dirY * cos(-ROT_SPEED);
    oldPlaneX = vars->player.planeX;
    vars->player.planeX = vars->player.planeX * cos(-ROT_SPEED) - vars->player.planeY * sin(-ROT_SPEED);
    vars->player.planeY = oldPlaneX * sin(-ROT_SPEED) + vars->player.planeY * cos(-ROT_SPEED);
}