#include "../../includes/cub3d.h"

int	parse_cub(char *file, t_vars *vars)
{
	int fd;

	if (!ft_strnstr(file, ".cub", ft_strlen(file)))
		parse_error("Invalid file extension.", vars, -1, NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		parse_error("Failed to open .cub file.", vars, -1, NULL);
	parse_tex_path_color(fd, vars);
	parse_map(fd, vars);
	close(fd);
	return (0);
}