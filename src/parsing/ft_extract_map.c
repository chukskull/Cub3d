/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:40:39 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/11 22:35:56 by olabrahm         ###   ########.fr       */
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
	return (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && c != ' ');
}

static int	ft_invalid_map_line(char **file_content, int line_index)
{
	int	i;

	if (has_no_ones(file_content[line_index]))
		return (1);
	i = 0;
	while (file_content[line_index][i])
	{
		if (
			ft_invalid_char(file_content[line_index][i])
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

	i = 0;
	while (i < lines_len)
	{
		if (ft_invalid_map_line(file_content, i))
			ft_exit_error("Error", EXIT_FAILURE);
		i++;
	}
	return (1);
}

void	ft_extract_map(char **file_content, int lines_len, t_state *state)
{
	// int	map_width;
	// int	map_height;

	(void) state;
	if (!file_content || !file_content[0] || lines_len <= 1)
		ft_exit_error("Error", EXIT_FAILURE);
	ft_check_correct_map(file_content, lines_len);
	printf("map is valid\n");
	// map_width = ft_get_map_width(file_content, lines_len);
	// map_height = ft_get_map_height(file_content, lines_len);
}
