#include "../../includes/cub3d.h"

int load_tex_path_bak(char *line, char *dir, t_img *tex, void *mlx)
{
    line[ft_strlen(line) - 1] = '\0';
    if (ft_strncmp(line, dir, ft_strlen(dir)) != 0)
        return (1);
    tex->img_ptr = mlx_xpm_file_to_image(mlx, line+3, &tex->width, &tex->height);
    if (!tex->img_ptr)
    {
        printf("Error: Faild load texture.\n");
        return (1);
    }
    tex->data = (int *)mlx_get_data_addr(tex->img_ptr, &tex->bpp, &tex->size_line, &tex->endian);
}

int load_tex(t_vars *vars)
{
    vars->texN.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->texN_path, &vars->texN.width, &vars->texN.height);
    if (!vars->texN.img_ptr)
        return (fprintf(stderr, "mlx_xpm_file_to_image failed\n"), 1);
    vars->texN.data = (int *)mlx_get_data_addr(vars->texN.img_ptr, &vars->texN.bpp, &vars->texN.size_line, &vars->texN.endian);
    vars->texS.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->texS_path, &vars->texS.width, &vars->texS.height);
    if (!vars->texS.img_ptr)
        return (fprintf(stderr, "mlx_xpm_file_to_image failed\n"), 1);
    vars->texS.data = (int *)mlx_get_data_addr(vars->texS.img_ptr, &vars->texS.bpp, &vars->texS.size_line, &vars->texS.endian);
    vars->texE.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->texE_path, &vars->texE.width, &vars->texE.height);
    if (!vars->texE.img_ptr)
        return (fprintf(stderr, "mlx_xpm_file_to_image failed\n"), 1);
    vars->texE.data = (int *)mlx_get_data_addr(vars->texE.img_ptr, &vars->texE.bpp, &vars->texE.size_line, &vars->texE.endian);
    vars->texW.img_ptr = mlx_xpm_file_to_image(vars->mlx, vars->texW_path, &vars->texW.width, &vars->texW.height);
    if (!vars->texW.img_ptr)
        return (fprintf(stderr, "mlx_xpm_file_to_image failed\n"), 1);
    vars->texW.data = (int *)mlx_get_data_addr(vars->texW.img_ptr, &vars->texW.bpp, &vars->texW.size_line, &vars->texW.endian);
    return (0);
}

int init_mlx(t_vars *vars)
{
    vars->mlx = mlx_init();
    if (!vars->mlx)
        return (fprintf(stderr, "mlx_init failed\n"), 1);
    load_tex(vars);
        vars->win = mlx_new_window(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
    if (!vars->win)
        return (fprintf(stderr, "mlx_new_window failed\n"), 1);

    return (0);
}
