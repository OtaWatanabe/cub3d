#include "../../includes/cub3d.h"

void	init_step_size_dist(t_vars *vars)
{
	if (vars->ray.ray_dir_x < 0)
	{
		vars->ray.step_x = -1;
		vars->ray.side_dist_x = (vars->player.pos_x - vars->ray.map_x)
			* vars->ray.delta_dist_x;
	}
	else
	{
		vars->ray.step_x = 1;
		vars->ray.side_dist_x = (vars->ray.map_x + 1.0 - vars->player.pos_x)
			* vars->ray.delta_dist_x;
	}
	if (vars->ray.ray_dir_y < 0)
	{
		vars->ray.step_y = -1;
		vars->ray.side_dist_y = (vars->player.pos_y - vars->ray.map_y)
			* vars->ray.delta_dist_y;
	}
	else
	{
		vars->ray.step_y = 1;
		vars->ray.side_dist_y = (vars->ray.map_y + 1.0 - vars->player.pos_y)
			* vars->ray.delta_dist_y;
	}
}

void	init_ray_vars(t_vars *vars, int x)
{
	//画面のx座標を-1から1に正規化
	vars->ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1.0;
	//レイの方向ベクトル
	vars->ray.ray_dir_x = vars->player.dir_x + vars->player.plane_x
		* vars->ray.camera_x;
	vars->ray.ray_dir_y = vars->player.dir_y + vars->player.plane_y
		* vars->ray.camera_x;
	//マップ座標
	vars->ray.map_x = (int)vars->player.pos_x;
	vars->ray.map_y = (int)vars->player.pos_y;
	//レイの移動距離
	if (vars->ray.ray_dir_x == 0)
		vars->ray.delta_dist_x = 1e30;
	else
		vars->ray.delta_dist_x = fabs(1 / vars->ray.ray_dir_x);
	if (vars->ray.ray_dir_y == 0)
		vars->ray.delta_dist_y = 1e30;
	else
		vars->ray.delta_dist_y = fabs(1 / vars->ray.ray_dir_y);
	// DDAの初期化
	init_step_size_dist(vars);
}

void	dda_loop(t_vars *vars)
{
	vars->ray.hit = 0;
	vars->ray.side = 0;
	while (vars->ray.hit == 0)
	{
		if (vars->ray.side_dist_x < vars->ray.side_dist_y)
		{
			vars->ray.side_dist_x += vars->ray.delta_dist_x;
			vars->ray.map_x += vars->ray.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.side_dist_y += vars->ray.delta_dist_y;
			vars->ray.map_y += vars->ray.step_y;
			vars->ray.side = 1;
		}
		if (vars->map[vars->ray.map_y][vars->ray.map_x] == '1')
			vars->ray.hit = 1;
	}
}
