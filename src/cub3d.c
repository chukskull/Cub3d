#include "cub3d.h"

void initial(t_data *data)
{
	int i;
	int usls;

	i = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	while (i < SQUARE)
	{
		fill_pixel(data, i, i, 0x00FF0000);
		i++;
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