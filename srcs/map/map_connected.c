#include "../../includes/cub3d.h"

// 斜め移動を含むDFS
int	component_contains_player(int row, int col, char **map, int height,
		int width, int **visited)
{
	int		found;
	char	c;
	int		dirs[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1},
				{-1, 1}, {-1, -1}};
	int		new_r;
	int		new_c;
	char	nc;

	// int		dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	found = 0;
	c = map[row][col];
	// プレイヤーの開始位置ならフラグを立てる
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		found = 1;
	visited[row][col] = 1;
	for (int i = 0; i < 8; i++)
	{
		new_r = row + dirs[i][0];
		new_c = col + dirs[i][1];
		// 範囲内かつ未訪問なら
		if (new_r >= 0 && new_r < height && new_c >= 0 && new_c < width
			&& !visited[new_r][new_c])
		{
			nc = map[new_r][new_c];
			if (nc == '1' || nc == '0' || nc == 'N' || nc == 'S' || nc == 'E'
				|| nc == 'W' || nc == 'A')
			{
				if (component_contains_player(new_r, new_c, map, height, width,
						visited))
					found = 1;
			}
		}
	}
	return (found);
}

// すべての'1'からプレイヤーにたどり着けるかチェックする関数
void	check_map_connected(t_vars *vars)
{
	int	i;
	int	j;

	allocate_visited(vars);
	i = 0;
	while (i < vars->cub.em_height)
	{
		j = 0;
		while (j < vars->cub.em_width)
		{
			if (vars->cub.e_map[i][j] == '1' && !vars->cub.visited[i][j])
			{
				if (!component_contains_player(i, j, vars->cub.e_map,
						vars->cub.em_height, vars->cub.em_width,
						vars->cub.visited))
				{
					safe_exit_with_error(vars, "map is not connected");
				}
			}
			j++;
		}
		i++;
	}
	free_visited(vars);
}
