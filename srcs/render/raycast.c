/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:42:17 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:42:21 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_walls(t_vars *vars)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray_vars(vars, x);
		dda_loop(vars);
		calc_wall_distance_height(vars);
		calc_using_tex(vars);
		calc_tex_pos(vars);
		draw_wall(vars, x);
		x++;
	}
}
