#include "cub3d.h"

double	scale(double val, double max, double range, double range2)
{
	double	r_1;
	double	r_2;

	r_1 = max;
	r_2 = range - range2;
	return (range2 + (val * (r_2 / r_1)));
}

void initial(t_data *data)
{
	int usls;
	int i;

	i = 0;

	usls = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	data->img = mlx_new_image(data->mlx, SQUARE_M, SQUARE_M);
	data->addr = (unsigned int *)mlx_get_data_addr(data->img, &usls, &usls, &usls);
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->img2 = mlx_xpm_file_to_image(data->mlx, "/Users/snagat/Desktop/42-cube3d/src/images/New-Project.xpm", &usls, &usls);
	data->addr2 =  (unsigned int *)mlx_get_data_addr(data->img2, &usls, &usls, &usls);
	 draw_map_p(data, 1);
	// while(i  < 64)
	// {
	// 	int j = 0;
	// 	while(j < 64)
	// 	{
	// 		fill_pixel_2(data, i, j, test_pixel(data, i,j));
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 02, 1L<<0, key_hook, data);
	mlx_loop(data->mlx);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data *data;

	data = malloc(sizeof(t_data));
	data->player = malloc(sizeof(t_player));
	initial(data);
}