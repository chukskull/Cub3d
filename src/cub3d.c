#include "cub3d.h"
#include "utils.h"

void	get_textures(t_data *data, int dir)
{
	if (dir == 1)
	{
		data->texture->img_north = mlx_xpm_file_to_image(data->mlx, get_north(data), &data->texture->no_width, &data->texture->no_height);
		if (!data->texture->img_north)
		{
			puts("sn1");
			ft_exit_error("Error", EXIT_FAILURE);
		}
		data->texture->addr_north = (unsigned int *)mlx_get_data_addr(data->texture->img_north, &data->usls, &data->usls, &data->usls);
	}
	else if (dir == 2)
	{
		data->texture->img_south = mlx_xpm_file_to_image(data->mlx, get_south(data), &data->texture->sou_width, &data->texture->sou_height);
		if (!data->texture->img_south)
		{
			puts("sn2");
			ft_exit_error("Error", EXIT_FAILURE);
		}
		data->texture->addr_south =  (unsigned int *)mlx_get_data_addr(data->texture->img_south, &data->usls, &data->usls, &data->usls);
	}
	else if (dir == 3)
	{
		data->texture->img_west = mlx_xpm_file_to_image(data->mlx, get_west(data), &data->texture->west_width, &data->texture->west_height);
		if (!data->texture->img_west)
		{
			puts("sn3");
			ft_exit_error("Error", EXIT_FAILURE);
		}
		data->texture->addr_west =  (unsigned int *)mlx_get_data_addr(data->texture->img_west, &data->usls, &data->usls, &data->usls);
	}
	else
	{
		data->texture->img_east= mlx_xpm_file_to_image(data->mlx, get_east(data), &data->texture->ea_width, &data->texture->ea_height);
		if (!data->texture->img_east)
		{
			puts("sn4");
			ft_exit_error("Error", EXIT_FAILURE);
		}
		data->texture->addr_east =  (unsigned int *)mlx_get_data_addr(data->texture->img_east, &data->usls, &data->usls, &data->usls);
	}
}

void initial(t_data *data)
{
	int			i;

	i = 1;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->texture = malloc(sizeof(t_texture));
	ft_memset((void *) data->texture, 0, sizeof(t_texture));
	while (i < 5)
	{
		get_textures(data, i);
		i++;
	}
	draw_map_p(data, 1);
	mlx_hook(data->win, 02, 1L<<0, key_hook, data);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	t_data	*data;
	t_state	*state;

	state = ft_parse(ac, av);
	if (!state)
		ft_exit_error("Error", 1);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->state = state;
	data->player = malloc(sizeof(t_player));
	puts("sos");
	initial(data);
	ft_free_state(state);
	return (0);
}