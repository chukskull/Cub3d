/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:17:45 by snagat            #+#    #+#             */
/*   Updated: 2022/10/16 12:09:00 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "utils.h"


typedef struct s_tex
{
	int				tab[2];
	int				y_so;
	int				y_no;
	int				y_we;
	int				y_ea;
	int				wdt_no;
	int				wdt_so;
	int				wdt_we;
	int				wdt_ea;
	unsigned int	*addr_no;
	unsigned int	*addr_so;
	unsigned int	*addr_we;
	unsigned int	*addr_ea;


} t_tex;

void	ft_texture(t_tex *tex, int flag, t_data *data, t_player *delta)
{
	int	pos_wallstr;
	int	xox;

	if (flag == 1)
	{
		if (delta->zone == 1)
		{
			pos_wallstr = delta->dx * tex->wdt_no;
			xox = pos_wallstr % tex->wdt_no;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_no, tex->wdt_no, tex->addr_no));
		}
		else
		{
			pos_wallstr = delta->dy * tex->wdt_no;
			xox = pos_wallstr % tex->wdt_no;
			if (tex->y_no == data->texture->ea_height)
				tex->y_no = data->texture->ea_height - 1;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_no, tex->wdt_no, tex->addr_no));
		}
	}
	if (flag == 2)
	{
		if (delta->zone == 1)
		{
			pos_wallstr = delta->dx * tex->wdt_so;
			xox = pos_wallstr % tex->wdt_so;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_so, tex->wdt_so, tex->addr_so));
		}
		else
		{
			pos_wallstr = delta->dy * tex->wdt_so;
			xox = pos_wallstr % tex->wdt_so;
			if (tex->y_so == data->texture->ea_height)
				tex->y_so = data->texture->ea_height - 1;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_so, tex->wdt_so, tex->addr_so));
		}
	}
	if (flag == 3)
	{
		if (delta->zone == 1)
		{
			pos_wallstr = delta->dx * tex->wdt_ea;
			xox = pos_wallstr % tex->wdt_ea;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_ea, tex->wdt_ea, tex->addr_ea));
		}
		else
		{
			pos_wallstr = delta->dy * tex->wdt_ea;
			xox = pos_wallstr % tex->wdt_ea;
			if (tex->y_ea == data->texture->ea_height)
				tex->y_ea = data->texture->ea_height - 1;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_ea, tex->wdt_ea, tex->addr_ea));
		}
	}
	if (flag == 4)
	{
		if (delta->zone == 1)
		{
			pos_wallstr = delta->dx * tex->wdt_we;
			xox = pos_wallstr % tex->wdt_we;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_we, tex->wdt_we, tex->addr_we));
		}
		else
		{
			pos_wallstr = delta->dy * tex->wdt_we;
			xox = pos_wallstr % tex->wdt_we;
			if (tex->y_we == data->texture->ea_height)
				tex->y_we = data->texture->ea_height - 1;
			fill_pixel(data, tex->tab[0], tex->tab[1], grab_pixel(xox, tex->y_we, tex->wdt_we, tex->addr_we));
		}
	}
}

static void	initial_texture(t_tex *cor, t_ray *ray,t_data *data, double x_w)
{
	cor->y_no = (ray->y - data->wall->top_y) * (get_no_height(data) / data->wall->wall_h);
	cor->y_so = (ray->y - data->wall->top_y) * (get_so_height(data) / data->wall->wall_h);
	cor->y_we = (ray->y - data->wall->top_y) * (get_we_height(data) / data->wall->wall_h);
	cor->y_ea = (ray->y - data->wall->top_y) * (get_ea_height(data) / data->wall->wall_h);
	cor->wdt_no = get_no_width(data);
	cor->wdt_so = get_so_width(data) ;
	cor->wdt_we = get_we_width(data) ;
	cor->wdt_ea = get_ea_width(data) ;
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
	//north
		ft_texture(&cor, 1, data, delta);
	else if (sin(ray->an) < 0 && delta->zone == 1)
	//south
		ft_texture(&cor, 2, data, delta);
	else if (cos(ray->an) >= 0)
	//east
		ft_texture(&cor, 3, data, delta);
	else if (cos(ray->an) < 0)
	//west
		ft_texture(&cor, 4, data, delta);
}

static void	draw_wall2(t_data *data, t_ray *ray,
	t_player *delta)
{
	double	x_w;

	x_w = (WIDTH)/ 60.0;
	if (ray->y < data->wall->top_y)
		fill_pixel(data, (ray->x) * x_w, ray->y ,data->state->ceiling_color);
	else if (ray->y >= data->wall->top_y && ray->y <= data->wall->bottom_y)
		ft_apply_texture(data, ray, delta, x_w);
	else if (ray->y > data->wall->bottom_y && ray->y < HEIGHT)
		fill_pixel(data, (ray->x) * x_w, ray->y, data->state->floor_color);
}

void	draw_walls(t_player delta, t_data *data, t_ray *ray)
{
	double	distance;
	double	correct_distance;
	double	len;
	t_wall	wall_info;

	distance = sqrt(pow(data->player->x - delta.dx, 2) + pow(data->player->y - delta.dy, 2));
	correct_distance =(distance) * fabs(cos((data->player->an - ray->an)));
	wall_info.wall_h = HEIGHT / (correct_distance);
	len = wall_info.wall_h;
	if (len > HEIGHT)
		len = HEIGHT;
	wall_info.top_y = (HEIGHT - wall_info.wall_h) / 2;
	wall_info.bottom_y = wall_info.top_y + wall_info.wall_h;
	ray->y = 0;
	data->wall = &wall_info;
	while(ray->y < (HEIGHT))
	{
		draw_wall2(data, ray, &delta);
		ray->y++;
	}
}
