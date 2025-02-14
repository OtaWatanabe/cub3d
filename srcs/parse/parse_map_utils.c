#include "../../includes/cub3d.h"

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
