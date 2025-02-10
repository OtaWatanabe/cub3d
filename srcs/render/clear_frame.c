#include "../../includes/cub3d.h"

void	clear_frame(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(&vars->frame, x, y, vars->ceiling_color);
			else
				my_mlx_pixel_put(&vars->frame, x, y, vars->floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}
