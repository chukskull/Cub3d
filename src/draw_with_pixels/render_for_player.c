

#include "cub3d.h"

static void	ft_up_down_key(t_data *data)
{
	int		sign;
	double	cast_x = 0;
	double	cast_y = 0;

	sign = data->button.up;
	if (data->button.down)
		sign = data->button.down;
	cast_x = data->player->x;
	cast_y = data->player->y;
	cast_y -= sin(data->player->an) * 0.1 * sign;
	cast_x += cos(data->player->an) * 0.1 * sign;
	if ((data->map->map[(int)(cast_y)][(int)(cast_x)] == 0)
			|| (data->map->map[(int)(cast_y)][(int)(cast_x)] == 2))
	{
		data->player->y = cast_y;
		data->player->x = cast_x;
	}
}

static void	ft_left_right_key(t_data *data)
{
	int		sign;
	double	cast_x = 0;
	double	cast_y = 0;

	cast_x = data->player->x;
	cast_y = data->player->y;
	sign = data->button.left;
	if (data->button.right)
		sign = data->button.right;
	cast_y += sin(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
	cast_x += cos(M_PI - (M_PI_2) - data->player->an) * 0.1 * sign;
	if ((data->map->map[(int)(cast_y)][(int)(cast_x)] == 0)
			|| ((data->map->map[(int)(cast_y)][(int)(cast_x)] == 2)))
	{
		data->player->y = cast_y;
		data->player->x = cast_x;
	}
}	

int	key_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_up_down_key(data);
	ft_left_right_key(data);

	data->player->an += DEGREE * 4 * data->button.tour_left;
	if (data->player->an < 0)
		data->player->an += M_PI * 2;
	data->player->an += DEGREE * 4 * data->button.tour_right;
	if (data->player->an > M_PI * 2)
			data->player->an -= M_PI * 2;
	draw_map_p(data, 0, -1, -1);
	return (0);
}
