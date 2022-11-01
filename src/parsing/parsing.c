/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:13:16 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:15:59 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*get_map_data(char *file)
{
	int		fd;
	char	*map_content;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("the file couldn't be opened\n");
	map_content = ft_strdup("");
	line = gnl(fd);
	while (line)
	{
		map_content = ft_strjoin(map_content, line);
		if (!map_content)
			ft_error("The file is empty!");
		free(line);
		line = gnl(fd);
	}
	return (close(fd), map_content);
}

t_map	*parsing(char *argv)
{
	t_map	*map;
	char	*map_content;

	if (check_extension(&argv[1], ".cub") == 1)
		ft_error("Wrong file extension, use .cub\n");
	map_content = get_map_data(&argv[0]);
	if (!map_content)
		ft_error("Invalid or Empty File\n");
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error("Parsing error!\n");
	ft_parse_map(map_content, map);
	free(map_content);
	return (map);
}
