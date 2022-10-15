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

void	draw_map_p(t_data *data, int init, int r, int c)
{
	t_data	wall;

	while(++r < data->state->map_height)
	{
		c = -1;
		while(++c < data->state->map_width)
		{
			if (data->state->map[r][c] == PLAYER && init == 1)
			{
				if (data->state->player_angle == 'N')
					data->player->an =  M_PI_2;
				else if (data->state->player_angle == 'S')
					data->player->an = 3 * M_PI / 2;
				else if (data->state->player_angle == 'W')
					data->player->an = M_PI;
				else if (data->state->player_angle == 'E')
					data->player->an = 0;
				data->player->x = c + 0.1;
				data->player->y = r + 0.1;
			}
		}
	}
	draw_everything(data, data->state->map, &wall);
	mlx_put_image_to_window(data->mlx, data->win, wall.img, 0, 0);
	mlx_destroy_image(data->mlx, wall.img);
}
