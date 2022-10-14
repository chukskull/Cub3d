
#include "cub3d.h"


static void	ft_up_down_key(int key, t_data *data)
{
	int	sign;
	double	cast_x;
	double	cast_y;
	double	addition_y;
	double	addition_x;

	cast_x = data->player->x;
	cast_y = data->player->y;
	addition_y = data->player->x;
	addition_x = data->player->y;
	sign = 0;
	if (key == W)
		sign = 1;
	else if (key == S)
		sign = -1;
	addition_y -= sin(data->player->an) * 0.1 * sign;
	addition_x += cos(data->player->an) * 0.1 * sign;
		printf("1\n");
	while (cast_x < addition_x || cast_y < addition_y)
	{
		cast_x += 0.01;
		cast_y += 0.01;
		if (data->state->map[(int)(cast_y)][(int)(cast_x)] == 1)
			return;
	}
	data->player->y -= cast_y;
	data->player->x += cast_x;
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
	if ((data->state->map[(int)cast_y][(int)cast_x] == 0 || data->state->map[(int)cast_y][(int)cast_x] == 2) && data->flagb3d == 0)
	{
		data->player->y -= sin(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
		data->player->x -=  cos(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
	}
}
	

int	key_hook(int key, t_data *data)
{
	int	usls;

	usls = 0;
	if (key != A && key != S && key != D && key != W && key != 124 && key != 123)
		return (0);
	mlx_clear_window(data->mlx, data->win);
	puts("1");
	ft_up_down_key(key, data);
	puts("2");
	ft_left_right_key(key, data);
	puts("3");
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




