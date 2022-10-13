/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_newlines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:19:54 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/13 15:01:09 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_get_line(char *file_content)
{
	int		i;
	char	*line;

	i = 0;
	while (file_content[i] && file_content[i] != '\n')
		i++;
	line = ft_substr(file_content, 0, i + 1);
	if (!line)
		ft_exit_error("Error", 1);
	return (line);
}

static int	ft_line_is_texture_color(char *line)
{
	char	*first_word;

	first_word = ft_get_first_word(line);
	if (!first_word)
		return (0);
	if (!ft_strcmp(first_word, "NO") || !ft_strcmp(first_word, "SO")
		|| !ft_strcmp(first_word, "WE") || !ft_strcmp(first_word, "EA")
		|| !ft_strcmp(first_word, "F") || !ft_strcmp(first_word, "C"))
	{
		free(first_word);
		return (1);
	}
	free(first_word);
	return (0);
}

static void	ft_skip_textures_colors(char *file_content, int *i, int *right_lines)
{
	char	*line;

	while (file_content[*i])
	{
		line = ft_get_line(file_content + *i);
		if (ft_line_is_texture_color(line))
			(*right_lines)++;
		*i += ft_strlen(line);
		free(line);
		if (*right_lines == 6)
			break ;
	}
}

static void	ft_skip_map(char *file_content, int *i)
{
	char	*line;

	if (!file_content || !file_content[*i])
		ft_exit_error("Error", 1);
	while (file_content[*i])
	{
		line = ft_get_line(file_content + *i);
		if (!ft_strcmp(line, "\n"))
		{
			free(line);
			break ;
		}
		*i += ft_strlen(line);
		free(line);
	}
}

void	ft_check_newlines(char *file_content)
{
	int		right_lines;
	int		i;

	i = 0;
	right_lines = 0;
	// skip through textures and colors
	ft_skip_textures_colors(file_content, &i, &right_lines);
	// skip through new lines
	while (file_content[i] && file_content[i] == '\n')
		i++;
	// go through map till you reach \n or eof
	ft_skip_map(file_content, &i);
	// check if there is more content
	while (file_content[i] && file_content[i] == '\n')
		i++;
	if (file_content[i])
		ft_exit_error("Error", 1);
}
