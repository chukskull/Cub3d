/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:53:54 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 19:46:47 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	ft_extract_rgb(char **splitted_colors)
{
	int	i;
	int	rgb[3];

	i = 0;
	while (splitted_colors[i])
	{
		rgb[i] = ft_atoi(splitted_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255 || !ft_is_number(splitted_colors[i]))
			return (-1);
		i++;
	}
	ft_free_array(splitted_colors);
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

int	ft_get_color(char *line)
{
	char	*color;
	char	**splitted_colors;

	color = ft_get_second_word(line);
	if (ft_invalid_color(color))
		return (-1);
	splitted_colors = ft_split(color, ',');
	if (!splitted_colors || ft_array_len(splitted_colors) != 3)
	{
		free(color);
		return (-1);
	}
	free(color);
	return (ft_extract_rgb(splitted_colors));
}
