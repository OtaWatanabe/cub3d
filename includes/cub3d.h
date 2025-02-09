#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "config.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_player
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
}				t_player;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct s_keys
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			left;
	int			right;
}				t_keys;

typedef struct s_ray
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	double		perpWallDist;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	double		wallX;
	int			texX;
	double		step;
	double		texPos;
	t_img		tex_ptr;
}				t_ray;

typedef struct s_cub
{
	int			em_width;
	int			em_height;
	char		*texN_path;
	char		*texS_path;
	char		*texE_path;
	char		*texW_path;
	char		**e_map;
	int			**visited;
}				t_cub;

typedef struct s_minimap
{
	int			left;
	int			top;
	int			right;
	int			bottom;
	int			color;
	int			scale_x;
	int			scale_y;
	double		scale;
	int			px;
	int			py;
	int			ex;
	int			ey;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			e2;
	int			err;
}				t_minimap;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_img		texN;
	t_img		texS;
	t_img		texE;
	t_img		texW;
	t_img frame; // フレームバッファ用
	char		**map;
	t_keys		keys;
	int			ceilingColor;
	int			floorColor;
	t_ray		ray;
	char		*texN_path;
	char		*texS_path;
	char		*texE_path;
	char		*texW_path;
	t_cub		cub;
	int			mouse_in_window;
	int			old_x;
	char		*cub_path;
	int			map_height;
	int			map_width;
	t_minimap	minimap;
}				t_vars;

void			debug_player_move(t_vars *vars);
void			move_player(t_vars *vars);
void			rotate_left(t_vars *vars);
void			rotate_right(t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
int				get_tex_color(t_img tex, int x, int y);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			print_map(char **map);
int				load_ber(char *file, t_vars *vars);
void			init_player_state(t_vars *vars);
void			clear_frame(t_vars *vars);
void			init_step_size_dist(t_vars *vars);
void			init_ray_vars(t_vars *vars, int x);
void			dda_loop(t_vars *vars);
void			calc_wall_distance_height(t_vars *vars);
void			calc_using_tex(t_vars *vars);
void			calc_tex_pos(t_vars *vars);
void			draw_wall(t_vars *vars, int x);
void			draw_walls(t_vars *vars);
int				render_frame(t_vars *vars);
void			init_key_state(t_keys *keys);
int				init_frame(t_vars *vars);
int				init_mlx(t_vars *vars);
int				close_window(t_vars *vars);
int				get_max_width(char **map);
int				get_max_height(char **map);
void			expand_map(t_vars *vars);
int				validate_map(t_vars *vars);
int				parse_cub(char *file, t_vars *vars);
int				is_blank_line(char *line);
void			free_vars(t_vars *vars);
void			free_map(char **map);
void			init_vars(t_vars *vars, char *argv1);
int				is_map_char(char c);
void			safe_exit_with_error(t_vars *vars, char *msg);
void			parse_error(char *msg, t_vars *vars, int fd, char *line);
void			free_split(char **split);
int				string_to_color_value(char *line);
char			*remove_spaces_tabs_newlines(char *line);
int				rgb_to_int(char *line);
int				split_len(char **split);
char			*remove_spaces_tabs_newlines(char *line);
int				tex_path_color_parsed(t_vars *vars);
int				is_textures_xpm_extension(t_vars *vars);
int				parse_tex_path_color(int fd, t_vars *vars);
int				parse_map(int fd, t_vars *vars);
void			allocate_visited(t_vars *vars);
void			reset_visited(t_vars *vars);
void			free_visited(t_vars *vars);
int				validate_map(t_vars *vars);
void			check_map_connected(t_vars *vars);
int				validate_map_chars(char **map);
int				is_map_char(char c);
void			replace_enclosed_spaces_with_A(char **map, int height,
					int width);
int				validate_map_structures(char **map, int width, int height);
int				get_max_width(char **map);
int				get_max_height(char **map);
int				is_reachable_zero_player(int start_row, int start_col,
					int **visited, char **map, int height, int width);
int				check_map_spaces_enclosed(char **map, int width, int height);
void			check_map_enclosed(t_vars *vars);
int				is_player_char(char c);
int				mouse_move(int x, int y, t_vars *vars);
int				mouse_enter(t_vars *vars);
int				mouse_leave(t_vars *vars);
void			draw_minimap(t_vars *vars);
void			replace_interior_blanks(t_vars *vars);
void			draw_player(t_vars *vars, double scale);
int				trim_map_right_spaces(char **map, int height);
#endif
