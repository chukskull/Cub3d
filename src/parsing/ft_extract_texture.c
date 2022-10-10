/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:41:56 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 18:05:17 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_extract_north(char *line, t_state *state)
{
	if (state->north_texture)
		ft_exit_error("Error - north texture already set", EXIT_FAILURE);
	state->north_texture = ft_strdup(line);
	printf("TEXTURE DETECTED - set north texture correctly\n");
}

static void	ft_extract_south(char *line, t_state *state)
{
	if (state->south_texture)
		ft_exit_error("Error - south texture already set", EXIT_FAILURE);
	state->south_texture = ft_strdup(line);
	printf("TEXTURE DETECTED - set south texture correctly\n");
}

static void	ft_extract_west(char *line, t_state *state)
{
	if (state->west_texture)
		ft_exit_error("Error - west texture already set", EXIT_FAILURE);
	state->west_texture = ft_strdup(line);
	printf("TEXTURE DETECTED - set west texture correctly\n");
}

static void	ft_extract_east(char *line, t_state *state)
{
	if (state->east_texture)
		ft_exit_error("Error - east texture already set", EXIT_FAILURE);
	state->east_texture = ft_strdup(line);
	printf("TEXTURE DETECTED - set east texture correctly\n");
}


void	ft_extract_texture(char *line, char *type, t_state *state)
{
	if (!ft_strcmp(type, "NO"))
		ft_extract_north(line, state);
	else if (!ft_strcmp(type, "SO"))
		ft_extract_south(line, state);
	else if (!ft_strcmp(type, "WE"))
		ft_extract_west(line, state);
	else if (!ft_strcmp(type, "EA"))
		ft_extract_east(line, state);
	else
		ft_exit_error("Error - invalid texture given", EXIT_FAILURE);
}