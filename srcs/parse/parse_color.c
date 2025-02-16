/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:34:16 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 13:52:30 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	parse_rgb(char **rgb)
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

static int	count_comma(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

static int	rgb_to_int(char *line)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	if (count_comma(line) != 2)
		return (-1);
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

void	parse_color(char *line, char c, t_vars *vars, int fd)
{
	int	i;

	i = skip_spaces_count(line);
	if (line[i] != c)
		parse_error("Invalid line in the .cub file.", vars, fd, line);
	if (vars->floor_color >= 0 && c == 'F')
		parse_error("Floor color is duplicated.", vars, fd, line);
	if (vars->ceiling_color >= 0 && c == 'C')
		parse_error("Ceiling color is duplicated.", vars, fd, line);
	if (c == 'F')
	{
		vars->floor_color = rgb_to_int(line + i);
		if (vars->floor_color == -1)
			parse_error("Invalid color in the .cub file.", vars, fd, line);
	}
	else if (c == 'C')
	{
		vars->ceiling_color = rgb_to_int(line + i);
		if (vars->ceiling_color == -1)
			parse_error("Invalid color in the .cub file.", vars, fd, line);
	}
	else
		parse_error("Invalid line in the .cub file.", vars, fd, line);
}
