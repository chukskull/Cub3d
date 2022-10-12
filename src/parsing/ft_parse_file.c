/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:25 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/12 19:22:03 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_is_dir(char *file_name)
{
	int	fd;
	int	output;

	fd = open(file_name, O_DIRECTORY);
	output = fd != -1;
	close(fd);
	return (output);
}

static int	ft_open_file(char *filename)
{
	int	fd;

	if (!filename || ft_is_dir(filename))
		return (-1);
	fd = open(filename, O_RDONLY);
	return (fd);
}

char	*ft_parse_file(char *filename)
{
	char	*line;
	char	*content;
	int		fd;

	fd = ft_open_file(filename);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		content = ft_strjoin(content, line);
		if (!content)
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), content);
}
