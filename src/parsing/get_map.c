/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:35 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:12:36 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	has_no_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_invalid_line(char **map_content, int i)
{
	int	j;

	if (has_no_ones(map_content[i]))
		return (1);
	j = 0;
	while (map_content[i][j])
	{
		if (invalid_char(map_content[i][j])
			|| invalid_surroundings(map_content, i, j)
		)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_check_plus(char **map_content, int *i, int *is_end)
{
	if (ft_strlen(map_content[*i]) == 0)
	{
		*is_end = 1;
		(*i)++;
		return (1);
	}
	else if (*is_end || check_invalid_line(map_content, *i))
		ft_error("Parsing error!\n");
	return (0);
}

static int	ft_check_extra(char **map_content, int nbr_lines)
{
	int	find_player;
	int	is_end;
	int	i;

	i = 0;
	is_end = 0;
	find_player = 0;
	while (i < nbr_lines)
	{
		if (ft_check_plus(map_content, &i, &is_end))
			continue ;
		if (player_found(map_content[i]))
		{
			if (find_player)
				ft_error("Player not found!\n");
			find_player = 1;
		}
		i++;
	}
	if (!find_player)
		ft_error("Player not found!\n");
	return (1);
}

void	get_map(char **map_content, int nbr_lines, t_map *map)
{
	if (!map_content || !map_content[0] || nbr_lines <= 1)
		ft_error("Parsing error!\n");
	ft_check_extra(map_content, nbr_lines);
	map->map_w = map_width(map_content, nbr_lines);
	map->map_h = nbr_lines;
	ft_fill_map(map_content, map);
}
