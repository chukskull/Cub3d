/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:10 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:16:21 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strchr_gnl(const char *s, int c)
{
	char	to_find;
	int		i;

	i = 0;
	to_find = (char) c;
	while (s[i])
	{
		if (s[i] == to_find)
			return (i);
		i++;
	}
	if (s[i] == to_find)
		return (i);
	return (-1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i++] = NULL;
	}
	free(array);
	array = NULL;
}

void	init_map(t_map *map)
{
	map->map_w = -1;
	map->map_h = -1;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->player_ang = 0;
	map->map = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
}

int	count_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

void	ft_parse_map(char *map_content, t_map *map)
{
	char	**lines;
	int		nbr_lines;
	int		skip_txt_color;

	init_map(map);
	check_newlines(map_content);
	lines = ft_split(map_content, '\n');
	if (!lines)
		ft_error("Parsing error!\n");
	nbr_lines = count_lines(lines);
	skip_txt_color = get_texts_colors(lines, nbr_lines, map);
	get_map(lines + skip_txt_color, nbr_lines - skip_txt_color, map);
	ft_free_array(lines);
}
