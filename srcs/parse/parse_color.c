#include "../../includes/cub3d.h"

void	parse_rgb(char **rgb)
{
	char	*tmp;
	int		i;

	i = 0;
	while (i < 3)
	{
		tmp = remove_spaces_tabs_newlines(rgb[i]);
		free(rgb[i]);
		rgb[i] = tmp;
		i++;
	}
}

int	rgb_to_int(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(line + 2, ',');
	if (rgb == NULL)
		return (-1);
	if (split_len(rgb) != 3)
	{
		free_split(rgb);
		return (-1);
	}
	parse_rgb(rgb);
	r = string_to_color_value(rgb[0]);
	g = string_to_color_value(rgb[1]);
	b = string_to_color_value(rgb[2]);
	free_split(rgb);
	if (r == -1 || g == -1 || b == -1)
		return (-1);
	return (r << 16 | g << 8 | b);
}
