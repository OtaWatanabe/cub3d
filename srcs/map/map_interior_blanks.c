#include "../../includes/cub3d.h"

void	flood_fill(int row, int col, t_vars *vars)
{
	int	dirs[4][2];
	int	i;

	if (row < 0 || row >= vars->cub.em_height || col < 0
		|| col >= vars->cub.em_width)
		return ;
	if (vars->cub.visited[row][col])
		return ;
	if (vars->cub.e_map[row][col] != ' ')
		return ;
	init_dirs4(dirs);
	vars->cub.visited[row][col] = 1;
	i = 0;
	while (i < 4)
	{
		flood_fill(row + dirs[i][0], col + dirs[i][1], vars);
		i++;
	}
}

/// 外周の空白文字をvisited 配列にマークする
void	flood_fill_outside(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->cub.em_width)
	{
		if (vars->cub.e_map[0][i] == ' ' && !vars->cub.visited[0][i])
			flood_fill(0, i, vars);
		if (vars->cub.e_map[vars->cub.em_height - 1][i] == ' '
			&& !vars->cub.visited[vars->cub.em_height - 1][i])
			flood_fill(vars->cub.em_height - 1, i, vars);
		i++;
	}
	i = 0;
	while (i < vars->cub.em_height)
	{
		if (vars->cub.e_map[i][0] == ' ' && !vars->cub.visited[i][0])
			flood_fill(i, 0, vars);
		if (vars->cub.e_map[i][vars->cub.em_width - 1] == ' '
			&& !vars->cub.visited[i][vars->cub.em_width - 1])
			flood_fill(i, vars->cub.em_width - 1, vars);
		i++;
	}
}

// 外周から到達できなかった内部の空白を'A'に置き換える
void	replace_interior_blanks(t_vars *vars)
{
	int	i;
	int	j;

	allocate_visited(vars);
	flood_fill_outside(vars);
	i = 0;
	while (i < vars->cub.em_height)
	{
		j = 0;
		while (j < vars->cub.em_width)
		{
			if (vars->cub.e_map[i][j] == ' ' && !vars->cub.visited[i][j])
				vars->cub.e_map[i][j] = 'A';
			j++;
		}
		i++;
	}
	free_visited(vars);
}
