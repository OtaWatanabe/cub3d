/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:46:13 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 14:02:10 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "cub3d.h"
# include "structures.h"

// controls
int		mouse_move(int x, int y, t_vars *vars);
int		can_move(t_vars *vars, double x, double y);
void	move_player(t_vars *vars);
void	rotate_left(t_vars *vars);
void	rotate_right(t_vars *vars);
// events
int		close_window(t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
// free
void	safe_exit_with_error(t_vars *vars, char *msg);
void	free_map(char **map);
void	free_split(char **split);
void	free_vars(t_vars *vars);
// init
int		init_frame(t_vars *vars);
void	init_key_state(t_keys *keys);
int		init_mlx(t_vars *vars);
void	init_player_state(t_vars *vars);
void	init_vars(t_vars *vars);
// map
void	check_map_connected(t_vars *vars);
int		get_max_width(char **map);
int		get_max_height(char **map);
void	check_map_enclosed(t_vars *vars);
void	expand_map(t_vars *vars);
void	replace_interior_blanks(t_vars *vars);
int		is_player_char(char c);
int		is_map_char(char c);
int		validate_map_chars(char **map);
int		trim_map_right_spaces(char **map, int height);
void	apply_replace(t_vars *vars);
int		validate_map(t_vars *vars);
void	free_visited(t_vars *vars);
void	reset_visited(t_vars *vars);
void	allocate_visited(t_vars *vars);
void	init_dirs4(int dirs[4][2]);
// minimap
void	draw_player(t_vars *vars, double scale);
void	draw_minimap(t_vars *vars);
// mlx_helper
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_tex_color(t_img tex, int x, int y);
// parse
void	parse_color(char *line, char c, t_vars *vars, int fd);
int		parse_cub(char *file, t_vars *vars);
void	parse_error(char *msg, t_vars *vars, int fd, char *line);
int		is_blank_line(char *line);

int		is_map_line(char *line);
char	**add_line_to_map(t_vars *vars, char **map, char *line, int fd);
char	*skip_blank_lines(int fd);
void	read_map_lines(int fd, t_vars *vars);
void	trim_map_newlines(char **map);
int		parse_map(int fd, t_vars *vars);
void	check_tex_path_format(char *line, int i, t_vars *vars, int fd);
int		parse_tex_path_color(int fd, t_vars *vars);
int		string_to_color_value(char *line);
int		split_len(char **split);
char	*remove_spaces_tabs_newlines(char *line);
int		skip_spaces_count(const char *line);
int		tex_path_color_parsed(t_vars *vars);
int		is_textures_xpm_extension(t_vars *vars);
// render
void	clear_frame(t_vars *vars);
void	draw_wall(t_vars *vars, int x);
void	init_step_size_dist(t_vars *vars);
void	calc_using_tex(t_vars *vars);
void	calc_tex_pos(t_vars *vars);
void	draw_wall(t_vars *vars, int x);
void	draw_walls(t_vars *vars);
int		render_frame(t_vars *vars);
void	init_ray_vars(t_vars *vars, int x);
void	dda_loop(t_vars *vars);
void	calc_wall_distance_height(t_vars *vars);

#endif