#include "cub3d.h"

int	get_len(char *file)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!\n");
	line = gnl(fd);
	while (line)
	{
		free(line);
		i++;
		line = gnl(fd);
	}
	close(fd);
	return (i);
}

void	get_cub_data(t_data *p)
{
	int		fd;
	int		i;
	int		line_len;

	i = 0;
	line_len = get_len(p->map.file);
	p->file_cont = malloc(sizeof(char *) * (line_len + 1));
	if (!p->file_cont)
		ft_error("Mallocing error!\n");
	fd = open(p->map.file, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!\n");
	p->file_cont[i] = gnl(fd);
	while (p->file_cont[i] && i < line_len)
	{
		p->file_cont[i] = gnl(fd);
		i++;
	}
	close(fd);
}
