#include "../../includes/cub3d.h"

void	draw_walls(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_vars(vars, x);
		dda_loop(vars);
		calc_wall_distance_height(vars);
		calc_using_tex(vars);
		calc_tex_pos(vars);
		draw_wall(vars, x);
		x++;
	}
}
