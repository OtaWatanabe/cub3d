#include "../../includes/cub3d.h"

void	free_tex_path(t_vars *vars)
{
	if (vars->cub.texN_path)
		free(vars->cub.texN_path);
	if (vars->cub.texS_path)
		free(vars->cub.texS_path);
	if (vars->cub.texW_path)
		free(vars->cub.texW_path);
	if (vars->cub.texE_path)
		free(vars->cub.texE_path);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_vars(t_vars *vars)
{
	if (!vars)
		return ;
	free_tex_path(vars);
	if (vars->cub.e_map)
	{
		free_map(vars->cub.e_map);
		vars->cub.e_map = NULL;
	}
	if (vars->map)
	{
		free_map(vars->map);
		vars->map = NULL;
	}
	if (vars->cub.visited)
	{
		free_visited(vars);
		vars->cub.visited = NULL;
	}
	if (vars->texN.img_ptr)
		mlx_destroy_image(vars->mlx, vars->texN.img_ptr);
	if (vars->texS.img_ptr)
		mlx_destroy_image(vars->mlx, vars->texS.img_ptr);
	if (vars->texW.img_ptr)
		mlx_destroy_image(vars->mlx, vars->texW.img_ptr);
	if (vars->texE.img_ptr)
		mlx_destroy_image(vars->mlx, vars->texE.img_ptr);
	if (vars->frame.img_ptr)
		mlx_destroy_image(vars->mlx, vars->frame.img_ptr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
}

void	safe_exit_with_error(t_vars *vars, char *msg)
{
	if (vars)
		free_vars(vars);
	if (msg)
		printf("Error\n%s\n", msg);
	exit(1);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}