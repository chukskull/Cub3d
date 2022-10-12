/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrahm <olabrahm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:12:48 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 15:15:09 by olabrahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_null(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	ft_free_map(int **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_free_null((void **) &map[i]);
		i++;
	}
	ft_free_null((void **) map);
	map = NULL;
}

void	ft_free_state(t_state *state)
{
	ft_free_null((void **) &state->north_texture);
	ft_free_null((void **) &state->south_texture);
	ft_free_null((void **) &state->east_texture);
	ft_free_null((void **) &state->west_texture);

	ft_free_map(state->map);
}
