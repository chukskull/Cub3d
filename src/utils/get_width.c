/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:41:12 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 09:41:13 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_no_width(t_data *data)
{
	return (data->texture->no_width);
}

int	get_so_width(t_data *data)
{
	return (data->texture->sou_width);
}

int	get_we_width(t_data *data)
{
	return (data->texture->west_width);
}

int	get_ea_width(t_data *data)
{
	return (data->texture->ea_width);
}
