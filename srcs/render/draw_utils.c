#include "../../includes/cub3d.h"

void	calc_wall_distance_height(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.perpWallDist = (vars->ray.mapX - vars->player.posX + (1
					- vars->ray.stepX) / 2) / vars->ray.rayDirX;
	else
		vars->ray.perpWallDist = (vars->ray.mapY - vars->player.posY + (1
					- vars->ray.stepY) / 2) / vars->ray.rayDirY;
	vars->ray.lineHeight = (int)(SCREEN_HEIGHT / vars->ray.perpWallDist);
	vars->ray.drawStart = -vars->ray.lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (vars->ray.drawStart < 0)
		vars->ray.drawStart = 0;
	vars->ray.drawEnd = vars->ray.lineHeight / 2 + SCREEN_HEIGHT / 2;
	if (vars->ray.drawEnd >= SCREEN_HEIGHT)
		vars->ray.drawEnd = SCREEN_HEIGHT - 1;
	vars->ray.wallX = (vars->ray.side == 0) ? vars->player.posY
		+ vars->ray.perpWallDist * vars->ray.rayDirY : vars->player.posX
		+ vars->ray.perpWallDist * vars->ray.rayDirX;
	vars->ray.wallX -= floor(vars->ray.wallX);
}

void	calc_using_tex(t_vars *vars)
{
	if (vars->ray.side == 0)
	{
		if (vars->ray.rayDirX > 0)
			vars->ray.tex_ptr = vars->texE;
		else
			vars->ray.tex_ptr = vars->texW;
	}
	else
	{
		if (vars->ray.rayDirY > 0)
			vars->ray.tex_ptr = vars->texS;
		else
			vars->ray.tex_ptr = vars->texN;
	}
}

void	calc_tex_pos(t_vars *vars)
{
	vars->ray.texX = (int)(vars->ray.wallX * (double)vars->ray.tex_ptr.width);
	if (vars->ray.side == 0 && vars->ray.rayDirX < 0)
		vars->ray.texX = vars->ray.tex_ptr.width - vars->ray.texX - 1;
	if (vars->ray.side == 1 && vars->ray.rayDirY > 0)
		vars->ray.texX = vars->ray.tex_ptr.width - vars->ray.texX - 1;
	vars->ray.step = 1.0 * vars->ray.tex_ptr.height / vars->ray.lineHeight;
	vars->ray.texPos = (vars->ray.drawStart - SCREEN_HEIGHT / 2
			+ vars->ray.lineHeight / 2) * vars->ray.step;
}

void	draw_wall(t_vars *vars, int x)
{
	int	y;
	int	tex_y;
	int	color;

	y = vars->ray.drawStart;
	while (y < vars->ray.drawEnd)
	{
		tex_y = (int)vars->ray.texPos & (vars->ray.tex_ptr.height - 1);
		vars->ray.texPos += vars->ray.step;
		color = get_tex_color(vars->ray.tex_ptr, vars->ray.texX, tex_y);
		if (vars->ray.side == 1)
			color = (color >> 1) & 0x7F7F7F;
		my_mlx_pixel_put(&vars->frame, x, y, color);
		y++;
	}
}
