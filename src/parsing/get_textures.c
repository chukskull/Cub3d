#include "parsing.h"

static void	north_texture(char *line, t_map *map)
{
	if (map->north_texture)
		ft_error("NO texture Error!\n");
	map->north_texture = ft_get_second_word(line);
	printf("%s\n", map->north_texture);
	if (!map->north_texture)
		ft_error("NO texture Error!\n");
}

static void	south_texture(char *line, t_map *map)
{
	if (map->south_texture)
		ft_error("SO texture Error!\n");
	map->south_texture = ft_get_second_word(line);
	if (!map->south_texture)
		ft_error("SO texture Error!\n");
}

static void	west_texture(char *line, t_map *map)
{
	if (map->west_texture)
		ft_error("WE texture Error!\n");
	map->west_texture = ft_get_second_word(line);
	if (!map->west_texture)
		ft_error("WE texture Error!\n");
}

static void	east_texture(char *line, t_map *map)
{
	if (map->east_texture)
		ft_error("EA texture Error!\n");
	map->east_texture = ft_get_second_word(line);
	if (!map->east_texture)
		ft_error("EA texture Error!\n");
}

void	get_textures(char *line, char *type, t_map *map)
{
	if (!ft_strcmp(type, "NO"))
		north_texture(line, map);
	else if (!ft_strcmp(type, "SO"))
		south_texture(line, map);
	else if (!ft_strcmp(type, "WE"))
		west_texture(line, map);
	else if (!ft_strcmp(type, "EA"))
		east_texture(line, map);
	else
		ft_error("Texture Error!\n");
}
