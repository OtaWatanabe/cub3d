#include "../../includes/cub3d.h"

void	init_vars(t_vars *vars, char *argv1)
{
	vars->floor_color = -1;
	vars->ceiling_color = -1;
	vars->cub.tex_n_path = NULL;
	vars->cub.tex_s_path = NULL;
	vars->cub.tex_w_path = NULL;
	vars->cub.tex_e_path = NULL;
	vars->cub.e_map = NULL;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->tex_n.img_ptr = NULL;
	vars->tex_s.img_ptr = NULL;
	vars->tex_w.img_ptr = NULL;
	vars->tex_e.img_ptr = NULL;
	vars->frame.img_ptr = NULL;
	vars->frame.data = NULL;
	vars->keys.w = 0;
	vars->keys.s = 0;
	vars->keys.a = 0;
	vars->keys.d = 0;
	vars->keys.left = 0;
	vars->keys.right = 0;
	vars->cub.visited = NULL;
}
