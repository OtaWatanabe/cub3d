#include "../../includes/cub3d.h"

void	free_tex_path(t_vars *vars)
{
	if (vars->cub.tex_n_path)
		free(vars->cub.tex_n_path);
	if (vars->cub.tex_s_path)
		free(vars->cub.tex_s_path);
	if (vars->cub.tex_w_path)
		free(vars->cub.tex_w_path);
	if (vars->cub.tex_e_path)
		free(vars->cub.tex_e_path);
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

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_mlx(t_vars *vars)
{
	if (vars->tex_n.img_ptr)
		mlx_destroy_image(vars->mlx, vars->tex_n.img_ptr);
	if (vars->tex_s.img_ptr)
		mlx_destroy_image(vars->mlx, vars->tex_s.img_ptr);
	if (vars->tex_w.img_ptr)
		mlx_destroy_image(vars->mlx, vars->tex_w.img_ptr);
	if (vars->tex_e.img_ptr)
		mlx_destroy_image(vars->mlx, vars->tex_e.img_ptr);
	if (vars->frame.img_ptr)
		mlx_destroy_image(vars->mlx, vars->frame.img_ptr);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
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
}
