/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:32 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:33 by azouaghi         ###   ########.fr       */
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
