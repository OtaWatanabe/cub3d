#include "../../includes/cub3d.h"

/*
	プレイヤーが移動しようとしている座標を計算
	x, y軸方向に移動できるかチェック
	移動できるならばプレイヤーの座標を更新
	移動できない場合はx軸のみ、y軸のみ移動できるかチェック
	これをWASDキーに対して行う
*/
void	move_w(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x + vars->player.dir_x * MOVE_SPEED;
	next_y = vars->player.pos_y + vars->player.dir_y * MOVE_SPEED;
	if (can_move(vars, next_x, next_y))
	{
		vars->player.pos_x = next_x;
		vars->player.pos_y = next_y;
	}
	else
	{
		if (can_move(vars, next_x, vars->player.pos_y))
			vars->player.pos_x = next_x;
		if (can_move(vars, vars->player.pos_x, next_y))
			vars->player.pos_y = next_y;
	}
}

void	move_s(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x - vars->player.dir_x * MOVE_SPEED;
	next_y = vars->player.pos_y - vars->player.dir_y * MOVE_SPEED;
	if (can_move(vars, next_x, next_y))
	{
		vars->player.pos_x = next_x;
		vars->player.pos_y = next_y;
	}
	else
	{
		if (can_move(vars, next_x, vars->player.pos_y))
			vars->player.pos_x = next_x;
		if (can_move(vars, vars->player.pos_x, next_y))
			vars->player.pos_y = next_y;
	}
}

void	move_a(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x - vars->player.plane_x * MOVE_SPEED;
	next_y = vars->player.pos_y - vars->player.plane_y * MOVE_SPEED;
	if (can_move(vars, next_x, next_y))
	{
		vars->player.pos_x = next_x;
		vars->player.pos_y = next_y;
	}
	else
	{
		if (can_move(vars, next_x, vars->player.pos_y))
			vars->player.pos_x = next_x;
		if (can_move(vars, vars->player.pos_x, next_y))
			vars->player.pos_y = next_y;
	}
}

void	move_d(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x + vars->player.plane_x * MOVE_SPEED;
	next_y = vars->player.pos_y + vars->player.plane_y * MOVE_SPEED;
	if (can_move(vars, next_x, next_y))
	{
		vars->player.pos_x = next_x;
		vars->player.pos_y = next_y;
	}
	else
	{
		if (can_move(vars, next_x, vars->player.pos_y))
			vars->player.pos_x = next_x;
		if (can_move(vars, vars->player.pos_x, next_y))
			vars->player.pos_y = next_y;
	}
}

// debug_player_move(vars);でプレイヤーの位置、向きを表示ができる
void	move_player(t_vars *vars)
{
	if (vars->keys.w)
		move_w(vars);
	if (vars->keys.s)
		move_s(vars);
	if (vars->keys.a)
		move_a(vars);
	if (vars->keys.d)
		move_d(vars);
	if (vars->keys.left)
		rotate_left(vars);
	if (vars->keys.right)
		rotate_right(vars);
}
