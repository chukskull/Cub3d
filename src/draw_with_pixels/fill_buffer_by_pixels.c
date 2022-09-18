#include "cub3d.h"
#include <stdio.h>


void    draw_mini_square(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 20)
    {
        j = 0;
        while(j < 20)
        {
            fill_pixel(data, j + (30 * x), i +(60 *y), color);
            j++;
        }
        i++;
    }
}


void    draw_square(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    (void)x;
    (void)y;
    j = 0;
    i = 0;
    while(i < 50)
    {
        j = 0;
        while(j  < 50)
        {
            fill_pixel(data, i + (50 * x), j + (50 *y), color);
            j++;
        }
        i++;
    }

}

void fill_pixel(t_data *data, int x, int y, int color)
{
    unsigned int *pi;

    pi = data->addr + (y * SQUARE) + x;
    *pi = color;
}