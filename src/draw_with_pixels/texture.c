#include "cub3d.h"


void    ft_texture(t_data *wall, int x, int y, t_data *data, t_player delta, int h)
{
	int pos_wallstr;
	int xox;


	if (delta.zone == 1)
	{
		pos_wallstr = delta.dx * 100;
		xox = pos_wallstr % 100;
		fill_pixel(wall, x, y, test_pixel(data,xox, h));
	}
	else
	{
		pos_wallstr = delta.dy * 100;
        xox = pos_wallstr % 100;
        fill_pixel(wall, x, y, test_pixel(data,xox, h));
	}

}