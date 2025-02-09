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
	printf("Player Position: (%.2f, %.2f)\n", vars->player.posX,
		vars->player.posY);
	printf("Direction Vector: (%.2f, %.2f)\n", vars->player.dirX,
		vars->player.dirY);
	printf("Plane Vector: (%.2f, %.2f)\n", vars->player.planeX,
		vars->player.planeY);
	// ベクトルの直行
	double dot_product = vars->player.dirX * vars->player.planeX
		+ vars->player.dirY * vars->player.planeY;
	printf("Dot Product (should be ~0): %.5f\n", dot_product);
}