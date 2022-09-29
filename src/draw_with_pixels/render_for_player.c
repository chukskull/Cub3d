
#include "cub3d.h"


void	ft_up_down_key(int key, t_data *data, int usls)
{
	int	sign;

	sign = 0;
	if (key == W)
		sign = 1;
	else if (key == S)
		sign = -1;
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	data->player->y -= sin(data->player->an) * 0.3 * sign;
	data->player->x += cos(data->player->an) * 0.3 * sign;
	draw_map_p(data, 0);
}

void	ft_left_right_key(int key, t_data *data, int usls)
{
	int	sign;

	sign = 0;
	if (key == A)
		sign = 1;
	else if (key == D)
		sign = -1;
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	data->player->y -= sin(PI - (PI/2) - data->player->an)  * 0.3 * sign;
	data->player->x -= cos(PI - (PI/2) - data->player->an)  * 0.3 * sign;
	draw_map_p(data, 0);
}

int	key_hook(int key, t_data *data)
{
	int	usls;

	usls = 0;

	ft_up_down_key(key, data, usls);
	ft_left_right_key(key, data, usls);
 	if (key == 124)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->an -= DEGREE * 4;
		if (data->player->an < 0)
			data->player->an += M_PI *2;
		draw_map_p(data, 0);
	}
	else if (key == 123)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
		data->player->an += DEGREE * 4;
		if (data->player->an > M_PI * 2)
			data->player->an -= M_PI *2;
		draw_map_p(data, 0);
	}
	return(0);
}




