/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:24 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:25 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	*get_no_add(t_data *data)
{
	return (data->texture->addr_north);
}

unsigned int	*get_so_add(t_data *data)
{
	return (data->texture->addr_south);
}

unsigned int	*get_we_add(t_data *data)
{
	return (data->texture->addr_west);
}

unsigned int	*get_ea_add(t_data *data)
{
	return (data->texture->addr_east);
}
