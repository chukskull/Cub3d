
#include "cub3d.h"

void	draw_everything(t_data *data, int **map)
{
	t_ray		ray;
	t_player	delta;
	double		an_beg;

	an_beg = data->player->an + (60 / 2 * DEGREE);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = (unsigned int *)mlx_get_data_addr(\
data->img, &data->usls, &data->usls, &data->usls);
	ray.x = 60;
	while (ray.x > 0)
	{
		ray.an = an_beg - (ray.x * DEGREE);
		delta = find_wall(map, data, ray.an);
		draw_walls(delta, data, &ray);
		ray.x -= 59.0 / WIDTH;
	}
}
