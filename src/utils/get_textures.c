/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:41:24 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 12:25:27 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_north(t_data *data)
{
	return (data->state->north_texture);
}

char	*get_south(t_data *data)
{
	return (data->state->south_texture);
}

char	*get_east(t_data *data)
{
	return (data->state->east_texture);
}

char	*get_west(t_data *data)
{
	return (data->state->west_texture);
}
