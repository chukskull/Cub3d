#include "cub3d.h"

int	get_no_width(t_data *data)
{
	return(data->texture->no_width);
}

int	get_so_width(t_data *data)
{
	return(data->texture->sou_width);
}

int	get_we_width(t_data *data)
{
	return(data->texture->west_width);
}

int	get_ea_width(t_data *data)
{
	return(data->texture->ea_width);
}
