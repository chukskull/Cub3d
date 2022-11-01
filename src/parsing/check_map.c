/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:11:19 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:11:49 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_get_line(char *map_content)
{
	int		i;
	char	*line;

	i = 0;
	while (map_content[i] && map_content[i] != '\n')
		i++;
	line = ft_substr(map_content, 0, i + 1);
	if (!line)
		ft_error("Parsing error!\n");
	return (line);
}

int	is_color_or_texture(char *line)
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

void	skip_txts_clrs(char *map_content, int *i, int *lines)
{
	char	*line;

	while (map_content[*i])
	{
		line = ft_get_line(map_content + *i);
		if (is_color_or_texture(line))
			(*lines)++;
		*i += ft_strlen(line);
		free(line);
		if (*lines == 6)
			break ;
	}
}

void	ft_skip_map(char *map_content, int *i)
{
	char	*line;

	if (!map_content || !map_content[*i])
		ft_error("Error!\n");
	while (map_content[*i])
	{
		line = ft_get_line(map_content + *i);
		if (!ft_strcmp(line, "\n"))
		{
			free(line);
			break ;
		}
		*i += ft_strlen(line);
		free(line);
	}
}

void	check_newlines(char *map_content)
{
	int		lines;
	int		i;

	i = 0;
	lines = 0;
	skip_txts_clrs(map_content, &i, &lines);
	while (map_content[i] && map_content[i] == '\n')
		i++;
	ft_skip_map(map_content, &i);
	while (map_content[i] && map_content[i] == '\n')
		i++;
	if (map_content[i])
		ft_error("Parsing error!\n");
}
