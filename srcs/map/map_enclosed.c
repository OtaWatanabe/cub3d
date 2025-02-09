#include "../../includes/cub3d.h"

int	is_reachable_zero_player(int start_row, int start_col, int **visited,
		char **map, int height, int width)
{
	int	dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int	i;

	i = 0;
	if (start_row < 0 || start_row >= height || start_col < 0
		|| start_col >= width)
		return (0);
	if (visited[start_row][start_col])
		return (0);
	visited[start_row][start_col] = 1;
	if (map[start_row][start_col] == '1' || map[start_row][start_col] == '\0')
		return (0);
	if (map[start_row][start_col] == '0' || map[start_row][start_col] == 'N'
		|| map[start_row][start_col] == 'S' || map[start_row][start_col] == 'E'
		|| map[start_row][start_col] == 'W')
		return (1);
	while (i < 4)
	{
		if (is_reachable_zero_player(start_row + dirs[i][0], start_col
				+ dirs[i][1], visited, map, height, width))
			return (1);
		i++;
	}
	return (0);
}

void	check_map_enclosed(t_vars *vars)
{
	int **visited;
	int i;
	int j;

	i = 0;
	j = 0;
	allocate_visited(vars);
	while (i < vars->cub.em_height)
	{
		while (j < vars->cub.em_width)
		{
			if (vars->cub.e_map[i][j] == ' ' && !vars->cub.visited[i][j])
			{
				if (is_reachable_zero_player(i, j, vars->cub.visited,
						vars->cub.e_map, vars->cub.em_height,
						vars->cub.em_width))
				{
					safe_exit_with_error(vars, "map is not enclosed");
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	free_visited(vars);
}