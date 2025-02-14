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
	if (!is_xpm_extension(vars->cub.tex_n_path)
		|| !is_xpm_extension(vars->cub.tex_s_path)
		|| !is_xpm_extension(vars->cub.tex_w_path)
		|| !is_xpm_extension(vars->cub.tex_e_path))
	{
		return (1);
	}
	return (0);
}

int	tex_path_color_parsed(t_vars *vars)
{
	if (vars->cub.tex_n_path && vars->cub.tex_s_path && vars->cub.tex_w_path
		&& vars->cub.tex_e_path && vars->floor_color >= 0
		&& vars->ceiling_color >= 0)
	{
		return (1);
	}
	return (0);
}

// スペースを飛ばす
int	skip_spaces(const char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

// 東西南北の識別子のあとにスペースが来なければエラーを返す。
void	check_tex_path_format(char *line, int i, t_vars *vars, int fd)
{
	if (line[i + 2] != ' ' && line[i + 2] != '\t')
		parse_error("Invalid line in the .cub file.", vars, fd, line);
}
