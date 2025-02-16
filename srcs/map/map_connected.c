/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_connected.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:24:24 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:59:55 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_traversable_cell(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'A');
}

static void	init_dirs8(int dirs[8][2])
{
	dirs[0][0] = 1;
	dirs[0][1] = 0;
	dirs[1][0] = -1;
	dirs[1][1] = 0;
	dirs[2][0] = 0;
	dirs[2][1] = 1;
	dirs[3][0] = 0;
	dirs[3][1] = -1;
	dirs[4][0] = 1;
	dirs[4][1] = 1;
	dirs[5][0] = 1;
	dirs[5][1] = -1;
	dirs[6][0] = -1;
	dirs[6][1] = 1;
	dirs[7][0] = -1;
	dirs[7][1] = -1;
}

static int	component_contains_player(int row, int col, t_vars *vars)
{
	int	dirs[8][2];
	int	i;
	int	found;

	i = 0;
	found = 0;
	init_dirs8(dirs);
	if (is_player_char(vars->cub.e_map[row][col]))
		found = 1;
	vars->cub.visited[row][col] = 1;
	while (i < 8)
	{
		if (row + dirs[i][0] >= 0 && row + dirs[i][0] < vars->cub.em_height
			&& col + dirs[i][1] >= 0 && col + dirs[i][1] < vars->cub.em_width
			&& !vars->cub.visited[row + dirs[i][0]][col + dirs[i][1]])
		{
			if (is_traversable_cell(vars->cub.e_map[row + dirs[i][0]][col
				+ dirs[i][1]]))
				if (component_contains_player(row + dirs[i][0], col
					+ dirs[i][1], vars))
					found = 1;
		}
		i++;
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
				if (!component_contains_player(i, j, vars))
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
