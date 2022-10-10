/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_textures_colors.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:32 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 18:05:47 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    ft_extract_color(char *line, char *type, t_state *state)
{
	(void) line;
	if (!ft_strcmp(type, "F"))
	{
		if (state->floor_color != -1)
			ft_exit_error("Error - floor color already set", EXIT_FAILURE);
		state->floor_color = 1;
		printf("COLOR DETECTED - set floor color correctly.\n");
	}
	else if (!ft_strcmp(type, "C"))
	{
		if (state->ceiling_color != -1)
			ft_exit_error("Error - ceiling color already set", EXIT_FAILURE);
		state->ceiling_color = 1;
		printf("COLOR DETECTED - set floor color correctly.\n");
	}
	else
		ft_exit_error("Error - invalid color given", EXIT_FAILURE);
}

static void	ft_check_infos(t_state *state)
{
	if (!state->north_texture || !state->south_texture || !state->west_texture
		|| !state->east_texture || state->floor_color == -1 || state->ceiling_color == -1)
		ft_exit_error("Error - one of the textures or colors is missing", EXIT_FAILURE);
}

int	ft_extract_textures_colors(char **lines, int lines_count, t_state *state)
{
	char    *first_word;
	int     i;

	i = 0;
	while (i < lines_count)
	{
		first_word = ft_get_first_word(lines[i]);
		if (!first_word) continue ; // if line is empty
		if (!ft_strcmp(first_word, "NO") || !ft_strcmp(first_word, "SO") || !ft_strcmp(first_word, "WE") || !ft_strcmp(first_word, "EA"))
			ft_extract_texture(lines[i], first_word, state);
		else if (!ft_strcmp(first_word, "F") || !ft_strcmp(first_word, "C"))
			ft_extract_color(lines[i], first_word, state);
		else
		{
			// we have reached the map
			// check if we got all the needed info
			printf("MAP DETECTED - check if we got all the needed info\n");
			ft_check_infos(state);
			free(first_word);
			return (i);
		}
		free(first_word);
		i++;
	}
	return (-1);
}
