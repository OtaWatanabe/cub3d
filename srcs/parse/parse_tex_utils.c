#include "../../includes/cub3d.h"

int	is_xpm_extension(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (i < 4)
		return (0);
	if (path[i - 1] == 'm' && path[i - 2] == 'p' && path[i - 3] == 'x' && path[i
		- 4] == '.')
		return (1);
	return (0);
}

int	is_textures_xpm_extension(t_vars *vars)
{
	if (!is_xpm_extension(vars->cub.texN_path)
		|| !is_xpm_extension(vars->cub.texS_path)
		|| !is_xpm_extension(vars->cub.texW_path)
		|| !is_xpm_extension(vars->cub.texE_path))
	{
		return (1);
	}
	return (0);
}

int	tex_path_color_parsed(t_vars *vars)
{
	if (vars->cub.texN_path && vars->cub.texS_path && vars->cub.texW_path
		&& vars->cub.texE_path && vars->floorColor >= 0
		&& vars->ceilingColor >= 0)
	{
		return (1);
	}
	return (0);
}
