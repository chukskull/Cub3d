/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:11:30 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:11:31 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_rgb(int r, int g, int b)
{
	int	color;

	color = 0;
	color = color | r << 16;
	color = color | g << 8;
	color = color | b;
	return (color);
}

static int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_extract_rgb(char **splited_colors)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (splited_colors[i])
	{
		rgb[i] = ft_atoi(splited_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255 || !ft_is_number(splited_colors[i]))
			return (-1);
		i++;
	}
	ft_free_array(splited_colors);
	return (ft_rgb(rgb[0], rgb[1], rgb[2]));
}

static int	ft_invalid_color(char *color)
{
	int	i;

	i = 0;
	if (!color)
		return (1);
	while (color[i])
	{
		if ((i == 0 || i == (int) ft_strlen(color) - 1) && color[i] == ',')
			return (1);
		if (!ft_isdigit(color[i]) && color[i] != ',')
			return (1);
		i++;
	}
	return (0);
}

int	handle_color(char *line)
{
	char	*color;
	char	**splited_colors;

	color = ft_get_second_word(line);
	if (ft_invalid_color(color))
		return (-1);
	splited_colors = ft_split(color, ',');
	if (!splited_colors || ft_array_len(splited_colors) != 3)
	{
		free(color);
		return (-1);
	}
	free(color);
	return (ft_extract_rgb(splited_colors));
}
