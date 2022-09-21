#include "cub3d.h"
#include <stdio.h>



// void    draw_line(t_data *data, double Bx, double By, double Ex, double Ey)
// {
//     double  deltax;
//     double  deltay;
//     int pixels;


//     deltax = Ex - Bx;
//     deltay = Ey - By;
//     pixels = sqrt((deltax * deltax) +(deltay * deltay));
//     deltax /= pixels;  
//     deltay /= pixels; 
//     double pixelX = Bx;
//     double pixelY = By;
//     while (pixels)
//     {
//         fill_pixel(data, pixelX, pixelY, 0x00ff0000);
//         pixelX += deltax;
//         pixelY += deltay;
//         --pixels;
//     }
// }
void draw_line(t_data *data, double xB, double yB, double xA, double yA)
{

    int dx = xB - xA;
    int dy = yB - yA;

    float step = fmaxf(abs(dx),abs(dy));
    float xinc = dx/step;
    float yinc = dy/step;

    float x = xA,y = yA;

    while (step >= 0)
    {
       fill_pixel(data ,round(x),round(y),0xff3300);
        x += xinc;
        y += yinc;
        step--;
    }
}

void    draw_player(t_data *data, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    (void)x;
    (void)y;
    data->player->an = PI / 2 ;
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