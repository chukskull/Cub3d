#include "cub3d.h"

t_player	find_wall(int **map, t_data *data, double ray_angle)
{
	t_player	horiz;
	t_player	ver;
	double	distanc_hor;
	double	distanc_ver;

	data->flagb3d = 0;

	horiz = find_wall_horiz(map, data, ray_angle);
	ver = find_wall_vert(map, data, ray_angle);
	distanc_hor = sqrt(pow(data->player->x - horiz.dx  , 2)
		+ pow(data->player->y - horiz.dy, 2));
	distanc_ver = sqrt(pow(data->player->x - ver.dx, 2) 
	+ pow(data->player->y - ver.dy, 2));
	if (distanc_hor < distanc_ver  || ver.flag == 1)
	{
		if (distanc_hor == 0)
			data->flagb3d = 1;
		horiz.zone = 1;
		return(horiz);
	}
	else
	{
		if (distanc_ver == 0)
			data->flagb3d = 1;
		horiz.zone = 2;
		return(ver);
	}
}

t_player	find_wall_horiz(int **map, t_data *data, double ray_an)
{
	t_player	horiz;
	int			count;
	int			count2;
	int			dy;
	int			dx;

	dy = data->player->y;
	dx = data->player->x;
	count = 0;
	count2 = 0;
	while(1)
	{	
		if (sin(ray_an) > 0)
			horiz.dy = -(data->player->y - ((int)data->player->y - count++));
		else
			horiz.dy = -(data->player->y - (((int)data->player->y  + 1) + count2++));
		horiz.dx = -(horiz.dy / tan(ray_an)) + data->player->x;
		dx = horiz.dx;
		horiz.dy += data->player->y;
		dy = horiz.dy;
		if (dx >= data->state->map_width || dx <= 0 || dy >= data->state->map_height || dy <= 0)
			break ;
		if ((map[dy - 1][dx] == 1 || map[dy][dx] == 1))
			break ;
	}
	return(horiz);
}

t_player	find_wall_vert(int **map, t_data *data, double ray_an)
{
	t_player	ver;
	int			count;
	int			count2;
	int			dx;
	int			dy;

	dx = data->player->x;
	dy = data->player->y;
	ver.flag = 0;
	count = 1;
	count2 = 0;
	while(1)
	{
		if (cos(ray_an) > 0)
			ver.dx = -(data->player->x - ((int)data->player->x + count++));
		else if (cos(ray_an) < 0)
			ver.dx = -(data->player->x - ((int)data->player->x - count2++));
		ver.dy = -(ver.dx * (tan(ray_an)));
		ver.dx += data->player->x;
		ver.dy += data->player->y;
		if ((ver.dy < 0 || ver.dy > data->state->map_height) )
		{
			ver.flag = 1;
			break ;
		}
		else
			ver.flag = 0;
		dx = ver.dx;
		dy = ver.dy;
		if (map[dy][dx] == 1 || map[dy][dx - 1] == 1)
			break ;
	}
	return(ver);
}
