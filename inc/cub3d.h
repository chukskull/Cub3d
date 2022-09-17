#ifndef CUB3D_H
#define CUB3D_H

#include <mlx.h>
#include <stdlib.h>

#define SQUARE 500
typedef struct s_data
{
	void *mlx;
	void *img;
	void *win;
	unsigned int *addr;
} t_data;

void fill_pixel(t_data *data, int x, int y, int color);

#endif