/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:09:26 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:50:25 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"
#include "parsing.h"

static	void	direc(int key, t_data *data)
{
	if (key == LEFT)
	{
		data->button.flag = 1;
		data->button.tour_left = -1;
	}
	else if (key == RIGHT)
	{
		data->button.flag = 1;
		data->button.tour_right = 1;
	}
	else if (key == 53)
		exit(1);
}

int	func(int key, t_data *data)
{
	data->button.flag = 0;
	if (key == A)
	{
		data->button.flag = 1;
		data->button.left = -1;
	}
	else if (key == D)
	{
		data->button.flag = 1;
		data->button.right = 1;
	}
	else if (key == S)
	{
		data->button.flag = 1;
		data->button.down = -1;
	}
	else if (key == W)
	{
		data->button.flag = 1;
		data->button.up = 1;
	}
	direc(key, data);
	return (1);
}

int	func2(int key, t_data *data)
{
	if (key == A)
		data->button.left = 0;
	else if (key == D)
		data->button.right = 0;
	else if (key == S)
		data->button.down = 0;
	else if (key == W)
		data->button.up = 0;
	else if (key == LEFT)
		data->button.tour_left = 0;
	else if (key == RIGHT)
		data->button.tour_right = 0;
	return (1);
}
