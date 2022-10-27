#include "parsing.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		ft_error("Invalid Args! Ex: ./cub3d map.cub\n");
	map = parsing(argv);
	if (!map)
		ft_error("Parsing Error!\n");
	printf("%d\n", map->map_w);
	printf("%d\n", map->map_h);
	return (0);
}
