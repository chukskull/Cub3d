#include "cub3d.h"

void fill_pixel(t_data *data, int x, int y, int color)
{
    unsigned int *pi;

    pi = data->addr + (y * SQUARE) + x;
    *pi = color;
}