#include "../../includes/cub3d.h"

void	calc_wall_distance_height(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.perp_wall_dist = (vars->ray.map_x - vars->player.pos_x + (1
					- vars->ray.step_x) / 2) / vars->ray.ray_dir_x;
	else
		vars->ray.perp_wall_dist = (vars->ray.map_y - vars->player.pos_y + (1
					- vars->ray.step_y) / 2) / vars->ray.ray_dir_y;
	vars->ray.line_height = (int)(SCREEN_HEIGHT / vars->ray.perp_wall_dist);
	vars->ray.draw_start = -vars->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (vars->ray.draw_start < 0)
		vars->ray.draw_start = 0;
	vars->ray.draw_end = vars->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (vars->ray.draw_end >= SCREEN_HEIGHT)
		vars->ray.draw_end = SCREEN_HEIGHT - 1;
	vars->ray.wall_x = (vars->ray.side == 0) ? vars->player.pos_y
		+ vars->ray.perp_wall_dist * vars->ray.ray_dir_y : vars->player.pos_x
		+ vars->ray.perp_wall_dist * vars->ray.ray_dir_x;
	vars->ray.wall_x -= floor(vars->ray.wall_x);
}

void	calc_using_tex(t_vars *vars)
{
	if (vars->ray.side == 0)
	{
		if (vars->ray.ray_dir_x > 0)
			vars->ray.tex_ptr = vars->tex_e;
		else
			vars->ray.tex_ptr = vars->tex_w;
	}
	else
	{
		if (vars->ray.ray_dir_y > 0)
			vars->ray.tex_ptr = vars->tex_s;
		else
			vars->ray.tex_ptr = vars->tex_n;
	}
}

void	calc_tex_pos(t_vars *vars)
{
	vars->ray.tex_x = (int)(vars->ray.wall_x * (double)vars->ray.tex_ptr.width);
	if (vars->ray.side == 0 && vars->ray.ray_dir_x < 0)
		vars->ray.tex_x = vars->ray.tex_ptr.width - vars->ray.tex_x - 1;
	if (vars->ray.side == 1 && vars->ray.ray_dir_y > 0)
		vars->ray.tex_x = vars->ray.tex_ptr.width - vars->ray.tex_x - 1;
	vars->ray.step = 1.0 * vars->ray.tex_ptr.height / vars->ray.line_height;
	vars->ray.tex_pos = (vars->ray.draw_start - SCREEN_HEIGHT / 2
			+ vars->ray.line_height / 2) * vars->ray.step;
}

void	draw_wall(t_vars *vars, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = vars->ray.draw_start;
	while (y < vars->ray.draw_end)
	{
		tex_y = (int)vars->ray.tex_pos & (vars->ray.tex_ptr.height - 1);
		vars->ray.tex_pos += vars->ray.step;
		color = get_tex_color(vars->ray.tex_ptr, vars->ray.tex_x, tex_y);
		if (vars->ray.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		my_mlx_pixel_put(&vars->frame, x, y, color);
		y++;
	}
}
