/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:06:53 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:09:26 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

/*
	rotateを使うバージョン
*/
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
// }
