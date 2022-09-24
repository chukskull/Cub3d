
#include "cub3d.h"

void	get_cub_content(t_data *ptr)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = nbr_of_lines(ptr->map.file_name);
	ptr->file_content = malloc(sizeof(char *) * (len + 1));
	if (!ptr->file_content)
		ft_puterror("Malloc Error: parser.c: 81\n");
	fd = open(ptr->map.file_name, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	ptr->file_content[i] = get_next_line(fd);
	while (i < len && ptr->file_content[i++])
		ptr->file_content[i] = get_next_line(fd);
	ptr->file_content[i] = 0;
	close(fd);
}

void	parse_map(t_data *ptr)
{
	if (check_extention(ptr->map.file_name, ".cub")
		== EXIT_FAILURE)
		ft_puterror("Wrong extention.\n");
	get_cub_content(ptr);
	check_cub_content(ptr->file_content);
}
