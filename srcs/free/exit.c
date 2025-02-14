#include "../../includes/cub3d.h"

void	safe_exit_with_error(t_vars *vars, char *msg)
{
	if (vars)
		free_vars(vars);
	if (msg)
		printf("Error\n%s\n", msg);
	exit(1);
}
