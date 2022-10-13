#include "cub3d.h"


char    *get_north(t_data *data)
{
	return(data->state->north_texture);
}

char	*get_south(t_data *data)
{
	return(data->state->south_texture);
}

char	*get_east(t_data *data)
{
	return(data->state->east_texture);
}

char	*get_west(t_data *data)
{
	return(data->state->west_texture);
}