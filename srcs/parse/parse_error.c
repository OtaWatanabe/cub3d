#include "../../includes/cub3d.h"

void	parse_error(char *msg, t_vars *vars, int fd, char *line)
{
	if (fd != -1)
		close(fd);
	if (line)
		free(line);
	if (msg)
		printf("Error\n%s\n", msg);
	if (vars)
		free_vars(vars);
	exit(1);
}