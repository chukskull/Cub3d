/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:06:31 by snagat            #+#    #+#             */
/*   Updated: 2022/10/16 10:40:02 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//d[0] == x
//d[1] == y

t_player	find_wall(int **map, t_data *data, double ray_angle)
{
	t_player	horiz;
	t_player	ver;
	double		distanc_hor;
	double		distanc_ver;

	horiz = find_wall_horiz(map, data, ray_angle);
	ver = find_wall_vert(map, data, ray_angle);
	distanc_hor = sqrt(pow(data->player->x - horiz.dx, 2)
			+ pow(data->player->y - horiz.dy, 2));
	distanc_ver = sqrt(pow(data->player->x - ver.dx, 2)
			+ pow(data->player->y - ver.dy, 2));
	if (distanc_hor < distanc_ver || ver.flag == 1)
	{
		horiz.zone = 1;
		return (horiz);
	}
	else
		return (ver);
}

static void	initial_for_horiz(int *dy, int *dx, int count[2], t_data *data)
{
	*dy = data->player->y;
	*dx = data->player->x;
	count[0] = 0;
	count[1] = 0;
}

t_player	find_wall_horiz(int **map, t_data *data, double ray_an)
{
	t_player	horiz;
	int			count[2];
	int			dy;
	int			dx;

	initial_for_horiz(&dy, &dx, count, data);
	while (1)
	{	
		if (sin(ray_an) > 0)
			horiz.dy = -(data->player->y - ((int)data->player->y - count[0]++));
		else
			horiz.dy = -(data->player->y
					- (((int)data->player->y + 1) + count[1]++));
		horiz.dx = -(horiz.dy / tan(ray_an)) + data->player->x;
		dx = horiz.dx;
		horiz.dy += data->player->y;
		dy = horiz.dy;
		if (dx >= data->map->map_w || dx <= 0
			|| dy >= data->map->map_h || dy <= 0)
			break ;
		if ((map[dy - 1][dx] == 1 || map[dy][dx] == 1))
			break ;
	}
	return (horiz);
}

static void	initial_for_vert(int count[2], int dx_y[2],
		t_player *ver, t_data *data)
{
	dx_y[0] = data->player->x;
	dx_y[1] = data->player->y;
	ver->flag = 0;
	count[0] = 1;
	count[1] = 0;
}

typedef struct s_no
{
	t_player	v;
	int			count[2];
	int			d[2];
}t_no;

t_player	find_wall_vert(int **map, t_data *data, double ray_an)
{
	t_no	c;

	initial_for_vert(c.count, c.d, &c.v, data);
	while (1)
	{
		if (cos(ray_an) > 0)
			c.v.dx = -(data->player->x - ((int)data->player->x + c.count[0]++));
		else
			c.v.dx = -(data->player->x - ((int)data->player->x - c.count[1]++));
		c.v.dy = -(c.v.dx * (tan(ray_an)));
		c.v.dx += data->player->x;
		c.v.dy += data->player->y;
		if ((c.v.dy < 0 || c.v.dy > data->map->map_h))
		{
			c.v.flag = 1;
			break ;
		}
		else
			c.v.flag = 0;
		c.d[0] = c.v.dx;
		c.d[1] = c.v.dy;
		if (map[c.d[1]][c.d[0]] == 1 || map[c.d[1]][c.d[0] - 1] == 1)
			break ;
	}
	return (c.v);
}
