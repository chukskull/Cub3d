#include "cub3d.h"

void	ft_error(char* err)
{
	write(2, "Error:\n", 7);
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}
