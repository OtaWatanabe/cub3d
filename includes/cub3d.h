#ifndef CUB3D_H
# define CUB3D_H
#include "../minilibx-linux/mlx.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "config.h"

typedef struct s_player
{
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
}   t_player;

typedef struct s_img
{
    void    *img_ptr;
    int     *data;
    int     width;
    int     height;
    int     bpp;
    int     size_line;
    int     endian;
}   t_img;

typedef struct s_keys
{
    int w;
    int s;
    int a;
    int d;
    int left;
    int right;
}   t_keys;

typedef struct s_ray
{
    double cameraX;
    double rayDirX;
    double rayDirY;
    int mapX;
    int mapY;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    int stepX;
    int stepY;
    int hit;
    int side;
    double perpWallDist;
    int lineHeight;
    int drawStart;
    int drawEnd;
    double wallX;
    int texX;
    double step;
    double texPos;
    t_img *tex_ptr;
}   t_ray;

typedef struct s_vars
{
    void      *mlx;
    void      *win;
    t_player   player;
    t_img      texN;
    t_img      texS;
    t_img      texE;
    t_img      texW;
    t_img      frame;   // フレームバッファ用
    char      **map;
    t_keys     keys;
    int ceilingColor;
    int floorColor;
    t_ray ray;
    char *texN_path;
    char *texS_path;
    char *texE_path;
    char *texW_path;
}   t_vars;

void move_player(t_vars *vars);
void rotate_left(t_vars *vars);
void rotate_right(t_vars *vars);
int key_press(int keycode, t_vars *vars);
int key_release(int keycode, t_vars *vars);
int     get_tex_color(t_img *tex, int x, int y);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
void print_map(char **map);
void load_ber(char *file, t_vars *vars);
void init_player_state(t_vars *vars);
void clear_frame(t_vars *vars);
void init_step_size_dist(t_vars *vars);
void init_ray_vars(t_vars *vars, int x);
void dda_loop(t_vars *vars);
void calc_wall_distance_height(t_vars *vars);
void calc_using_tex(t_vars *vars);
void calc_tex_pos(t_vars *vars);
void draw_wall(t_vars *vars, int x);
void draw_walls(t_vars *vars);
int render_frame(t_vars *vars);
void init_key_state(t_keys *keys);
void init_frame(t_vars *vars);
int init_mlx(t_vars *vars);
int close_window(t_vars *vars);

#endif