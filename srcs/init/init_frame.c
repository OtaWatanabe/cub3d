#include "../../includes/cub3d.h"

int	init_frame(t_vars *vars)
{
	vars->frame.img_ptr = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT
			- 1);
	if (!vars->frame.img_ptr)
		safe_exit_with_error(vars, "mlx_new_image failed");
	vars->frame.data = (int *)mlx_get_data_addr(vars->frame.img_ptr,
			&vars->frame.bpp, &vars->frame.size_line, &vars->frame.endian);
	if (!vars->frame.data)
		safe_exit_with_error(vars, "mlx_get_data_addr failed");
	vars->frame.width = SCREEN_WIDTH;
	vars->frame.height = SCREEN_HEIGHT;
	return (0);
}
