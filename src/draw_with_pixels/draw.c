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
            fill_pixel(data, j + ((SIZE) * data->player->x), i +((SIZE) * data->player->y), color);
            j++;
        }
        i++;
    }
}

void	draw_walls(t_player *delta,t_data *data, double x, double an)
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
	distance = sqrt(pow(data->player->x - delta->dx, 2) + pow(data->player->y - delta->dy, 2));
	correct_distance = distance * cos(fabs(data->player->an - an));
	d_to_p = (SQUARE / 2) / tan(60 / 2);
	wall_strip_h = fabs((SIZE) / correct_distance * d_to_p);
	if (wall_strip_h > 800)
		wall_strip_h = 800;
	top_y = (SQUARE / 2) - (wall_strip_h / 2);
	bottom_y = top_y + wall_strip_h;
	while (top_y < bottom_y)
	{
		fill_pixel(data, ((x * (x_w))) , top_y,0xffff00);
		top_y++;
	}
}

void	draw_map_p(t_data *data, int init)
{
	int	r;
	int	c;

	r = 0;
	c = 0;

	int map[18][18] =
		{
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			{1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
			{1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
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
					draw_square(data, c, r, 0xB3ff0000);
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
		printf("%f\n", diff);
		double	check;
		x = 0;
		while (x < 60)
		{
			float ra = x * DEGREE ;
			t_player	*delta;
			// printf("%f cinamn \n", (an + ra));
			check = an + ra;
			if (check > 2 * M_PI)
				check -= 2 * M_PI;
			
			delta = find_wall(map, data, check);
			
			draw_line(data, (SIZE) * data->player->x, 
				(SIZE) * data->player->y,
				  delta->dx * (SIZE),
				  delta->dy * (SIZE));
			// draw_line(data, (SQUARE/18) * data->player->x, 
			draw_walls(delta, data, x, check);
			// 	(SQUARE/18) * data->player->y,
			// 	 (delta->dx + data->player->x) * (SQUARE/18),
			// 		((sin(data->player->an)*(delta->dy)) + data->player->y)  * (SQUARE/18));
			x += diff;
		}
		//draw_rays(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
