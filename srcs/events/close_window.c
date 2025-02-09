#include "../../includes/cub3d.h"

int	close_window(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}
