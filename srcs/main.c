#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_vars vars;

    if (argc != 2) {
        printf("Error\n");
        return (0);
    }
    load_ber(argv[1], &vars);
    if (init_mlx(&vars))
        return (1);
    // フレームバッファ用イメージ
    init_frame(&vars);
    // プレイヤー初期位置・向き
    init_player_state(&vars);
    // キー状態初期化s
    init_key_state(&vars.keys);
    // イベントフック: キー押下/離されたとき
    mlx_hook(vars.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_press, &vars);
    mlx_hook(vars.win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, key_release, &vars);
    mlx_hook(vars.win, 17, (1L << 17), close_window, &vars);
    // 毎フレームの描画 (render_frame) を登録
    mlx_loop_hook(vars.mlx, render_frame, &vars);
    // イベントループ開始
    mlx_loop(vars.mlx);
    return (0);
}
