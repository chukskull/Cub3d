#include "cub3d.h"


void    ft_texture(t_data *wall, int x, int y, t_data *data, t_player delta, int h, int	width, unsigned int *addr)
{
	int pos_wallstr;
	int xox;

	if (delta.zone == 1)
	{
		pos_wallstr = delta.dx * width;
		xox = pos_wallstr % width;
		fill_pixel(wall, x, y, test_pixel(xox, h, width, addr));
	}
	else
	{
		pos_wallstr = delta.dy * width;
        xox = pos_wallstr % width;
		//mlx problem ;##### ???
		if (h == data->texture->ea_height)
			h = data->texture->ea_height - 1;
        fill_pixel(wall, x, y, test_pixel(xox, h, width, addr));
	}

}