#include "cub3d.h"


void	draw_p(t_data *data, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i < 1)
    {
        j = 0;
        while(j < 1)
        {
            fill_pixel_2(data, j + ((SIZE) * data->player->x), i +((SIZE) * data->player->y), color);
            j++;
        }
        i++;
    }
}

void	draw_walls(t_data *wall,t_player delta,t_data *data, double x, double an)
{
	double	d_to_p;
	double	distance;
	double	correct_distance;
	double	wall_strip_h;
	int top_y;
	double x_w;

	int	bottom_y;
	int j;
	j = 0;
	x_w = (SQUARE)/ 60;
	distance = sqrt(pow(data->player->x - delta.dx, 2) + pow(data->player->y - delta.dy, 2));
	correct_distance = distance * cos(fabs(data->player->an - an));
	d_to_p = (SQUARE / 2) / tan(60 / 2);
	wall_strip_h = fabs((SIZE) / correct_distance * d_to_p);
	if (wall_strip_h > 800)
		wall_strip_h = 800;
	top_y = (SQUARE / 2) - (wall_strip_h / 2);
	bottom_y = top_y + wall_strip_h;
	int y = 0;
	while(y < (SQUARE))
	{
		if (y >= 0 && y < top_y)
		{
				fill_pixel(wall, (x) *(x_w)  , y ,0x0051afa4);
		}
		else if (y >= top_y && y <= bottom_y)
			fill_pixel(wall, (x) *(x_w)  , y,0x008151af);
		else if (y >= bottom_y && y <= SQUARE)
			fill_pixel(wall, (x) * (x_w), y, 0xbff79d);
		y++;
	}
}

void	draw_map_p(t_data *data, int init)
{
	int	r;
	int	c;
	t_data	wall;
	int usls;

	r = 0;
	c = 0;
	int map[18][18] =
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,1,0,0,0,2,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,1},
			{1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1},
			{1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1},
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		};
	while(r < 18)
		{
			c = 0;
			while(c < 18)
			{
				if (map[r][c] == 1)
					draw_square(data, c, r, 0x0074af51);
				else if (map[r][c] == 0 || map[r][c] == 2)
					draw_square(data, c, r, 0x00e5dad5);
				c++;
			}
			r++;
		}

		r = 0;
		while(r < 18)
		{
			c = 0;
			while(c < 18)
			{
				if (map[r][c] == 2 && init ==1)
					draw_player(data, c,r, 0x00ff0000);
				else if (init == 0)
					draw_p(data, 0x00ff0000);
				c++;
			}
			r++;
		}
		double an = data->player->an - (60/2 * DEGREE);
		if (an < 0 )
			an += 2 * M_PI;
		float x;
		float diff = 60.0 / 800;
		double	check;
		wall.img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		wall.addr = (unsigned int *)mlx_get_data_addr(wall.img, &usls, &usls, &usls);
		x = 0;
		while (x < 60)
		{
			float ra = x * DEGREE ;
			t_player	delta;
			check = an + ra;
			if (check > 2 * M_PI)
				check -= 2 * M_PI;
			delta = find_wall(map, data, check);
			
			draw_line(data, (SIZE) * data->player->x, 
				(SIZE) * data->player->y,
				  delta.dx * (SIZE),
				  delta.dy * (SIZE));
			draw_walls(&wall , delta, data, x, check);
			x += diff;
		}
		//draw_rays(data)
		mlx_put_image_to_window(data->mlx, data->win, wall.img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_destroy_image(data->mlx, wall.img);
		mlx_destroy_image(data->mlx, data->img);
}
