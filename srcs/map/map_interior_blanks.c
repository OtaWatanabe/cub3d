#include "../../includes/cub3d.h"

void	flood_fill(char **map, int height, int width, int row, int col,
		int **visited)
{
	int	dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int	i;

	if (row < 0 || row >= height || col < 0 || col >= width)
		return ;
	if (visited[row][col])
		return ;
	/* 空白でなければ探索しない */
	if (map[row][col] != ' ')
		return ;
	visited[row][col] = 1;
	i = 0;
	while (i < 4)
	{
		flood_fill(map, height, width, row + dirs[i][0], col + dirs[i][1],
			visited);
		i++;
	}
}

/// 外周の空白文字をvisited 配列にマークする
void	flood_fill_outside(char **map, int height, int width, int **visited)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] == ' ' && !visited[0][i])
			flood_fill(map, height, width, 0, i, visited);
		if (map[height - 1][i] == ' ' && !visited[height - 1][i])
			flood_fill(map, height, width, height - 1, i, visited);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] == ' ' && !visited[i][0])
			flood_fill(map, height, width, i, 0, visited);
		if (map[i][width - 1] == ' ' && !visited[i][width - 1])
			flood_fill(map, height, width, i, width - 1, visited);
		i++;
	}
}

// 外周から到達できなかった内部の空白を'A'に置き換える
void	replace_interior_blanks(t_vars *vars)
{
	int	i;
	int	j;

	allocate_visited(vars);
	flood_fill_outside(vars->cub.e_map, vars->cub.em_height, vars->cub.em_width,
		vars->cub.visited);
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
