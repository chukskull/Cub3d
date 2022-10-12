/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:36:10 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/11 22:33:40 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		lines[i++] = NULL;
	}
	free(lines);
	lines = NULL;
}

static int	ft_count_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	return (i);
}

static void	ft_empty_state(t_state *state)
{
	state->north_texture = NULL;
	state->south_texture = NULL;
	state->west_texture = NULL;
	state->east_texture = NULL;
	state->floor_color = -1;
	state->ceiling_color = -1;
	state->map_width = -1;
	state->map_height = -1;
	state->map = NULL;
	state->player_angle = 0;
}

void	ft_fill_state(char *filename, t_state *state)
{
	char	**lines;
	int		lines_count;
	int		skip_file_head;

	ft_empty_state(state);
	lines = ft_split(filename, '\n');
	if (!lines)
		ft_exit_error("Error", EXIT_FAILURE);
	lines_count = ft_count_lines(lines);
	skip_file_head = ft_extract_textures_colors(lines, lines_count, state);
	ft_extract_map(lines + skip_file_head, lines_count - skip_file_head, state);
	ft_free_lines(lines);
}
