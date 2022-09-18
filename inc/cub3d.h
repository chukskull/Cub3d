#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

#define SQUARE 800
typedef struct s_data
{
	void *mlx;
	void *img;
	void *win;
	unsigned int *addr;
} t_data;

void fill_pixel(t_data *data, int x, int y, int color);
void    draw_square(t_data *data, int x, int y, int color);
void    draw_mini_square(t_data *data, int x, int y, int color);


#endif