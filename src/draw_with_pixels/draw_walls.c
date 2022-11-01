/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:10:23 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:10:24 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	ft_texture(t_tex *tex, int flag, t_data *data, t_player *delta)
{
	if (flag == 1)
		ft_texture_no(data, delta, tex);
	else if (flag == 2)
		ft_texture_so(data, delta, tex);
	else if (flag == 3)
		ft_texture_ea(data, delta, tex);
	else if (flag == 4)
		ft_texture_we(data, delta, tex);
}

static void	initial_texture(t_tex *cor, t_ray *ray, t_data *data, double x_w)
{
	cor->y_no = (ray->y - data->wall->top_y) * (get_no_height(data)
			/ data->wall->wall_h);
	cor->y_so = (ray->y - data->wall->top_y) * (get_so_height(data)
			/ data->wall->wall_h);
	cor->y_we = (ray->y - data->wall->top_y) * (get_we_height(data)
			/ data->wall->wall_h);
	cor->y_ea = (ray->y - data->wall->top_y) * (get_ea_height(data)
			/ data->wall->wall_h);
	cor->wdt_no = get_no_width(data);
	cor->wdt_so = get_so_width(data);
	cor->wdt_we = get_we_width(data);
	cor->wdt_ea = get_ea_width(data);
	cor->tab[0] = (ray->x) * x_w;
	cor->tab[1] = ray->y;
	cor->addr_ea = get_ea_add(data);
	cor->addr_no = get_no_add(data);
	cor->addr_so = get_so_add(data);
	cor->addr_we = get_we_add(data);
}

static void	ft_apply_texture(t_data *data, t_ray *ray,
		t_player *delta, double x_w)
{
	t_tex	cor;

	initial_texture(&cor, ray, data, x_w);
	if (sin(ray->an) > 0 && delta->zone == 1)
		ft_texture(&cor, 1, data, delta);
	else if (sin(ray->an) < 0 && delta->zone == 1)
		ft_texture(&cor, 2, data, delta);
	else if (cos(ray->an) >= 0)
		ft_texture(&cor, 3, data, delta);
	else if (cos(ray->an) < 0)
		ft_texture(&cor, 4, data, delta);
}

static void	draw_wall2(t_data *data, t_ray *ray,
	t_player *delta)
{
	double	x_w;

	x_w = WIDTH / 60.0;
	if (ray->y < data->wall->top_y)
		fill_pixel(data, ray->x * x_w, ray->y, data->map->ceiling_color);
	else if (ray->y >= data->wall->top_y && ray->y <= data->wall->bottom_y)
		ft_apply_texture(data, ray, delta, x_w);
	else if (ray->y > data->wall->bottom_y && ray->y < HEIGHT)
		fill_pixel(data, ray->x * x_w, ray->y, data->map->floor_color);
}

void	draw_walls(t_player delta, t_data *data, t_ray *ray)
{
	double	distance;
	double	correct_distance;
	double	len;
	t_wall	wall_info;

	distance = sqrt(pow(data->player->x - delta.dx, 2)
			+ pow(data->player->y - delta.dy, 2));
	correct_distance = distance * fabs(cos((data->player->an - ray->an)));
	wall_info.wall_h = HEIGHT / correct_distance;
	len = wall_info.wall_h;
	if (len > HEIGHT)
		len = HEIGHT;
	wall_info.top_y = (HEIGHT - wall_info.wall_h) / 2;
	wall_info.bottom_y = wall_info.top_y + wall_info.wall_h;
	ray->y = 0;
	data->wall = &wall_info;
	while (ray->y < (HEIGHT))
	{
		draw_wall2(data, ray, &delta);
		ray->y++;
	}
}
