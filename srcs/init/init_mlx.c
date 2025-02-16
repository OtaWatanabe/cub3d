/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:20:48 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:21:33 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	load_tex(t_vars *vars)
{
	vars->tex_n.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.tex_n_path,
			&vars->tex_n.width, &vars->tex_n.height);
	if (!vars->tex_n.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->tex_n.data = (int *)mlx_get_data_addr(vars->tex_n.img_ptr,
			&vars->tex_n.bpp, &vars->tex_n.size_line, &vars->tex_n.endian);
	vars->tex_s.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.tex_s_path,
			&vars->tex_s.width, &vars->tex_s.height);
	if (!vars->tex_s.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->tex_s.data = (int *)mlx_get_data_addr(vars->tex_s.img_ptr,
			&vars->tex_s.bpp, &vars->tex_s.size_line, &vars->tex_s.endian);
	vars->tex_e.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.tex_e_path,
			&vars->tex_e.width, &vars->tex_e.height);
	if (!vars->tex_e.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->tex_e.data = (int *)mlx_get_data_addr(vars->tex_e.img_ptr,
			&vars->tex_e.bpp, &vars->tex_e.size_line, &vars->tex_e.endian);
	vars->tex_w.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.tex_w_path,
			&vars->tex_w.width, &vars->tex_w.height);
	if (!vars->tex_w.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->tex_w.data = (int *)mlx_get_data_addr(vars->tex_w.img_ptr,
			&vars->tex_w.bpp, &vars->tex_w.size_line, &vars->tex_w.endian);
	return (0);
}

static void	check_tex_size(t_vars *vars)
{
	if (64 != vars->tex_n.width || vars->tex_n.width != vars->tex_n.height
		|| vars->tex_n.height != vars->tex_s.width
		|| vars->tex_s.width != vars->tex_s.height
		|| vars->tex_s.height != vars->tex_e.width
		|| vars->tex_e.width != vars->tex_e.height
		|| vars->tex_e.height != vars->tex_w.width
		|| vars->tex_w.width != vars->tex_w.height)
		safe_exit_with_error(vars, "texture size  must be 64x64");
}

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		safe_exit_with_error(vars, "mlx_init failed");
	load_tex(vars);
	check_tex_size(vars);
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!vars->win)
		safe_exit_with_error(vars, "mlx_new_window failed");
	return (0);
}
