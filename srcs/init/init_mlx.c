#include "../../includes/cub3d.h"

int	load_tex(t_vars *vars)
{
	vars->texN.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.texN_path,
			&vars->texN.width, &vars->texN.height);
	if (!vars->texN.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->texN.data = (int *)mlx_get_data_addr(vars->texN.img_ptr,
			&vars->texN.bpp, &vars->texN.size_line, &vars->texN.endian);
	vars->texS.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.texS_path,
			&vars->texS.width, &vars->texS.height);
	if (!vars->texS.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->texS.data = (int *)mlx_get_data_addr(vars->texS.img_ptr,
			&vars->texS.bpp, &vars->texS.size_line, &vars->texS.endian);
	vars->texE.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.texE_path,
			&vars->texE.width, &vars->texE.height);
	if (!vars->texE.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->texE.data = (int *)mlx_get_data_addr(vars->texE.img_ptr,
			&vars->texE.bpp, &vars->texE.size_line, &vars->texE.endian);
	vars->texW.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->cub.texW_path,
			&vars->texW.width, &vars->texW.height);
	if (!vars->texW.img_ptr)
		safe_exit_with_error(vars, "mlx_xpm_file_to_image failed");
	vars->texW.data = (int *)mlx_get_data_addr(vars->texW.img_ptr,
			&vars->texW.bpp, &vars->texW.size_line, &vars->texW.endian);
	return (0);
}

int	init_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		safe_exit_with_error(vars, "mlx_init failed");
	load_tex(vars);
	vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!vars->win)
		safe_exit_with_error(vars, "mlx_new_window failed");
	return (0);
}
