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

	(void)y;                   // 縦方向の移動は使用しない
	if (x == SCREEN_WIDTH / 2) // カーソルが中央なら何もしない
		return (0);
	angle = (x - SCREEN_WIDTH / 2) * MOUSE_SENSITIVITY; // マウス感度から角度を計算
	// プレイヤーの方向ベクトルを更新
	old_dir_x = vars->player.dirX;
	vars->player.dirX = vars->player.dirX * cos(angle) - vars->player.dirY
		* sin(angle);
	vars->player.dirY = old_dir_x * sin(angle) + vars->player.dirY * cos(angle);
	// カメラ平面ベクトルを更新
	old_plane_x = vars->player.planeX;
	vars->player.planeX = vars->player.planeX * cos(angle) - vars->player.planeY
		* sin(angle);
	vars->player.planeY = old_plane_x * sin(angle) + vars->player.planeY
		* cos(angle);
	// マウスカーソルを非表示
	mlx_mouse_hide(vars->mlx, vars->win);
	// カーソルを中央に移動
	mlx_mouse_move(vars->mlx, vars->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}
