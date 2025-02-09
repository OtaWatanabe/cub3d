#include "../includes/cub3d.h"
#define EnterNotify 7
#define LeaveNotify 8

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.mouse_in_window = 0;
	vars.old_x = -1;
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	init_vars(&vars, argv[1]);
	parse_cub(argv[1], &vars);
	validate_map(&vars);
	init_mlx(&vars);
	init_frame(&vars);
	// プレイヤー初期位置・向き
	init_player_state(&vars);
	// イベントフック: キー押下/離されたとき
	mlx_hook(vars.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_press, &vars);
	mlx_hook(vars.win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, key_release, &vars);
	mlx_hook(vars.win, 17, (1L << 17), close_window, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	// mlx_hook(vars.win, EnterNotify, 1L << 4, mouse_enter, &vars);
	// mlx_hook(vars.win, LeaveNotify, 1L << 5, mouse_leave, &vars);
	// 毎フレームの描画 (render_frame) を登録
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	// イベントループ開始
	mlx_loop(vars.mlx);
	return (0);
}
