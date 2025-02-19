#include "../../includes/cub3d.h"

void	print_map_line_len(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%zu\n", ft_strlen(map[i]));
		i++;
	}
}
int	validate_map(t_vars *vars)
{
	if (!validate_map_chars(vars->map))
		safe_exit_with_error(vars, "invalid map characters");
	vars->map_height = get_max_height(vars->map);
	trim_map_right_spaces(vars->map, vars->map_height);
	vars->map_width = get_max_width(vars->map);
	expand_map(vars);
	vars->cub.em_width = get_max_width(vars->cub.e_map);
	vars->cub.em_height = get_max_height(vars->cub.e_map);
	replace_interior_blanks(vars);
	check_map_enclosed(vars);
	check_map_connected(vars);
	apply_replace(vars);
	return (1);
}
