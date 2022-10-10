/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dar_sefrioui <dar_sefrioui@student.1337    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:09:34 by dar_sefriou       #+#    #+#             */
/*   Updated: 2022/10/10 15:59:59 by dar_sefriou      ###   ########.fr       */
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
}	t_state;

t_state *ft_parse(int ac, char **av);
void    ft_exit_error(char *error, int status);
char	*ft_parse_file(char *filename, t_state *state);

#endif