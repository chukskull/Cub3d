/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texts_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:44 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:12:45 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	check_t_c(t_map *map)
{
	if (!map->north_texture || !map->south_texture
		|| !map->west_texture || !map->east_texture
		|| map->floor_color == -1 || map->ceiling_color == -1)
		ft_error("Texture or Color Error!\n");
}

static void	get_colors(char *line, char *ForC, t_map *map)
{
	if (!ft_strcmp(ForC, "C"))
	{
		if (map->ceiling_color != -1)
			ft_error("Color Error!\n");
		map->ceiling_color = handle_color(line);
		if (map->ceiling_color == -1)
			ft_error("Color Error!\n");
	}
	else if (!ft_strcmp(ForC, "F"))
	{
		if (map->floor_color != -1)
			ft_error("Color Error!\n");
		map->floor_color = handle_color(line);
		if (map->floor_color == -1)
			ft_error("Color Error!\n");
	}
	else
		ft_error("Color Error!\n");
}

int	get_texts_colors(char **lines, int nbr_lines, t_map *map)
{
	int		i;
	char	*first_word;

	i = 0;
	while (i < nbr_lines)
	{
		first_word = ft_get_first_word(lines[i]);
		if (!first_word)
		{
			i++;
			continue ;
		}
		if (!ft_strcmp(first_word, "NO") || !ft_strcmp(first_word, "SO")
			|| !ft_strcmp(first_word, "WE") || !ft_strcmp(first_word, "EA"))
			pars_get_textures(lines[i], first_word, map);
		else if (!ft_strcmp(first_word, "F") || !ft_strcmp(first_word, "C"))
			get_colors(lines[i], first_word, map);
		else
			return (check_t_c(map), free(first_word), i);
		free(first_word);
		i++;
	}
	return (-1);
}
