#include "cub3d.h"

char	*gnl(int fd)
{
	char	line[10000000];
	char	buff;
	int		i;

	i = 0;
	while (read(fd, &buff, 1) == 1)
	{
		line[i++] = buff;
		if (buff == '\n')
			break ;
	}
	line[i] = '\0';
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
