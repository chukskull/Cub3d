
#include "cub3d.h"

void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->row = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->file_name = NULL;
	map->starting_pos = '\0';
	init_color(&map->floor_color);
	init_color(&map->ceilling_color);
	map->player.x = 0;
	map->player.y = 0;
}

void	init_game(t_data *game)
{
	init_map(&game->map);
	game->mlx = mlx_init();
	game->file_content = NULL;
	game->screen_h = 1024;
	game->screen_w = 1024;
	game->x = 0;
	ft_new_window(game);
	game->img.ptr = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->img.arr = (int *)mlx_get_data_addr(game->img.ptr, &(game->img.bpp), \
		&(game->img.len), &(game->img.endian));
}

