#include "cub3d.h"
#include "utils.h"

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
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (get_no_height(data)/ wall_info.wall_h),get_no_width(data), get_no_add(data));
			else if (sin(data->player->an) < 0 && delta.zone == 1)
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (get_so_height(data)/ wall_info.wall_h), get_so_width(data), get_so_add(data));
			else if (cos(data->player->an) >= 0)
			{
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (get_ea_height(data) / wall_info.wall_h), get_ea_width(data),get_ea_add(data));
			}
			else if (cos(data->player->an) < 0)
				ft_texture(wall, (ray->x) * x_w, ray->y, data, delta,  (ray->y - wall_info.top_y) * (get_we_height(data) / wall_info.wall_h), get_we_width(data),  get_we_add(data));
		}
		else if (ray->y > wall_info.bottom_y && ray->y < HEIGHT)
			fill_pixel(wall, (ray->x) * x_w, ray->y, 0x8c321f);
		ray->y++;
	}
}
