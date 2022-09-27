
#include "cub3d.h"

void	get_textures(t_data *data)
{
	char	**splited;
	int		i;

	i = 0;
	while (i < 4)
	{
		splited = ft_split(data->file_content[i++], ", \n");
		if (!splited[0])
			return ;
		if (ft_strcmp(splited[0], NORTH_TEXTURE) == EQUAL)
			data->map.north_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], SOUTH_TEXTURE) == EQUAL)
			data->map.south_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], EAST_TEXTURE) == EQUAL)
			data->map.east_texture = ft_strdup(splited[1]);
		else if (ft_strcmp(splited[0], WEST_TEXTURE) == EQUAL)
			data->map.west_texture = ft_strdup(splited[1]);
		free_split(splited);
	}
	if (open(data->map.north_texture, O_RDONLY) < 0
		|| open(data->map.south_texture, O_RDONLY) < 0
		|| open(data->map.east_texture, O_RDONLY) < 0
		|| open(data->map.west_texture, O_RDONLY) < 0)
		ft_error("Texture doesn't exist!\n");
}

void	get_rgb(t_color *color, char **str)
{
	color->r = ft_atoi(str[0]);
	color->g = ft_atoi(str[1]);
	color->b = ft_atoi(str[2]);
}

void	get_colors(t_data *p)
{
	char	**splited;
	int		i;

	i = 0;
	while (p->file_content[i])
	{
		if (p->file_content[i][0] == '1'
				|| p->file_content[i][0] == ' '
				|| p->file_content[i][0] == '0')
			break ;
		splited = ft_split(p->file_content[i++], ", \n");
		if (splited[0])
		{
			if (ft_strcmp(splited[0], FLOOR) == EQUAL)
				get_rgb(&p->map.floor_color, splited + 1);
			else if (ft_strcmp(splited[0], CEILLING) == EQUAL)
				get_rgb(&p->map.ceilling_color, splited + 1);
		}
		free_split(splited);
	}
}

void	get_map(t_data *p)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	p->map.row = get_map_len(p);
	p->map.map = malloc(sizeof(char *) * (p->map.row + 1));
	p->map.col = 0;
	if (!p->map.map)
		ft_error("Mallocing Error\n");
	while (p->file_content[i])
	{
		if (p->file_content[i][0] == '1'
				|| p->file_content[i][0] == ' '
				|| p->file_content[i][0] == '0')
		{
			p->map.map[j++] = ft_strndup(p->file_content[i],
					ft_strlen(p->file_content[i]) - \
					check_new_line(p->file_content[i]));
			if (p->map.col < ft_strlen(p->map.map[j - 1]))
				p->map.col = ft_strlen(p->map.map[j - 1]);
		}
		i++;
	}
	p->map.map[j] = 0;
}

void	get_p_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map[row])
	{
		col = 0;
		while (map->map[row][col])
		{
			if (char_inset(map->map[row][col], "NWSE"))
			{
				map->player.x = row;
				map->player.y = col;
				map->start_position = map->map[row][col];
				return ;
			}
			col++;
		}
		row++;
	}
}
