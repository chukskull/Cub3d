/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:01:14 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/12 17:48:12 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_extension(char *filename, char *extension)
{
	int		i;
	int		j;

	i = ft_strlen(filename) - 1;
	j = ft_strlen(extension) - 1;
	while (i >= 0 && j >= 0)
	{
		if (filename[i] != extension[j])
			return (0);
		i--;
		j--;
	}
	if (j >= 0)
		return (0);
	return (1);
}

t_state	*ft_parse(int ac, char **av)
{
	t_state	*state;
	char	*file_content;

	if (ac < 2 || !ft_check_extension(av[1], ".cub"))
		return (NULL);
	file_content = ft_parse_file(av[1]);
	if (!file_content)
		return (NULL);
	printf("file read correctly, filling state\n");
	state = (t_state *) malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	ft_fill_state(file_content, state);
	free(file_content);
	return (state);
}
