/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:41:43 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 09:41:46 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_no_height(t_data *data)
{
	return (data->texture->no_height);
}

int	get_so_height(t_data *data)
{
	return (data->texture->sou_height);
}

int	get_we_height(t_data *data)
{
	return (data->texture->west_height);
}

int	get_ea_height(t_data *data)
{
	return (data->texture->ea_height);
}
