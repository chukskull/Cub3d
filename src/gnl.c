
#include "cub3d.h"

char	*gnl(int fd)
{
	char	line[8000000];
	char	buf;
	int		i;

	i = 0;
	while (read(fd, &buf, 1) == 1)
	{
		line[i++] = buf;
		if (buf == '\n')
			break ;
	}
	line[i] = '\0';
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
