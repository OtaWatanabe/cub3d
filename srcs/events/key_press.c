/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:15:25 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:15:57 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		free_vars(vars);
		exit(0);
	}
	else if (keycode == KEY_W)
		vars->keys.w = 1;
	else if (keycode == KEY_S)
		vars->keys.s = 1;
	else if (keycode == KEY_A)
		vars->keys.a = 1;
	else if (keycode == KEY_D)
		vars->keys.d = 1;
	else if (keycode == KEY_LEFT)
		vars->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		vars->keys.right = 1;
	return (0);
}
