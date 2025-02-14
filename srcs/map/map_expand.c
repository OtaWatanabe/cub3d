#include "../../includes/cub3d.h"

void	allocate_expand_map(t_vars *vars)
{
	int	i;

	vars->cub.e_map = (char **)ft_calloc(vars->map_height + 3, sizeof(char *));
	if (!vars->cub.e_map)
		safe_exit_with_error(vars,
			"failed to allocate memory for expanded map");
	i = 0;
	while (i < vars->map_height + 2)
	{
		vars->cub.e_map[i] = (char *)ft_calloc(vars->map_width + 3,
				sizeof(char));
		if (!vars->cub.e_map[i])
		{
			while (i >= 0)
				free(vars->cub.e_map[i--]);
			free(vars->cub.e_map);
			safe_exit_with_error(vars,
				"failed to allocate memory for expanded map");
		}
		i++;
	}
	vars->cub.e_map[vars->map_height + 2] = NULL;
}

void	expand_map(t_vars *vars)
{
	int	i;
	int	j;

	allocate_expand_map(vars);
	i = 0;
	while (i < vars->map_height + 2)
	{
		j = 0;
		while (j < vars->map_width + 2)
		{
			if (i == 0 || i == vars->map_height + 1 || j == 0
				|| j == vars->map_width + 1)
				vars->cub.e_map[i][j] = ' ';
			else
			{
				if (j - 1 < (int)ft_strlen(vars->map[i - 1]))
					vars->cub.e_map[i][j] = vars->map[i - 1][j - 1];
				else
					vars->cub.e_map[i][j] = ' ';
			}
			j++;
		}
		i++;
	}
	vars->cub.e_map[vars->map_height + 2] = NULL;
}
