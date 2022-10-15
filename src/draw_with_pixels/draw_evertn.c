#include "cub3d.h"

void	draw_everything(t_data *data, int **map, t_data *wall)
{
		t_ray		ray;
		t_player	delta;
		double		an_beg;

		an_beg = data->player->an - (60/2 * DEGREE);
		wall->img = mlx_new_image(data->mlx, WIDTH , HEIGHT);
		wall->addr = (unsigned int *)mlx_get_data_addr(wall->img, &data->usls, &data->usls, &data->usls);
		ray.x = 0;
		while (ray.x < 60)
		{
			ray.an = an_beg + (ray.x * DEGREE);
			if (ray.an > 2 * M_PI)
				ray.an -= 2 * M_PI;
			delta = find_wall(map, data, ray.an);
			draw_walls(wall , delta, data, &ray); 
			ray.x += 59.0 / WIDTH;
		}
}
