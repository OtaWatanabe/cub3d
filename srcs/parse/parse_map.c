#include "../../includes/cub3d.h"

// int	is_blank_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] == ' ' || line[i] == '\t')
// 		i++;
// 	if (line[i] == '\n' || line[i] == '\0')
// 		return (1);
// 	return (0);
// }

// int	is_map_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\n')
// 			return (1);
// 		if (!is_map_char(line[i]))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// char	**add_line_to_map(char **map, char *line)
// {
// 	int		i;
// 	char	**new_map;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	new_map = ft_calloc(i + 2, sizeof(char *));
// 	for (int k = 0; k < i; k++)
// 		new_map[k] = map[k];
// 	new_map[i] = ft_strdup(line);
// 	new_map[i + 1] = NULL;
// 	free(map);
// 	return (new_map);
// }

// int	parse_map(int fd, t_vars *vars)
// {
// 	char	*line;
// 	int		i;
// 	char	*pos;

// 	vars->map = (char **)ft_calloc(1, sizeof(char *));
// 	if (!vars->map)
// 		return (1);
// 	line = get_next_line(fd);
// 	while (line && is_blank_line(line))
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	if (!line)
// 		parse_error("No map found.", vars, fd, NULL);
// 	while (line)
// 	{
// 		if (!is_map_line(line))
// 		{
// 			free(line);
// 			parse_error("Invalid map line.", vars, fd, NULL);
// 		}
// 		vars->map = add_line_to_map(vars->map, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	i = 0;
// 	while (vars->map[i])
// 	{
// 		pos = ft_strchr(vars->map[i], '\n');
// 		if (pos)
// 			*pos = '\0';
// 		i++;
// 	}
// 	return (0);
// }

int	is_blank_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		if (!is_map_char(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	**add_line_to_map(t_vars *vars, char **map, char *line, int fd)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = ft_calloc(i + 2, sizeof(char *));
	if (!new_map)
		parse_error("Failed to allocate memory for new map.", vars, fd, NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
		parse_error("Failed to duplicate map line.", vars, fd, NULL);
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

char	*skip_blank_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && is_blank_line(line))
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	read_map_lines(int fd, t_vars *vars)
{
	char	*line;

	vars->map = ft_calloc(1, sizeof(char *));
	if (!vars->map)
		parse_error("Failed to allocate memory for map.", vars, fd, NULL);
	line = skip_blank_lines(fd);
	if (!line)
		parse_error("No map found.", vars, fd, NULL);
	while (line)
	{
		if (!is_map_line(line))
		{
			free(line);
			parse_error("Invalid map line.", vars, fd, NULL);
		}
		vars->map = add_line_to_map(vars, vars->map, line, fd);
		if (!vars->map)
			parse_error("Failed to add line to map.", vars, fd, line);
		free(line);
		line = get_next_line(fd);
	}
}

void	trim_map_newlines(char **map)
{
	int		i;
	char	*pos;

	i = 0;
	while (map[i])
	{
		pos = ft_strchr(map[i], '\n');
		if (pos)
			*pos = '\0';
		i++;
	}
}

int	parse_map(int fd, t_vars *vars)
{
	read_map_lines(fd, vars);
	trim_map_newlines(vars->map);
	return (0);
}
