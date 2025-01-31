#include "../../includes/cub3d.h"

void init_step_size_dist(t_vars *vars)
{
    if (vars->ray.rayDirX < 0)
    {
        vars->ray.stepX = -1;
        vars->ray.sideDistX = (vars->player.posX - vars->ray.mapX) * vars->ray.deltaDistX;
    }
    else
    {
        vars->ray.stepX = 1;
        vars->ray.sideDistX = (vars->ray.mapX + 1.0 - vars->player.posX) * vars->ray.deltaDistX;
    }
    if (vars->ray.rayDirY < 0)
    {
        vars->ray.stepY = -1;
        vars->ray.sideDistY = (vars->player.posY - vars->ray.mapY) * vars->ray.deltaDistY;
    }
    else
    {
        vars->ray.stepY = 1;
        vars->ray.sideDistY = (vars->ray.mapY + 1.0 - vars->player.posY) * vars->ray.deltaDistY;
    }
}

void init_ray_vars(t_vars *vars, int x)
{
    //画面のx座標を-1から1に正規化
    vars->ray.cameraX = 2 * x / (double)SCREEN_WIDTH - 1.0;
    //レイの方向ベクトル
    vars->ray.rayDirX = vars->player.dirX + vars->player.planeX * vars->ray.cameraX;
    vars->ray.rayDirY = vars->player.dirY + vars->player.planeY * vars->ray.cameraX;
    //マップ座標
    vars->ray.mapX = (int)vars->player.posX;
    vars->ray.mapY = (int)vars->player.posY;
    //レイの移動距離
    vars->ray.deltaDistX = (vars->ray.rayDirY == 0) ? 1e30 : fabs(1 / vars->ray.rayDirX);
    vars->ray.deltaDistY = (vars->ray.rayDirX == 0) ? 1e30 : fabs(1 / vars->ray.rayDirY);
    //DDAの初期化
    init_step_size_dist(vars);
}

void dda_loop(t_vars *vars)
{
    vars->ray.hit = 0;
    vars->ray.side = 0;
    while (vars->ray.hit == 0)
    {
        if (vars->ray.sideDistX < vars->ray.sideDistY)
        {
            vars->ray.sideDistX += vars->ray.deltaDistX;
            vars->ray.mapX += vars->ray.stepX;
            vars->ray.side = 0;
        }
        else
        {
            vars->ray.sideDistY += vars->ray.deltaDistY;
            vars->ray.mapY += vars->ray.stepY;
            vars->ray.side = 1;
        }
        if (vars->map[vars->ray.mapY][vars->ray.mapX] == '1')
            vars->ray.hit = 1;
    }
}
