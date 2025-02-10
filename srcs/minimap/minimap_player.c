#include "../../includes/cub3d.h"

void	draw_dir_line_init(t_vars *vars)
{
	vars->minimap.dx = abs(vars->minimap.ex - vars->minimap.px);
	vars->minimap.dy = abs(vars->minimap.ey - vars->minimap.py);
	if (vars->minimap.px < vars->minimap.ex)
		vars->minimap.sx = 1;
	else
		vars->minimap.sx = -1;
	if (vars->minimap.py < vars->minimap.ey)
		vars->minimap.sy = 1;
	else
		vars->minimap.sy = -1;
	vars->minimap.err = vars->minimap.dx - vars->minimap.dy;
}

// Bresenhamの直線描画アルゴリズム
void	draw_dir_line(t_vars *vars, int color)
{
	draw_dir_line_init(vars);
	while (1)
	{
		my_mlx_pixel_put(&vars->frame, vars->minimap.px, vars->minimap.py,
			color);
		if (vars->minimap.px == vars->minimap.ex
			&& vars->minimap.py == vars->minimap.ey)
			break ;
		vars->minimap.e2 = 2 * vars->minimap.err;
		if (vars->minimap.e2 > -vars->minimap.dy)
		{
			vars->minimap.err -= vars->minimap.dy;
			vars->minimap.px += vars->minimap.sx;
		}
		if (vars->minimap.e2 < vars->minimap.dx)
		{
			vars->minimap.err += vars->minimap.dx;
			vars->minimap.py += vars->minimap.sy;
		}
	}
}

void	draw_player(t_vars *vars, double scale)
{
	vars->minimap.px = MINIMAP_OFFSET_X + vars->player.pos_x * scale;
	vars->minimap.py = MINIMAP_OFFSET_Y + vars->player.pos_y * scale;
	for (int dy = -1; dy <= 1; dy++)
	{
		for (int dx = -1; dx <= 1; dx++)
		{
			my_mlx_pixel_put(&vars->frame, (int)vars->minimap.px + dx,
				(int)vars->minimap.py + dy, 0x00FF00);
		}
	}
	vars->minimap.ex = (int)(vars->minimap.px + vars->player.dir_x * ARROW_LEN);
	vars->minimap.ey = (int)(vars->minimap.py + vars->player.dir_y * ARROW_LEN);
	vars->minimap.px = (int)vars->minimap.px;
	vars->minimap.py = (int)vars->minimap.py;
	draw_dir_line(vars, (int)0xFF0000);
}
