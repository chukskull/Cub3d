/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouaghi <azouaghi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 13:11:26 by azouaghi          #+#    #+#             */
/*   Updated: 2022/11/01 13:11:27 by azouaghi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	invalid_surroundings(char **map_content, int i, int j)
{
	if (map_content[i][j] != '0'
		&& !char_is_player(map_content[i][j]))
		return (0);
	if (!map_content[i][j + 1]
		|| map_content[i][j + 1] == ' ')
		return (1);
	if (
		j - 1 < 0
		|| !map_content[i][j - 1]
		|| map_content[i][j - 1] == ' ')
		return (1);
	if (!map_content[i + 1]
		|| !map_content[i + 1][j]
		|| map_content[i + 1][j] == ' ')
		return (1);
	if (
		i - 1 < 0
		|| !map_content[i - 1]
		|| !map_content[i - 1][j]
		|| map_content[i - 1][j] == ' ')
		return (1);
	return (0);
}
