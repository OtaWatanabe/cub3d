#include "../../includes/cub3d.h"

int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	is_map_char(char c)
{
	if (c != ' ' && c != '1' && c != '0' && !is_player_char(c) && c != '\0')
		return (0);
	return (1);
}

int	validate_map_chars(char **map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (!is_map_char(map[i][j]))
				return (0);
			if (is_player_char(map[i][j]))
				player++;
			if (player > 1)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (player == 0)
		return (0);
	return (1);
}

int	trim_map_right_spaces(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = ft_strlen(map[i]) - 1;
		while (j >= 0)
		{
			if (map[i][j] == '1')
				break ;
			if (map[i][j] == ' ')
				map[i][j] = '\0';
			j--;
		}
		i++;
	}
	return (1);
}
