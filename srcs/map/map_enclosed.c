#include "../../includes/cub3d.h"

void	init_dirs4(int dirs[4][2])
{
	dirs[0][0] = 1;
	dirs[0][1] = 0;
	dirs[1][0] = -1;
	dirs[1][1] = 0;
	dirs[2][0] = 0;
	dirs[2][1] = 1;
	dirs[3][0] = 0;
	dirs[3][1] = -1;
}

int	is_reachable_zero_player(int row, int col, t_vars *vars)
{
	int	dirs[4][2];
	int	i;

	i = 0;
	init_dirs4(dirs);
	if (row < 0 || row >= vars->cub.em_height || col < 0
		|| col >= vars->cub.em_width)
		return (0);
	if (vars->cub.visited[row][col])
		return (0);
	vars->cub.visited[row][col] = 1;
	if (vars->cub.e_map[row][col] == '1' || vars->cub.e_map[row][col] == '\0')
		return (0);
	if (is_player_char(vars->cub.e_map[row][col])
		|| vars->cub.e_map[row][col] == '0')
		return (1);
	while (i < 4)
	{
		if (is_reachable_zero_player(row + dirs[i][0], col + dirs[i][1], vars))
			return (1);
		i++;
	}
	return (0);
}

void	check_map_enclosed(t_vars *vars)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	j = 0;
	allocate_visited(vars);
	while (i < vars->cub.em_height)
	{
		while (j < vars->cub.em_width)
		{
			if (vars->cub.e_map[i][j] == ' ' && !vars->cub.visited[i][j])
			{
				if (is_reachable_zero_player(i, j, vars))
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
