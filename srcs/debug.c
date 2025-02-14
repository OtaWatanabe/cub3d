#include "../includes/cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	debug_player_move(t_vars *vars)
{
	printf("Player Position: (%.2f, %.2f)\n", vars->player.pos_x,
		vars->player.pos_y);
	printf("Direction Vector: (%.2f, %.2f)\n", vars->player.dir_x,
		vars->player.dir_y);
	printf("Plane Vector: (%.2f, %.2f)\n", vars->player.plane_x,
		vars->player.plane_y);
	double dot_product = vars->player.dir_x * vars->player.plane_x
		+ vars->player.dir_y * vars->player.plane_y;
	printf("Dot Product (should be ~0): %.5f\n", dot_product);
}
