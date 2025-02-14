#include "../includes/cub3d.h"

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
	init_vars(&vars);
	parse_cub(argv[1], &vars);
	validate_map(&vars);
	init_mlx(&vars);
	init_frame(&vars);
	init_player_state(&vars);
	mlx_hook(vars.win, EVENT_KEY_PRESS, MASK_KEY_PRESS, key_press, &vars);
	mlx_hook(vars.win, EVENT_KEY_RELEASE, MASK_KEY_RELEASE, key_release, &vars);
	mlx_hook(vars.win, 17, (1L << 17), close_window, &vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

// #define EnterNotify 7
// #define LeaveNotify 8
	// mlx_hook(vars.win, EnterNotify, 1L << 4, mouse_enter, &vars);
	// mlx_hook(vars.win, LeaveNotify, 1L << 5, mouse_leave, &vars);
