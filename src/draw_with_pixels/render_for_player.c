
#include "cub3d.h"

int	key_hook(int key, t_data *data)
{
	int	usls;

	if (key == 13)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->y -=0.3;
		draw_map_p(data, 0);
	}
	else if (key == 1)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->y +=0.3;
		draw_map_p(data, 0);
	}
	else if (key == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->x -=0.3;
		draw_map_p(data, 0);
	}
	else if (key == 2)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->x +=0.3;
		draw_map_p(data, 0);
	}
	return(0);
}