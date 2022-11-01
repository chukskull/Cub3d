/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:10:29 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:10:30 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

void	draw_map_p(t_data *data, int init, int r, int c)
{
	while (++r < data->map->map_h)
	{
		c = -1;
		while (++c < data->map->map_w)
		{
			if (data->map->map[r][c] == PLAYER && init == 1)
			{
				if (data->map->player_ang == 'N')
					data->player->an = M_PI_2;
				else if (data->map->player_ang == 'S')
					data->player->an = 3 * M_PI / 2;
				else if (data->map->player_ang == 'W')
					data->player->an = M_PI;
				else if (data->map->player_ang == 'E')
					data->player->an = 0;
				data->player->x = c + 0.2;
				data->player->y = r + 0.2;
			}
		}
	}
	draw_everything(data, data->map->map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}
