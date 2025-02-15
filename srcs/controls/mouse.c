#include "../../includes/cub3d.h"

int	mouse_enter(t_vars *vars)
{
	vars->mouse_in_window = 1;
	vars->old_x = -1;
	return (0);
}

int	mouse_leave(t_vars *vars)
{
	vars->mouse_in_window = 0;
	return (0);
}

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
	mlx_mouse_move(vars->mlx, vars->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	return (0);
}
// int	mouse_move(int x, int y, t_vars *vars)
// {
// 	double	angle;
// 	double	old_dir_x;
// 	double	old_plane_x;

// 	// 上下の回転をしないので y は使わない場合 (void) や引数削除などでOK
// 	(void)y;
// 	// 「すでに中央にいる」イベントなら無視 (再センタリングの直後など)
// 	if (x == SCREEN_WIDTH / 2)
// 		return (0);
// 	// 中央からの差分を回転角度に変換
// 	angle = (x - (SCREEN_WIDTH / 2)) * MOUSE_SENSITIVITY;
// 	// 回転計算
// 	old_dir_x = vars->player.dir_x;
// 	vars->player.dir_x = vars->player.dir_x * cos(angle) - vars->player.dir_y
// 		* sin(angle);
// 	vars->player.dir_y = old_dir_x * sin(angle) + vars->player.dir_y
// 		* cos(angle);
// 	old_plane_x = vars->player.plane_x;
// 	vars->player.plane_x = vars->player.plane_x * cos(angle)
// 		- vars->player.plane_y * sin(angle);
// 	vars->player.plane_y = old_plane_x * sin(angle) + vars->player.plane_y
// 		* cos(angle);
// 	// カーソルを隠して毎回中央に戻す
// 	mlx_mouse_hide(vars->mlx, vars->win);
// 	mlx_mouse_move(vars->mlx, vars->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
// 	return (0);
// }

// int	mouse_move(int x, int y, t_vars *vars)
// {
// 	int	delta_x;
// 	int	steps;

// 	(void)y; // 縦方向の移動は今は使わないのでキャストだけ
// 	// 初回呼び出し時は old_x が初期化されていないためセットして終了
// 	if (vars->old_x == -1)
// 	{
// 		vars->old_x = x;
// 		return (0);
// 	}
// 	delta_x = x - vars->old_x;
// 	vars->old_x = x; // 今回の座標を次回の比較用に保存
// 	// マウスが右へ動いた (delta_x > 0) → rotate_right を複数回呼ぶ
// 	if (delta_x > 0)
// 	{
// 		steps = delta_x;
// 		while (steps > 0)
// 		{
// 			rotate_right(vars);
// 			steps--;
// 		}
// 	}
// 	// マウスが左へ動いた (delta_x < 0) → rotate_left を複数回呼ぶ
// 	else if (delta_x < 0)
// 	{
// 		steps = -delta_x; // delta_x が負なので正数化
// 		while (steps > 0)
// 		{
// 			rotate_left(vars);
// 			steps--;
// 		}
// 	}
// 	mlx_mouse_hide(vars->mlx, vars->win);
// 	if (x < 100 || x > SCREEN_WIDTH - 100)
// 		mlx_mouse_move(vars->mlx, vars->win, SCREEN_WIDTH / 2, SCREEN_HEIGHT
// 			/ 2);
// 	return (0);
// }

/*
	(void)y; 縦方向の移動は使用しない
	視点移動の角度を計算
	方向ベクトルの更新
	カメラ平面ベクトルの更新
	mls_mouse_hide マウスカーソルを非表示
	mlx_mouse_move カーソルを中央に移動
*/

/*
	TODO
	varsにangleを持たせて、
	マウスのときはangle = (x - (SCREEN_WIDTH / 2)) * MOUSE_SENSITIVITY;
	キーボードのときはangle = ROT_SPEED として設定する
*/