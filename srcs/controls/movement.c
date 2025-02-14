#include "../../includes/cub3d.h"

void	move_w(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x + vars->player.dir_x * MOVE_SPEED;
	next_y = vars->player.pos_y + vars->player.dir_y * MOVE_SPEED;
	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
	{
		vars->player.pos_x = next_x;
	}
	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
	{
		vars->player.pos_y = next_y;
	}
}

void	move_s(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x - vars->player.dir_x * MOVE_SPEED;
	next_y = vars->player.pos_y - vars->player.dir_y * MOVE_SPEED;
	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
	{
		vars->player.pos_x = next_x;
	}
	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
	{
		vars->player.pos_y = next_y;
	}
}

void	move_a(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x - vars->player.plane_x * MOVE_SPEED;
	next_y = vars->player.pos_y - vars->player.plane_y * MOVE_SPEED;
	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
	{
		vars->player.pos_y = next_y;
	}
	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
	{
		vars->player.pos_x = next_x;
	}
}

void	move_d(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x + vars->player.plane_x * MOVE_SPEED;
	next_y = vars->player.pos_y + vars->player.plane_y * MOVE_SPEED;
	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
	{
		vars->player.pos_y = next_y;
	}
	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
	{
		vars->player.pos_x = next_x;
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
