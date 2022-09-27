
#include "cub3d.h"

void	get_file_content(t_data *p)
{
	int	len;
	int	fd;
	int	i;

	i = 0;
	len = lines_nbr(p->map.file_name);
	p->file_content = malloc(sizeof(char *) * (len + 1));
	if (!p->file_content)
		ft_error("Mallocing Error\n");
	fd = open(p->map.file_name, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		exit(EXIT_FAILURE);
	}
	p->file_content[i] = gnl(fd);
	while (i < len && p->file_content[i++])
		p->file_content[i] = gnl(fd);
	p->file_content[i] = 0;
	close(fd);
}

void	parsing(t_data *p)
{
	if (check_extention(p->map.file_name, ".cub")
		== EXIT_FAILURE)
		ft_error("Please use .cub extention!\n");
	get_file_content(p);
	check_map_content(p->file_content);
	get_textures(p);
	get_colors(p);
	get_map(p);
	get_p_pos(&p->map);
	check_map(p->map.map);
	check_map2(p->map);
}
