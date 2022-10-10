#include "cub3d.h"

void	draw_walls(t_data *wall,t_player delta,t_data *data,t_ray *ray)
{
	double	distance;
	double	correct_distance;
	double	x_w;
	double	len;
	t_wall	wall_info;

	x_w = (WIDTH)/ 60.0;
	distance = sqrt(pow(data->player->x - delta.dx, 2) + pow(data->player->y - delta.dy, 2));
	correct_distance =(distance) * fabs(cos((data->player->an - ray->an)));
	wall_info.wall_h = HEIGHT / (correct_distance);
	len = wall_info.wall_h;
	if (len > HEIGHT)
		len = HEIGHT;
	wall_info.top_y = (HEIGHT - wall_info.wall_h) / 2;
	wall_info.bottom_y = wall_info.top_y + wall_info.wall_h;
	ray->y = 0;
	while(ray->y < (HEIGHT))
	{
		if (ray->y < wall_info.top_y)
			fill_pixel(wall, (ray->x) * x_w, ray->y ,0xe486f1);
		else if (ray->y >= wall_info.top_y && ray->y <= wall_info.bottom_y)
		{
		
			if (sin(data->player->an) > 0 && delta.zone == 1)
			{
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (data->fassi2/ wall_info.wall_h),data->fassi, data->addr2);
			}
			else if (sin(data->player->an) < 0 && delta.zone == 1)
			{
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (data->kozina2/ wall_info.wall_h), data->kozina, data->addr5);
			}
			else if (cos(data->player->an) > 0)
			{
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (data->pop2/ wall_info.wall_h), data->pop,data->addr4);
			}
			else if (cos(data->player->an) < 0)
			{
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (data->casa2/ wall_info.wall_h),data->casa,  data->addr3);
			}

		}
		else if (ray->y > wall_info.bottom_y && ray->y < HEIGHT)
			fill_pixel(wall, (ray->x) * x_w, ray->y, 0x8c321f);
		ray->y++;
	}
}
