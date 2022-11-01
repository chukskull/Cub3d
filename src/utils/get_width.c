/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:50 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:51 by azouaghi         ###   ########.fr       */
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
