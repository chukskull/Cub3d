/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:51:49 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 17:52:53 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
