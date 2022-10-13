#include "cub3d.h"
#include "utils.h"


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

void	draw_map_p(t_data *data, int init)
{
	int	r;
	int	c;
	t_data	wall;

	r = 0;
	c = 0;
		printf("%dmmm\n", get_no_height(data));
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
		draw_everything(data, map, &wall);
		mlx_put_image_to_window(data->mlx, data->win, wall.img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_destroy_image(data->mlx, wall.img);
		mlx_destroy_image(data->mlx, data->img);
}
