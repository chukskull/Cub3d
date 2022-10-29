
#include "cub3d.h"

char	*get_north(t_data *data)
{
	return (data->map->north_texture);
}

char	*get_south(t_data *data)
{
	return (data->map->south_texture);
}

char	*get_east(t_data *data)
{
	return (data->map->east_texture);
}

char	*get_west(t_data *data)
{
	return (data->map->west_texture);
}
