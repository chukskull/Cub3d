#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	data_p;

	if (ac != 2)
		ft_error("Example: ./cub3d map.cub\n");
	data_p.map.file_name = ft_strdup(av[1]);
	parsing(&data_p);
	return (0);
}
