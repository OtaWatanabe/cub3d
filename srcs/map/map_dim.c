#include "../../includes/cub3d.h"

int	get_max_width(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

// int	get_max_height(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	return (i);
// }
// int	get_max_height(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (map[i])
// 	{
// 		if (map[i][0] == '\0')
// 			j = i;
// 		if (j && map[i][0] != '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (i);
// }
int	get_max_height(char **map)
{
	int	i;
	int	height;

	i = 0;
	if (!map)
		return (0);
	// map 配列全体の行数をカウント
	while (map[i])
		i++;
	height = i;
	// 末尾の空行（文字列がない行）はカウントしない
	while (height > 0 && map[height - 1][0] == '\0')
		height--;
	return (height);
}
