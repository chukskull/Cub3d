/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer_by_pixels.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:04:17 by snagat            #+#    #+#             */
/*   Updated: 2022/10/16 10:05:16 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	fill_pixel(t_data *data, int x, int y, int color)
{
	unsigned int	*pi;

	pi = data->addr + (y * WIDTH) + x;
	*pi = color;
}

int	grab_pixel(int x, int y, int width, unsigned int *addr)
{
	unsigned int	*pi;

	pi = addr + (y * width) + x;
	return (*pi);
}
