#include "../../includes/cub3d.h"

#define COLLISION_RADIUS 0.011 // プレイヤーの衝突半径
#define EPSILON 0.01           // 衝突判定のためのイプシロン

/*
	2点 (x1, y1) と (x2, y2) のユークリッド距離の2乗を返す関数(計算量を減らすため)
*/
static double	squared_distance(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = x2 - x1;
	dy = y2 - y1;
	return (dx * dx + dy * dy);
}

/*
	プレイヤー(x, y)とセル(cell_x, cell_y)の衝突判定を行う関数
	max(min())でx,yをcell_x,cell_yの範囲に制限する
	最も近い点の距離の2乗を計算
	内部の円の半径の2乗を計算
	最も近い点の距離の2乗が内部の円の半径の2乗より小さいかどうかを返す
	小さければ衝突している
*/
int	circle_rect_collision(double x, double y, double cell_x, double cell_y)
{
	double	closest_x;
	double	closest_y;
	double	nearest_point_distance_sq;
	double	inner_ball_radius_sq;

	closest_x = fmax(cell_x, fmin(x, cell_x + 1));
	closest_y = fmax(cell_y, fmin(y, cell_y + 1));
	nearest_point_distance_sq = squared_distance(x, y, closest_x, closest_y);
	inner_ball_radius_sq = (COLLISION_RADIUS - EPSILON) * (COLLISION_RADIUS
			- EPSILON);
	return (nearest_point_distance_sq < inner_ball_radius_sq);
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
