

#include "cub3d.h"

int	nbr_of_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
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

int	in_charset(char c, char *set)
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

int	get_map_len(t_data *ptr)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (ptr->file_content[i])
	{
		if (ptr->file_content[i][0] == '1'
				|| ptr->file_content[i][0] == ' '
				|| ptr->file_content[i][0] == '0')
		{
			len++;
		}
		i++;
	}
	return (len);
}
