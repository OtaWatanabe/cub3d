#include "../../includes/cub3d.h"

int	string_to_color_value(char *line)
{
	int	ret;
	int	i;

	if (!line || ft_strlen(line) < 1 || ft_strlen(line) > 3)
		return (-1);
	ret = 0;
	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		ret = ret * 10 + (line[i] - '0');
		i++;
	}
	if (ret < 0 || ret > 255)
		return (-1);
	return (ret);
}

int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

char	*remove_spaces_tabs_newlines(char *line)
{
	int i;
	int j;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\t' && line[j] != '\n')
		j++;
	return (ft_substr(line, i, j - i));
}