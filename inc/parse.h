/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:09:34 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 17:51:43 by dar_sefriou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

# include "cub3d.h"
# include "get_next_line.h"

typedef struct s_state {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	int		floor_color;
	int		ceiling_color;

	int		map_width;
	int		map_height;
	char	**map;

	char	player_angle; // N, S, E, W
}	t_state;

t_state	*ft_parse(int ac, char **av);
void	ft_exit_error(char *error, int status);
char	*ft_parse_file(char *filename, t_state *state);
int		ft_extract_textures_colors(char **lines, int lines_count, t_state *state);
char	*ft_get_first_word(char *str);
void	ft_extract_texture(char *line, char *type, t_state *state);
void	ft_fill_state(char *filename, t_state *state);

#endif