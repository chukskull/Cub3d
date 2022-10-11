/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:40:39 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 22:04:45 by dar_sefriou      ###   ########.fr       */
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

static int	ft_invalid_map_line(char *line)
{
	int	i;

	if (has_no_ones(line))
		return (1);
	i = 0;
	while (line[i])
	{
		if (ft_invalid_char(line[i]))
			return (1);
		i++;
	}
	return (0);
}

void	ft_extract_map(char **file_content, int lines_len, t_state *state)
{
	int	i;

	(void) state;
	if (!file_content || !file_content[0] || lines_len <= 1)
		ft_exit_error("Error", EXIT_FAILURE);
	i = 0;
	while (i < lines_len)
	{
		if (ft_invalid_map_line(file_content[i]))
			ft_exit_error("Error", EXIT_FAILURE);
	}
}
