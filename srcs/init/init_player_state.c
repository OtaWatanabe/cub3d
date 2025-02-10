#include "../../includes/cub3d.h"

void	player_north_direction(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x + 0.5;
	vars->player.pos_y = y + 0.5;
	vars->player.dir_x = 0.0;
	vars->player.dir_y = -1.0; // 北向き(上向き)
	vars->player.plane_x = 0.66;
	vars->player.plane_y = 0.0;
	vars->map[y][x] = '0';
}

void	player_south_direction(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x + 0.5;
	vars->player.pos_y = y + 0.5;
	vars->player.dir_x = 0.0;
	vars->player.dir_y = 1.0; // 南向き(下向き)
	vars->player.plane_x = -0.66;
	vars->player.plane_y = 0.0;
	vars->map[y][x] = '0';
}

void	player_east_direction(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x + 0.5;
	vars->player.pos_y = y + 0.5;
	vars->player.dir_x = 1.0;
	vars->player.dir_y = 0.0; // 東向き(右向き)
	vars->player.plane_x = 0.0;
	vars->player.plane_y = 0.66;
	vars->map[y][x] = '0';
}

void	player_west_direction(t_vars *vars, int x, int y)
{
	vars->player.pos_x = x + 0.5;
	vars->player.pos_y = y + 0.5;
	vars->player.dir_x = -1.0;
	vars->player.dir_y = 0.0; // 西向き(左向き)
	vars->player.plane_x = 0.0;
	vars->player.plane_y = -0.66;
	vars->map[y][x] = '0';
}

void	init_player_state(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'N')
				player_north_direction(vars, x, y);
			else if (vars->map[y][x] == 'S')
				player_south_direction(vars, x, y);
			else if (vars->map[y][x] == 'E')
				player_east_direction(vars, x, y);
			else if (vars->map[y][x] == 'W')
				player_west_direction(vars, x, y);
			x++;
		}
		y++;
	}
}
