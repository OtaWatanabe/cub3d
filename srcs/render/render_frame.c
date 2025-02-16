/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:42:40 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:42:41 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render_frame(t_vars *vars)
{
	move_player(vars);
	clear_frame(vars);
	draw_walls(vars);
	draw_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frame.img_ptr, 0, 0);
	return (0);
}
