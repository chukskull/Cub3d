
#include "cub3d.h"

double	g_player_y(t_data *data)
{
	return (data->player->y);
}

double	g_player_x(t_data *data)
{
	return (data->player->x);
}

double	g_player_dy(t_data *data)
{
	return (data->player->dy);
}

double	g_player_dx(t_data *data)
{
	return (data->player->dx);
}
