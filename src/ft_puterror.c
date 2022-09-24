
#include "cub3d.h"

void	ft_puterror(char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
