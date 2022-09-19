#include "cub3d.h"

double	scale(double val, double max, double range, double range2)
{
	double	r_1;
	double	r_2;

	r_1 = max;
	r_2 = range - range2;
	return (range2 + (val * (r_2 / r_1)));
}

int	key_hook(int key, t_data *data)
{
	int	usls;

	if (key == 13)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->y +=0.3;
		draw_map_p(data, 0);
	}
	return(0);
}
void initial(t_data *data)
{
	int usls;

	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	draw_map_p(data, 1);
	//mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data *data;

	data = malloc(sizeof(t_data));
	data->player = malloc(sizeof(t_player));
	initial(data);
}