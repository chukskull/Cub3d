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
	while(r < data->state->map_height)
		{
			c = 0;
			while(c < data->state->map_width)
			{
				if (data->state->map[r][c] == WALL)
					draw_square(data, c, r, 0x0074af51);
				else if (data->state->map[r][c] == EMPTY || data->state->map[r][c] == PLAYER)
					draw_square(data, c, r, 0x00e5dad5);
				c++;
			}
			r++;
		}
		r = 0;
		while(r < data->state->map_height)
		{
			c = 0;
			while(c < data->state->map_width)
			{
				if (data->state->map[r][c] == PLAYER && init == 1)
					draw_player(data, c,r, 0x00ff0000);
				else if (init == 0)
					draw_p(data, 0x00ff0000);
				c++;
			}
			r++;
		}
		draw_everything(data, data->state->map, &wall);
		mlx_put_image_to_window(data->mlx, data->win, wall.img, 0, 0);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_destroy_image(data->mlx, wall.img);
		mlx_destroy_image(data->mlx, data->img);
}
