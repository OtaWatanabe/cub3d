#include "../../includes/cub3d.h"

int close_window(t_vars *vars)
{
    // 画像を破棄
    if (vars->frame.img_ptr)
        mlx_destroy_image(vars->mlx, vars->frame.img_ptr);
    // ウィンドウを破棄
    if (vars->win)
        mlx_destroy_window(vars->mlx, vars->win);
    //ディスプレイ接続を破棄
    if (vars->mlx)
    {
        mlx_destroy_display(vars->mlx);
        free(vars->mlx); // mlx_init()で割り当てられた内部構造体の解放
    }
    exit(0);
    return (0);
}