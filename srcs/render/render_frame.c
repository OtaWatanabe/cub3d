#include "../../includes/cub3d.h"

int render_frame(t_vars *vars)
{
    //キー入力によってプレイヤーの移動、回転
    move_player(vars);

    // 背景描画
    clear_frame(vars);

    // 3) レイキャスト (DDA) で壁を描画
    draw_walls(vars);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->frame.img_ptr, 0, 0);

    return (0);
}
