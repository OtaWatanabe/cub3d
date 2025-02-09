#include "../../includes/cub3d.h"

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->keys.w = 0;
	else if (keycode == KEY_S)
		vars->keys.s = 0;
	else if (keycode == KEY_A)
		vars->keys.a = 0;
	else if (keycode == KEY_D)
		vars->keys.d = 0;
	else if (keycode == KEY_LEFT)
		vars->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		vars->keys.right = 0;
	return (0);
}
