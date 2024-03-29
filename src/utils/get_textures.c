/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:43 by snagat          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:44 by snagat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
