/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid_surroundings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:20:48 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 19:26:03 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_char_is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	ft_invalid_surroundings(char **file_content, int line_idx, int char_idx)
{
	if (file_content[line_idx][char_idx] != '0'
		&& !ft_char_is_player(file_content[line_idx][char_idx]))
		return (0);
	if (!file_content[line_idx][char_idx + 1]
		|| file_content[line_idx][char_idx + 1] == ' ')
		return (1);
	if (!file_content[line_idx][char_idx - 1]
		|| file_content[line_idx][char_idx - 1] == ' ')
		return (1);
	if (!file_content[line_idx + 1]
		|| !file_content[line_idx + 1][char_idx]
		|| file_content[line_idx + 1][char_idx] == ' ')
		return (1);
	if (!file_content[line_idx - 1]
		|| !file_content[line_idx - 1][char_idx]
		|| file_content[line_idx - 1][char_idx] == ' ')
		return (1);
	return (0);
}
