/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_textures_colors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:32 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/16 09:45:42 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_extract_color(char *line, char *type, t_state *state)
{
	if (!ft_strcmp(type, "F"))
	{
		if (state->floor_color != -1)
			ft_exit_error("Error", EXIT_FAILURE);
		state->floor_color = ft_get_color(line);
		if (state->floor_color == -1)
			ft_exit_error("Error", EXIT_FAILURE);
	}
	else if (!ft_strcmp(type, "C"))
	{
		if (state->ceiling_color != -1)
			ft_exit_error("Error", EXIT_FAILURE);
		state->ceiling_color = ft_get_color(line);
		if (state->ceiling_color == -1)
			ft_exit_error("Error", EXIT_FAILURE);
	}
	else
		ft_exit_error("Error", EXIT_FAILURE);
}

static void	ft_check_infos(t_state *state)
{
	if (!state->north_texture || !state->south_texture
		|| !state->west_texture || !state->east_texture
		|| state->floor_color == -1 || state->ceiling_color == -1)
		ft_exit_error("Error", EXIT_FAILURE);
}

int	ft_extract_textures_colors(char **lines, int lines_count, t_state *state)
{
	char	*first_word;
	int		i;

	i = 0;
	while (i < lines_count)
	{
		first_word = ft_get_first_word(lines[i]);
		if (!first_word)
		{
			i++;
			continue ;
		}
		if (!ft_strcmp(first_word, "NO") || !ft_strcmp(first_word, "SO")
			|| !ft_strcmp(first_word, "WE") || !ft_strcmp(first_word, "EA"))
			ft_extract_texture(lines[i], first_word, state);
		else if (!ft_strcmp(first_word, "F") || !ft_strcmp(first_word, "C"))
			ft_extract_color(lines[i], first_word, state);
		else
			return (ft_check_infos(state), free(first_word), i);
		free(first_word);
		i++;
	}
	return (-1);
}
