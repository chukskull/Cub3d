/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:55:54 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/15 20:53:16 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fill_line(char *line, int *buffer, int width, t_state *state)
{
	int	i;

	i = 0;
	while (line[i] && i < width)
	{
		if (line[i] == '0')
			buffer[i] = EMPTY;
		else if (line[i] == '1')
			buffer[i] = WALL;
		else if (line[i] == ' ')
			buffer[i] = NOTHING;
		else if (ft_char_is_player(line[i]))
		{
			buffer[i] = PLAYER;
			state->player_angle = line[i];
		}
		else
			ft_exit_error("Error", EXIT_FAILURE);
		i++;
	}
	while (i < width)
		buffer[i++] = NOTHING;
}

void	ft_fill_map(char **file_content, t_state *state)
{
	int	**map;
	int	i;

	map = (int **) malloc((state->map_height + 1) * sizeof(int *));
	if (!map)
		ft_exit_error("Error", EXIT_FAILURE);
	map[state->map_height] = NULL;
	i = 0;
	while (i < state->map_height)
	{
		map[i] = (int *) malloc(state->map_width * sizeof(int));
		if (!map[i])
			ft_exit_error("Error", EXIT_FAILURE);
		ft_fill_line(file_content[i], map[i], state->map_width, state);
		i++;
	}
	state->map = map;
}
