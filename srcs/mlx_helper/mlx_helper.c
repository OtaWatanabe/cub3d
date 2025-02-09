#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	img->data[y * (img->size_line / 4) + x] = color;
}

int	get_tex_color(t_img tex, int x, int y)
{
	if (x < 0)
		x = 0;
	if (x >= tex.width)
		x = tex.width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex.height)
		y = tex.height - 1;
	return (tex.data[y * (tex.size_line / 4) + x]);
}
