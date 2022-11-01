/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:12:54 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:12:55 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strncpy(char *dst, char *src, int n)
{
	int	i;

	i = -1;
	while (src[++i] && i < n)
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char	*another_line(char **content_ptr, char *line)
{
	char	*new_content;
	int		new_content_len;
	int		i;
	int		j;

	i = 0;
	new_content_len = ft_strlen(*content_ptr) - ft_strlen(line);
	if (new_content_len == 0)
		return (ft_free(content_ptr));
	new_content = (char *)malloc((new_content_len + 1) * sizeof(char));
	if (!new_content)
		return (ft_free(content_ptr));
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

char	*first_line(char **content_ptr)
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
	*content_ptr = another_line(content_ptr, output);
	return (output);
}

char	*ft_free(char **ptr)
{
	free (*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*gnl(int fd)
{
	static char	*content;
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!content)
		content = ft_strdup("");
	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read >= 0)
	{
		buff[bytes_read] = 0;
		content = ft_strjoin(content, buff);
		if (bytes_read == 0 && !content[0])
			break ;
		if (ft_strchr_gnl(content, '\n') > -1 || bytes_read == 0)
			return (first_line(&content));
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	return (ft_free(&content));
}
