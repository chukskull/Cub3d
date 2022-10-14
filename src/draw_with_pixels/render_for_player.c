
#include "cub3d.h"


static void	ft_up_down_key(int key, t_data *data)
{
	int	sign;

	sign = 0;
	if (key == W)
		sign = 1;
	else if (key == S)
		sign = -1;
	data->player->y -= sin(data->player->an) * 0.3 * sign;
	data->player->x += cos(data->player->an) * 0.3 * sign;
}

static void	ft_left_right_key(int key, t_data *data)
{
	int	sign;

	sign = 0;
	if (key == A)
		sign = -1;
	else if (key == D)
		sign = 1;
	data->player->y -= sin(PI - (PI/2) - data->player->an)  * 0.3 * sign;
	data->player->x -= cos(PI - (PI/2) - data->player->an)  * 0.3 * sign;
}

int	key_hook(int key, t_data *data)
{
	int	usls;

	usls = 0;
	if (key != A && key != S && key != D && key != W && key != 124 && key != 123)
		return (0);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE_M, SQUARE_M);
	if (!data->img)
		exit(1);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	if (!data->addr)
		exit(1);
	ft_up_down_key(key, data);
	ft_left_right_key(key, data);
 	if (key == LEFT)
	{
		data->player->an += DEGREE * 4;
		if (data->player->an < 0)
			data->player->an += M_PI *2;
	}
	else if (key == RIGHT)
	{
		data->player->an -= DEGREE * 4;
		if (data->player->an > M_PI * 2)
			data->player->an -= M_PI *2;
	}
	draw_map_p(data, 0);
	return(0);
}




