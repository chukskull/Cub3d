#include "cub3d.h"

double	scale(double val, double max, double range, double range2)
{
	double	r_1;
	double	r_2;

	r_1 = max;
	r_2 = range - range2;
	return (range2 + (val * (r_2 / r_1)));
}

void initial(t_data *data)
{
	int usls;
	int r = 0;
	int c = 0;

	int map[8][8] = 
		{
			{1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,1},
			{1,0,0,2,0,0,0,1},
			{1,0,0,1,0,0,0,1},
			{1,0,0,1,0,0,0,1},
			{1,0,0,1,0,0,0,1},
			{1,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1},
		};
	(void)map;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	while(r < 8)
	{
		c = 0;
		while(c < 8)
		{
			if (map[r][c] == 1)
				draw_square(data, c, r, 0x00ff0000);
			else if (map[r][c] == 0)
				draw_square(data, c, r, 0x0000000);
			else if (map[r][c] == 2)
				draw_mini_square(data, c, r, 0x00ffD100);

			c++;
		}
		r++;
	}
	
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data *data;

	data = malloc(sizeof(t_data));
	initial(data);
}