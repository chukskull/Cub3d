#include "cub3d.h"

void	check_extension(char **av)
{
	int i;
	
	i = 0;
	while (av[1][i])
		i++;
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u'
		|| av[1][i - 3] != 'c' || av[1][i - 4] != '.')
		ft_error("Invalid file type, use .cub!\n");
}
