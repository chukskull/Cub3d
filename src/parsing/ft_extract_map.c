/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:40:39 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/12 17:28:25 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int	ft_invalid_char(char c)
{
	return (c != '0' && c != '1' && c != ' ' && !ft_char_is_player(c));
}

static int	ft_invalid_map_line(char **file_content, int line_index)
{
	int	i;

printf("line: |%s| - has %zu chars\n", file_content[line_index], ft_strlen(file_content[line_index]));
	if (ft_strlen(file_content[line_index]) == 0
		|| has_no_ones(file_content[line_index]))
		return (1);
	i = 0;
	while (file_content[line_index][i])
	{
		if (ft_invalid_char(file_content[line_index][i])
			|| ft_invalid_surroundings(file_content, line_index, i)
		)
		{
			printf("invalid character, or misplacement of char at line %d, char %d, (%c)", line_index, i, file_content[line_index][i]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_correct_map(char **file_content, int lines_len)
{
	int	i;
	int	player_found;

	i = 0;
	player_found = 0;
	while (i < lines_len)
	{
		if (ft_invalid_map_line(file_content, i))
			ft_exit_error("Error", EXIT_FAILURE);
		if (ft_found_player(file_content[i]))
		{
			if (player_found)
			{
				printf("multiple players found");
				ft_exit_error("Error", EXIT_FAILURE);
			}
			player_found = 1;
		}
		i++;
	}
	if (!player_found)
	{
		printf("no player found");
		ft_exit_error("Error", EXIT_FAILURE);
	}
	return (1);
}

void	ft_extract_map(char **file_content, int lines_len, t_state *state)
{
	if (!file_content || !file_content[0] || lines_len <= 1)
		ft_exit_error("Error", EXIT_FAILURE);
	ft_check_correct_map(file_content, lines_len);
	printf("map is valid\n");
	state->map_width = ft_get_map_width(file_content, lines_len);
	state->map_height = lines_len;
	printf("map width: %d, map height: %d\n", state->map_width, state->map_height);
	ft_fill_map(file_content, state);
	ft_print_map(state);
	printf("player is looking at: %c\n", state->player_angle);
	printf("north	texture: |%s|\n", state->north_texture);
	printf("south	texture: |%s|\n", state->south_texture);
	printf("east	texture: |%s|\n", state->east_texture);
	printf("west	texture: |%s|\n", state->west_texture);
	printf("floor	color: |%d|\n", state->floor_color);
	printf("ceiling	color: |%d|\n", state->ceiling_color);
}
