#include "../../includes/cub3d.h"

int	render_frame(t_vars *vars)
{
	//キー入力によってプレイヤーの移動、回転
	move_player(vars);
	// フレームをクリア
	clear_frame(vars);
	// レイキャスト
	draw_walls(vars);
	draw_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frame.img_ptr, 0, 0);
	return (0);
}
