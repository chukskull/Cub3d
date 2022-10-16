/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:42:00 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/16 09:42:01 by olabrahm         ###   ########.fr       */
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
