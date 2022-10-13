#include "cub3d.h"



int	get_no_height(t_data *data)
{
	return(data->texture->no_height);
}

int	get_so_height(t_data *data)
{
	return(data->texture->sou_height);
}

int	get_we_height(t_data *data)
{
	return(data->texture->west_height);
}

int	get_ea_height(t_data *data)
{
	return(data->texture->ea_height);
}
