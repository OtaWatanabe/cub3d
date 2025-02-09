#include "../../includes/cub3d.h"

// int	parse_tex_path(char *line, char *dir, t_vars *vars, int fd)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (line[i + 2] != ' ' && line[i + 2] != '\t')
// 		parse_error("Invalid line in the .cub file.", vars, fd, line);
// 	if (ft_strncmp(dir, "NO", 2) == 0 && vars->cub.texN_path)
// 		parse_error("NO texture path is duplicated.", vars, fd, line);
// 	if (ft_strncmp(dir, "SO", 2) == 0 && vars->cub.texS_path)
// 		parse_error("SO texture path is duplicated.", vars, fd, line);
// 	if (ft_strncmp(dir, "WE", 2) == 0 && vars->cub.texW_path)
// 		parse_error("WE texture path is duplicated.", vars, fd, line);
// 	if (ft_strncmp(dir, "NO", 2) == 0)
// 		vars->cub.texN_path = remove_spaces_tabs_newlines(line + i + 2);
// 	else if (ft_strncmp(dir, "SO", 2) == 0)
// 		vars->cub.texS_path = remove_spaces_tabs_newlines(line + i + 2);
// 	else if (ft_strncmp(dir, "WE", 2) == 0)
// 		vars->cub.texW_path = remove_spaces_tabs_newlines(line + i + 2);
// 	else if (ft_strncmp(dir, "EA", 2) == 0)
// 		vars->cub.texE_path = remove_spaces_tabs_newlines(line + i + 2);
// 	else
// 		parse_error("Invalid line in the .cub file.", vars, fd, line);
// 	return (0);
// }

// int	parse_tex_path_color(int fd, t_vars *vars)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line && !tex_path_color_parsed(vars))
// 	{
// 		i = 0;
// 		while (line[i] == ' ' || line[i] == '\t')
// 			i++;
// 		if (ft_strncmp(line + i, "NO", 2) == 0)
// 			parse_tex_path(line + i, "NO", vars, fd);
// 		else if (ft_strncmp(line + i, "SO", 2) == 0)
// 			parse_tex_path(line + i, "SO", vars, fd);
// 		else if (ft_strncmp(line + i, "WE", 2) == 0)
// 			parse_tex_path(line + i, "WE", vars, fd);
// 		else if (ft_strncmp(line + i, "EA", 2) == 0)
// 			parse_tex_path(line + i, "EA", vars, fd);
// 		else if (line[i] == 'F')
// 			vars->floorColor = rgb_to_int(line + i);
// 		else if (line[i] == 'C')
// 			vars->ceilingColor = rgb_to_int(line + i);
// 		else if (line[i] == '1' || line[i] == '0')
// 			parse_error("Texture or color is not loaded.", vars, fd, line);
// 		else if (line[i] != '\n' && line[i] != '\0')
// 			parse_error("Invalid line in the .cub file.", vars, fd, line);
// 		free(line);
// 		if (!tex_path_color_parsed(vars))
// 			line = get_next_line(fd);
// 	}
// 	if (!tex_path_color_parsed(vars))
// 		parse_error("Texture or color is not loaded.", vars, -1, NULL);
// 	if (is_textures_xpm_extension(vars))
// 		parse_error("Invalid texture path.", vars, -1, NULL);
// 	return (0);
// }

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

// テクスチャパスが重複していないかチェックする。
void	check_duplicate_tex_path(char *dir, t_vars *vars, int fd, char *line)
{
	if (ft_strncmp(dir, "NO", 2) == 0 && vars->cub.texN_path)
		parse_error("NO texture path is duplicated.", vars, fd, line);
	if (ft_strncmp(dir, "SO", 2) == 0 && vars->cub.texS_path)
		parse_error("SO texture path is duplicated.", vars, fd, line);
	if (ft_strncmp(dir, "WE", 2) == 0 && vars->cub.texW_path)
		parse_error("WE texture path is duplicated.", vars, fd, line);
	if (ft_strncmp(dir, "EA", 2) == 0 && vars->cub.texE_path)
		parse_error("EA texture path is duplicated.", vars, fd, line);
}

void	set_tex_path_value(char *dir, char *line, int i, t_vars *vars)
{
	if (ft_strncmp(dir, "NO", 2) == 0)
		vars->cub.texN_path = remove_spaces_tabs_newlines(line + i + 2);
	else if (ft_strncmp(dir, "SO", 2) == 0)
		vars->cub.texS_path = remove_spaces_tabs_newlines(line + i + 2);
	else if (ft_strncmp(dir, "WE", 2) == 0)
		vars->cub.texW_path = remove_spaces_tabs_newlines(line + i + 2);
	else if (ft_strncmp(dir, "EA", 2) == 0)
		vars->cub.texE_path = remove_spaces_tabs_newlines(line + i + 2);
	else
		parse_error("Invalid line in the .cub file.", vars, 0, line);
}

// lineからテクスチャパスを取得して、varsに設定する。
int	parse_tex_path(char *line, char *dir, t_vars *vars, int fd)
{
	int	i;

	i = skip_spaces(line);
	check_tex_path_format(line, i, vars, fd);
	check_duplicate_tex_path(dir, vars, fd, line);
	set_tex_path_value(dir, line, i, vars);
	return (0);
}

// lineからテクスチャパスまたはカラー情報を解析する。
void	process_tex_color_line(char *line, int fd, t_vars *vars)
{
	int	i;

	i = skip_spaces(line);
	if (ft_strncmp(line + i, "NO", 2) == 0)
		parse_tex_path(line + i, "NO", vars, fd);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		parse_tex_path(line + i, "SO", vars, fd);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		parse_tex_path(line + i, "WE", vars, fd);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		parse_tex_path(line + i, "EA", vars, fd);
	else if (line[i] == 'F')
		vars->floorColor = rgb_to_int(line + i);
	else if (line[i] == 'C')
		vars->ceilingColor = rgb_to_int(line + i);
	else if (line[i] == '1' || line[i] == '0')
		parse_error("Texture or color is not loaded.", vars, fd, line);
	else if (line[i] != '\n' && line[i] != '\0')
		parse_error("Invalid line in the .cub file.", vars, fd, line);
}

int	parse_tex_path_color(int fd, t_vars *vars)
{
	char *line;

	line = get_next_line(fd);
	while (line && !tex_path_color_parsed(vars))
	{
		process_tex_color_line(line, fd, vars);
		free(line);
		if (!tex_path_color_parsed(vars))
			line = get_next_line(fd);
	}
	if (!tex_path_color_parsed(vars))
		parse_error("Texture or color is not loaded.", vars, -1, NULL);
	if (is_textures_xpm_extension(vars))
		parse_error("Invalid texture path.", vars, -1, NULL);
	return (0);
}