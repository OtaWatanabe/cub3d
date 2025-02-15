#include "../../includes/cub3d.h"

/*
	if (x == SCREEN_WIDTH / 2)
		return (0);
	angle = (x - SCREEN_WIDTH / 2) * MOUSE_SENSITIVITY;
	*/
// void	move_w(t_vars *vars)
// {
// 	double	next_x;
// 	double	next_y;

// 	next_x = vars->player.pos_x + vars->player.dir_x * MOVE_SPEED;
// 	next_y = vars->player.pos_y + vars->player.dir_y * MOVE_SPEED;
// 	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
// 	{
// 		vars->player.pos_x = next_x;
// 	}
// 	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
// 	{
// 		vars->player.pos_y = next_y;
// 	}
// }

// void	move_s(t_vars *vars)
// {
// 	double	next_x;
// 	double	next_y;

// 	next_x = vars->player.pos_x - vars->player.dir_x * MOVE_SPEED;
// 	next_y = vars->player.pos_y - vars->player.dir_y * MOVE_SPEED;
// 	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
// 	{
// 		vars->player.pos_x = next_x;
// 	}
// 	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
// 	{
// 		vars->player.pos_y = next_y;
// 	}
// }

// void	move_a(t_vars *vars)
// {
// 	double	next_x;
// 	double	next_y;

// 	next_x = vars->player.pos_x - vars->player.plane_x * MOVE_SPEED;
// 	next_y = vars->player.pos_y - vars->player.plane_y * MOVE_SPEED;
// 	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
// 	{
// 		vars->player.pos_y = next_y;
// 	}
// 	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
// 	{
// 		vars->player.pos_x = next_x;
// 	}
// }

// void	move_d(t_vars *vars)
// {
// 	double	next_x;
// 	double	next_y;

// 	next_x = vars->player.pos_x + vars->player.plane_x * MOVE_SPEED;
// 	next_y = vars->player.pos_y + vars->player.plane_y * MOVE_SPEED;
// 	if (vars->map[(int)next_y][(int)vars->player.pos_x] == '0')
// 	{
// 		vars->player.pos_y = next_y;
// 	}
// 	if (vars->map[(int)vars->player.pos_y][(int)next_x] == '0')
// 	{
// 		vars->player.pos_x = next_x;
// 	}
// }
#define COLLISION_RADIUS 0.011 // プレイヤーの衝突半径
#define EPSILON 0.01           // 衝突判定のためのイプシロン

// 2点 (x1, y1) と (x2, y2) のユークリッド距離の2乗を返す関数
static double	squared_distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (dx * dx + dy * dy);
}

int	circle_rect_collision(double x, double y, double cell_x, double cell_y)
{
	double	closest_x;
	double	closest_y;
	double	dist_sq;
	double	allowed;

	closest_x = fmax(cell_x, fmin(x, cell_x + 1));
	closest_y = fmax(cell_y, fmin(y, cell_y + 1));
	dist_sq = squared_distance(x, y, closest_x, closest_y);
	allowed = (COLLISION_RADIUS - EPSILON) * (COLLISION_RADIUS - EPSILON);
	return (dist_sq < allowed);
}

/*
	i ~ end_y までのy座標を走査
	0 = j ~ (end_x - start_x) までのx座標を走査
	ただしend_x = (int)floor(x + COLLISION_RADIUS) (ローカル変数の制限より)
	2重whileの中での絶対座標は (start_x+j, i)
	障害物でないことと円と四角形の衝突判定を行う
*/

int	can_move(t_vars *vars, double x, double y)
{
	int	i;
	int	j;
	int	end_y;
	int	start_x;

	i = (int)(y - COLLISION_RADIUS);
	end_y = (int)(y + COLLISION_RADIUS);
	start_x = (int)(x - COLLISION_RADIUS);
	while (i <= end_y)
	{
		j = 0;
		while (j <= (int)(x + COLLISION_RADIUS) - start_x)
		{
			if (vars->map[i][start_x + j] != '0' && circle_rect_collision(x, y,
					start_x + j, i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// 上方向移動（前進）の例
void	move_w(t_vars *vars)
{
	double	next_x;
	double	next_y;

	next_x = vars->player.pos_x + vars->player.dir_x * MOVE_SPEED;
	next_y = vars->player.pos_y + vars->player.dir_y * MOVE_SPEED;
	// x,y軸の移動をまず試みる
	if (can_move(vars, next_x, next_y))
	{
		vars->player.pos_x = next_x;
		vars->player.pos_y = next_y;
	}
	else
	{
		// X軸のみ移動できるかチェック
		if (can_move(vars, next_x, vars->player.pos_y))
			vars->player.pos_x = next_x;
		// Y軸のみ移動できるかチェック
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
