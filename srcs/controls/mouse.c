#include "../../includes/cub3d.h"

// int	mouse_enter(t_vars *vars)
// {
// 	vars->mouse_in_window = 1;
// 	vars->old_x = -1;
// 	return (0);
// }

// int	mouse_leave(t_vars *vars)
// {
// 	vars->mouse_in_window = 0;
// 	return (0);
// }

int	mouse_move(int x, int y, t_vars *vars)
{
	double	angle;
	double	old_dir_x;
	double	old_plane_x;

	(void)y;
	if (x == SCREEN_WIDTH / 2)
		return (0);
	angle = (x - SCREEN_WIDTH / 2) * MOUSE_SENSITIVITY;
	old_dir_x = vars->player.dir_x;
	vars->player.dir_x = vars->player.dir_x * cos(angle) - vars->player.dir_y
		* sin(angle);
	vars->player.dir_y = old_dir_x * sin(angle) + vars->player.dir_y
		* cos(angle);
	old_plane_x = vars->player.plane_x;
	vars->player.plane_x = vars->player.plane_x * cos(angle)
		- vars->player.plane_y * sin(angle);
	vars->player.plane_y = old_plane_x * sin(angle) + vars->player.plane_y
		* cos(angle);
	mlx_mouse_hide(vars->mlx, vars->win);
	mlx_mouse_move(vars->mlx, vars->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}

/*
	(void)y; 縦方向の移動は使用しない
	視点移動の角度を計算
	方向ベクトルの更新
	カメラ平面ベクトルの更新
	mls_mouse_hide マウスカーソルを非表示
	mlx_mouse_move カーソルを中央に移動
*/