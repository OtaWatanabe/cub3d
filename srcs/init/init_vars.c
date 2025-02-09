#include "../../includes/cub3d.h"

void	init_vars(t_vars *vars, char *argv1)
{
	vars->floorColor = -1;
	vars->ceilingColor = -1;
	vars->cub.texN_path = NULL;
	vars->cub.texS_path = NULL;
	vars->cub.texW_path = NULL;
	vars->cub.texE_path = NULL;
	vars->cub.e_map = NULL;
	vars->map = NULL;
	vars->mlx = NULL;
	vars->win = NULL;
	vars->texN.img_ptr = NULL;
	vars->texS.img_ptr = NULL;
	vars->texW.img_ptr = NULL;
	vars->texE.img_ptr = NULL;
	vars->frame.img_ptr = NULL;
	vars->frame.data = NULL;
	vars->keys.w = 0;
	vars->keys.s = 0;
	vars->keys.a = 0;
	vars->keys.d = 0;
	vars->keys.left = 0;
	vars->keys.right = 0;
	vars->cub_path = argv1;
	vars->cub.visited = NULL;
}