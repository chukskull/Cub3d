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
	map->no_tex = NULL;
	map->so_tex = NULL;
	map->ea_tex = NULL;
	map->we_tex = NULL;
	map->file = NULL;
	init_color(&map->floor_clr);
	init_color(&map->ceilling_clr);
	map->player.x = 0;
	map->player.y = 0;
}

void initial(t_data *data)
{
	int i;
	int usls;

	i = 0;
	data->file_cont = NULL;
	init_map(&data->map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data data_p;

	if (ac != 2)
		ft_error("Example: ./cub3d map.cub\n");
	check_extension(av);
	initial(&data_p);
	data_p.map.file = ft_strdup(av[1]);
	get_cub_data(&data_p);
	check_cub_data(data_p.file_cont);
}
