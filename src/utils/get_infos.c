/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:37 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:38 by azouaghi         ###   ########.fr       */
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
