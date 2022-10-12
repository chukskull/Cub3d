/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:15:38 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/11 22:18:06 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_correct_map(char **file_content, int lines_len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < lines_len)
	{
		if (ft_strlen(file_content[i]) == 0)
		{
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count);
}