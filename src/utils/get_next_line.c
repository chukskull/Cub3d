/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:03:49 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 16:03:49 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = -1;
	while (src[++i] && i < n)
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char	*ft_cut_line(char **content_ptr, char *line)
{
	char	*new_content;
	int		new_content_len;
	int		i;
	int		j;

	i = 0;
	new_content_len = ft_strlen(*content_ptr) - ft_strlen(line);
	if (new_content_len == 0)
		return (ft_free_ptr(content_ptr));
	new_content = (char *)malloc((new_content_len + 1) * sizeof(char));
	if (!new_content)
		return (ft_free_ptr(content_ptr));
	while ((*content_ptr)[i] == line[i])
		i++;
	j = 0;
	while ((*content_ptr)[i] && j < new_content_len)
	{
		new_content[j] = (*content_ptr)[i + j];
		j++;
	}
	new_content[j] = 0;
	free(*content_ptr);
	return (new_content);
}

char	*ft_first_line(char **content_ptr)
{
	char	*output;
	int		nl_index;
	int		line_len;

	nl_index = ft_strchr_gnl(*content_ptr, '\n');
	if (nl_index == -1)
		nl_index = ft_strlen(*content_ptr) - 1;
	line_len = nl_index + 1;
	output = (char *)malloc((line_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ft_strncpy(output, *content_ptr, line_len);
	*content_ptr = ft_cut_line(content_ptr, output);
	return (output);
}

char	*ft_free_ptr(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*progress;
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!progress)
		progress = ft_strdup("");
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while (read_bytes >= 0)
	{
		buffer[read_bytes] = 0;
		progress = ft_strjoin(progress, buffer);
		if (read_bytes == 0 && !progress[0])
			break ;
		if (ft_strchr_gnl(progress, '\n') > -1 || read_bytes == 0)
			return (ft_first_line(&progress));
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (ft_free_ptr(&progress));
}
