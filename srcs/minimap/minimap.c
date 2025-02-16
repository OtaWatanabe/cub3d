/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:32:57 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 14:07:32 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_cell(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->minimap.color == -1)
		return ;
	y = vars->minimap.top;
	while (y < vars->minimap.bottom)
	{
		x = vars->minimap.left;
		while (x < vars->minimap.right)
		{
			my_mlx_pixel_put(&vars->frame, x, y, vars->minimap.color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap_init(t_vars *vars)
{
	vars->minimap.scale_x = (double)MINIMAP_MAX_WIDTH / (double)vars->map_width;
	vars->minimap.scale_y = (double)MINIMAP_MAX_HEIGHT
		/ (double)vars->map_height;
	vars->minimap.scale = fmin(vars->minimap.scale_x, vars->minimap.scale_y);
	if (vars->minimap.scale < 1.0)
		vars->minimap.scale = 1.0;
}

/*
	マップのセルの位置を計算する
*/
static void	calc_cell_position(t_vars *vars, int i, int j)
{
	vars->minimap.left = MINIMAP_OFFSET_X + (int)round(j * vars->minimap.scale);
	vars->minimap.right = MINIMAP_OFFSET_X + (int)round((j + 1)
			* vars->minimap.scale);
	vars->minimap.top = MINIMAP_OFFSET_Y + (int)round(i * vars->minimap.scale);
	vars->minimap.bottom = MINIMAP_OFFSET_Y + (int)round((i + 1)
			* vars->minimap.scale);
}

void	get_cell_color(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		vars->minimap.color = 0x888888;
	else if (vars->map[i][j] == ' ')
		vars->minimap.color = -1;
	else if (vars->map[i][j] == 'A')
		vars->minimap.color = 0xF7F7F7;
	else
		vars->minimap.color = 0xFFFFFF;
}

void	draw_minimap(t_vars *vars)
{
	int	i;
	int	j;
	int	row_width;

	draw_minimap_init(vars);
	i = 0;
	while (i < vars->map_height)
	{
		row_width = ft_strlen(vars->map[i]);
		j = 0;
		while (j < row_width)
		{
			calc_cell_position(vars, i, j);
			get_cell_color(vars, i, j);
			draw_cell(vars);
			j++;
		}
		i++;
	}
	draw_player(vars, vars->minimap.scale);
}
