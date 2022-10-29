#include "parsing.h"

void	ft_error(char *error)
{
	write(2, "Error:\n", 7);
	write(2, error, ft_strlen(error));
	exit(1);
}
