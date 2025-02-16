/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:46:10 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 14:02:13 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
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
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	t_img		tex_ptr;
}				t_ray;

typedef struct s_cub
{
	int			em_width;
	int			em_height;
	char		*tex_n_path;
	char		*tex_s_path;
	char		*tex_e_path;
	char		*tex_w_path;
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
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_img		frame;
	char		**map;
	t_keys		keys;
	int			ceiling_color;
	int			floor_color;
	t_ray		ray;
	char		*tex_n_path;
	char		*tex_s_path;
	char		*tex_e_path;
	char		*tex_w_path;
	t_cub		cub;
	int			mouse_in_window;
	int			old_x;
	int			map_height;
	int			map_width;
	int			mouse_inside;
	t_minimap	minimap;
}				t_vars;

#endif
