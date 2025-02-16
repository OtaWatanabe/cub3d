/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:40:39 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:40:45 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	clear_frame(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(&vars->frame, x, y, vars->ceiling_color);
			else
				my_mlx_pixel_put(&vars->frame, x, y, vars->floor_color);
			x++;
		}
		x = 0;
		y++;
	}
}
