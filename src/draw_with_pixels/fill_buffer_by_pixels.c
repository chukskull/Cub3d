#include "cub3d.h"
#include <stdio.h>

void fill_pixel(t_data *data, int x, int y, int color)
{
	unsigned int *pi;
	
	pi = data->addr + (y * WIDTH) + x;
	*pi = color;
}

int	test_pixel(int x, int y, int width, unsigned int *addr)
{
	unsigned int	*pi;

	pi = addr + (y * width) + x;
	return (*pi);
}



// void fill_pixel_test(t_data *data, int x, int y, int color)
// {
// 	 unsigned int *pi;
// 	int i;
// 	int j;


// 	pi = data->addr + (y * WIDTH) + x;
// 	*pi = color;
// }

