/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:02:55 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 19:22:51 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int	ft_get_lines_count(char *file_content)
{
	int	i;
	int lines_count;
	
	i = 0;
	lines_count = 0;
	while (file_content[i])
	{
		if (file_content[i] == '\n')
				lines_count++;
		i++;
	}
	return (lines_count);
}

char	**ft_get_lines(char *file_content)
{
	char	**lines;
	int		i;
	int		j;
	int		k;
	int		line_len;

	i = 0;
	j = 0;
	lines = malloc(sizeof(char *) * (ft_get_lines_count(file_content) + 1));
	while (file_content[i])
	{
		k = 0;
		line_len = ft_get_line_len(file_content + i);
		if (line_len == 0)
		{
			lines[j++] = ft_strdup("");
			i++;
			continue ;
		}
		lines[j] = malloc(sizeof(char) * (line_len + 1));
		while (file_content[i] && file_content[i] != '\n')
		{
			lines[j][k] = file_content[i];
			i++;
			k++;
		}
		lines[j][k] = '\0';
		if (file_content[i])
			i++;
		j++;
	}
	lines[j] = NULL;
	return (lines);
}
