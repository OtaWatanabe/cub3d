#include "../../includes/cub3d.h"

void init_frame(t_vars *vars)
{
    vars->frame.img_ptr = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    vars->frame.data = (int *)mlx_get_data_addr(vars->frame.img_ptr,
                                                &vars->frame.bpp,
                                                &vars->frame.size_line,
                                                &vars->frame.endian);
    vars->frame.width  = SCREEN_WIDTH;
    vars->frame.height = SCREEN_HEIGHT;
}