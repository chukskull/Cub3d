/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:04 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:13:05 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	char_is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	player_found(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (char_is_player(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	map_width(char **map_content, int nbr_lines)
{
	int	i;
	int	max;
	int	line_len;

	i = 0;
	max = 0;
	while (i < nbr_lines)
	{
		line_len = ft_strlen(map_content[i]);
		if (line_len > max)
			max = line_len;
		i++;
	}
	return (max);
}

static void	ft_fill_line(char *line, int *buff, int w, t_map *map)
{
	int	i;

	i = 0;
	while (line[i] && i < w)
	{
		if (line[i] == '0')
			buff[i] = EMPTY;
		else if (line[i] == '1')
			buff[i] = WALL;
		else if (line[i] == ' ')
			buff[i] = NO_VALUE;
		else if (char_is_player(line[i]))
		{
			buff[i] = PLAYER;
			map->player_ang = line[i];
		}
		else
			ft_error("Parsing error!\n");
		i++;
	}
	while (i < w)
		buff[i++] = NO_VALUE;
}

void	ft_fill_map(char **map_content, t_map *map)
{
	int	**map_tab;
	int	i;

	map_tab = (int **) malloc((map->map_h + 1) * sizeof(int *));
	if (!map_tab)
		ft_error("Map allocation error!\n");
	map_tab[map->map_h] = NULL;
	i = 0;
	while (i < map->map_h)
	{
		map_tab[i] = (int *) malloc(map->map_w * sizeof(int));
		if (!map_tab[i])
			ft_error("Map allocation error!\n");
		ft_fill_line(map_content[i], map_tab[i], map->map_w, map);
		i++;
	}
	map->map = map_tab;
}
