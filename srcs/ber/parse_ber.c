#include "../../includes/cub3d.h"



int load_tex_path(char *line, char *dir, t_vars *vars) {
    line[ft_strlen(line) - 1] = '\0';
    if (ft_strncmp(line, dir, ft_strlen(dir)) != 0)
        return (1);
    if (ft_strncmp(dir, "NO", 2) == 0)
        vars->texN_path = ft_strdup(line+3);
    else if (ft_strncmp(dir, "SO", 2) == 0)
        vars->texS_path = ft_strdup(line+3);
    else if (ft_strncmp(dir, "WE", 2) == 0)
        vars->texW_path = ft_strdup(line+3);
    else if (ft_strncmp(dir, "EA", 2) == 0)
        vars->texE_path = ft_strdup(line+3);
}

int string_to_color_value(char *line) {
    int ret;
    int i;

    if (!line || ft_strlen(line)  < 1 || ft_strlen(line) > 3)
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

int background_color(char *line)
{
    int r;
    int g;
    int b;
    char **rgb;

    rgb = ft_split(line+2, ',');
    if (rgb == NULL)
        return (-1);
    rgb[2][ft_strchr(rgb[2], '\n') - rgb[2]] = '\0';
    r = string_to_color_value(rgb[0]);
    g = string_to_color_value(rgb[1]);
    b = string_to_color_value(rgb[2]);
    if (r == -1 || g == -1 || b == -1)
        return (-1);
    return (r << 16 | g << 8 | b);
}

char **add_line_to_map(char **map, char *line)
{
    int i = 0;
    while (map[i])
        i++;
    char **new_map = ft_calloc(i + 2, sizeof(char *));
    for (int k = 0; k < i; k++)
        new_map[k] = map[k]; 
    new_map[i] = ft_strdup(line);
    new_map[i + 1] = NULL;
    free(map);

    return (new_map);
}


int load_map(int fd, t_vars *vars)
{
    char **map;
    char *line;
    int i = 0;

    map = (char **)ft_calloc(1, sizeof(char *));
    while ((line = get_next_line(fd)))
    {
        map = add_line_to_map(map,line);
        free(line);
    }
    vars->map = map;
    return 0;
}

void load_ber(char *file, t_vars *vars)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: Faild load ber.\n");
        exit(1);
    }
    line = get_next_line(fd);
    load_tex_path(line, "NO", vars);
    free(line);
    line = get_next_line(fd);
    load_tex_path(line, "SO", vars);
    free(line);
    line = get_next_line(fd);
    load_tex_path(line, "WE", vars);
    free(line);
    line = get_next_line(fd);
    load_tex_path(line, "EA", vars);
    free(line);
    line = get_next_line(fd);
    free(line);
    line = get_next_line(fd);
    vars->ceilingColor = background_color(line);
    free(line);
    line = get_next_line(fd);
    vars->floorColor = background_color(line);
    free(line);
    line = get_next_line(fd);
    free(line); 
    load_map(fd, vars);
}
