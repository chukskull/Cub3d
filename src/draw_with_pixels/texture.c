#include "cub3d.h"


void    ft_texture(t_data *wall, int x, int y, t_data *data, t_player delta, int h)
{
    int pos_wallstr;
    int xox;

    pos_wallstr = delta.dx * 64;
    xox = pos_wallstr % 64;
    fill_pixel(wall, x, y, test_pixel(data,xox, h));

}