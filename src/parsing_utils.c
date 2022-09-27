
#include "cub3d.h"

int	lines_nbr(char *file_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
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

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	check_new_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

int	char_inset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_map_len(t_data *p)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (p->file_content[i])
	{
		if (p->file_content[i][0] == '1'
				|| p->file_content[i][0] == ' '
				|| p->file_content[i][0] == '0')
		{
			len++;
		}
		i++;
	}
	return (len);
}
