#include "cub3d.h"


void    ft_texture(t_data *wall, int x, int y, t_data *data, t_player delta, int h)
{
	int pos_wallstr;
	int xox;


	if (delta.zone == 1)
	{
		pos_wallstr = delta.dx * data->pop;
		xox = pos_wallstr % data->pop;
		// xox = scale(xox, data->pop, 0, 100);
		// printf("%d\n", xox);
		fill_pixel(wall, x, y, test_pixel(data,xox, h));
	}
	else
	{
		pos_wallstr = delta.dy * data->pop;
        xox = pos_wallstr % data->pop;
		// xox = scale(xox, 100, 0, 100);
        fill_pixel(wall, x, y, test_pixel(data,xox, h));
	}

}