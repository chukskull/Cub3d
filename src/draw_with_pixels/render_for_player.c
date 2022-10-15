
#include "cub3d.h"


static void	ft_up_down_key(int key, t_data *data)
{
	int	sign;
	double	cast_x;
	double	cast_y;

	cast_x = data->player->x;
	cast_y = data->player->y;
	sign = 0;
	if (key == W)
		sign = 1;
	else if (key == S)
		sign = -1;
	cast_y -= sin(data->player->an) * 0.1 * sign;
	cast_x += cos(data->player->an) * 0.1 * sign;
	if ((data->state->map[(int)(cast_y)][(int)(cast_x)] == 0) || (data->state->map[(int)(cast_y)][(int)(cast_x)] == 2))
	{
		data->player->y = cast_y;
		data->player->x = cast_x;
	}
	
}

static void	ft_left_right_key(int key, t_data *data)
{
	int	sign;

	double	cast_x;
	double	cast_y;

	cast_x = data->player->x;
	cast_y = data->player->y;
	sign = 0;
	if (key == A)
		sign = -1;
	else if (key == D)
		sign = 1;
	cast_y -= sin(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
	cast_x -=  cos(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
	if ((data->state->map[(int)(cast_y)][(int)(cast_x)] == 0) || ((data->state->map[(int)(cast_y)][(int)(cast_x)] == 2)))
	{
		data->player->y = cast_y;
		data->player->x = cast_x;
	}
}
	

int	key_hook(int key, t_data *data)
{
	int	usls;

	usls = 0;
	if (key == 53)
		ft_exit();
	if (key != A && key != S && key != D && key != W && key != 124 && key != 123)
		return (0);
	mlx_clear_window(data->mlx, data->win);
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




