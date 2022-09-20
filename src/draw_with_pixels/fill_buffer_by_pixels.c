#include "cub3d.h"
#include <stdio.h>


void    draw_player(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    (void)x;
    (void)y;
    data->player->x = x;
    data->player->y = y;
    while(i < 10)
    {
        j = 0;
        while(j < 10)
        {
            fill_pixel(data, j + ((SQUARE/18) * x), i +((SQUARE / 18) * y), color);
            j++;
        }
        i++;
    }
}


void    draw_square(t_data *data, int x, int y, int color)
{
    double i;
    double j;

    j = 0;
    i = 0;
    while(i < (SQUARE/ 18) - 1)
    {
        j = 0;
        while(j  < (SQUARE/ 18) - 1)
        {
            fill_pixel(data, (i + ((SQUARE/ 18))* x), (j + (((SQUARE/ 18)) *y)), color);
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