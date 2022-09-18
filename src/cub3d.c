#include "cub3d.h"

void initial(t_data *data)
{
	int i;
	int usls;

	i = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

void	check_extension(char **av)
{
	int i;
	
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u'
		|| av[1][i - 3] != 'c' || av[1][i - 4] != '.')
	{
		printf("Error: Invalid file type, use .cub!\n");
		exit(1);
	}
}

int main(int ac, char **av)
{
	t_data *data;
	int fd;
	if (ac != 2)
	{
		write(2, "Error! Example: ./cub3d map.cub\n", 32);
		exit(0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: File not found!\n");
		exit(0);
	}
	check_extension(av);
	data = malloc(sizeof(t_data));
	initial(data);
}